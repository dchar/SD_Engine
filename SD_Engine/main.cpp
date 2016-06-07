#include <iostream>

#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <list>

#include "globals.h"
#include "object.h"

using namespace std;

int main(void)
{
	/* INITIALIZE ALLEGRO OBJECTS AND ADDONS =============================== */

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;

	if (!al_init()) { 
		fprintf(stderr, "Failed to initialize allegro\n");
		return -1;
	}

	display = al_create_display(WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!display) {
		fprintf(stderr, "Failed to create allgero display\n");
		return -1;
	}

	event_queue = al_create_event_queue();
	if (!event_queue) {
		fprintf(stderr, "Failed to create allegro event queue\n");
		al_destroy_display(display);
		return -1;
	}

	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_keyboard();

	/* REGISTER EVENT SOURCES ============================================== */

	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();

	/* GAME GLOBALS ======================================================== */
	ALLEGRO_TIMER *game_timer;
	ALLEGRO_BITMAP *default_bitmap = al_load_bitmap(DEFAULT_IMAGE_PATH);
	ALLEGRO_FONT *lucida_font = al_load_font(LUCIDA_SANS_ITALIC, 14, 0);
	ALLEGRO_FONT *open_sans_font = al_load_font(OPEN_SANS, 12, 0);

	int WIDTH = 800;
	int HEIGHT = 600;
	int *window_width, *window_height;
	window_width = &WIDTH;
	window_height = &HEIGHT;

	list<Object> objects;
	list<Object>::iterator itr;
	float game_time = 0.0;
	int game_FPS = 0;
	int num_frames = 0;

	

	/* TESTING ============================================================= */

	Object test_obj, break_obj, text_obj;
	string *status_ptr;
	string status = "-- TEST STRING --";
	status_ptr = &status;

	/* Initialize game Objects */
	test_obj.Initialize(1, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	break_obj.Initialize(1, WINDOW_WIDTH / 4, WINDOW_HEIGHT / 4);
	text_obj.Initialize(1, 15, 15);

	/* Add Object Components */
	test_obj.addPhysics();
	test_obj.addRenderer(DEFAULT_IMAGE_PATH);
	test_obj.addCollider(window_width, window_height);
	text_obj.addText(open_sans_font, status_ptr);

	/* Add Objects to game list*/
	objects.push_back(test_obj);
	objects.push_back(break_obj);
	objects.push_back(text_obj);
	
	ALLEGRO_TIMER *run_time = al_create_timer(1.0);
	al_start_timer(run_time);
	string update_str = "MAIN TEST UPDATE";


	/* INITIALIZE TIMER AND BEGIN GAME LOOP ================================ */

	game_timer = al_create_timer(1.0 / 60);
	al_register_event_source(event_queue, al_get_timer_event_source(game_timer));

	al_start_timer(game_timer);
	game_time = al_current_time();

	while (1) {
		ALLEGRO_EVENT ev;
		ALLEGRO_TIMEOUT timeout;
		al_init_timeout(&timeout, 0.06);

		bool get_event = al_wait_for_event_until(event_queue, &ev, &timeout);

		/* KEY HANDLING ==================================================== */
		if (get_event && ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch(ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				keys[UP] = true;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = true;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = true;
				break;
			}
		}
		else if (get_event && ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				keys[UP] = false;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = false;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = false;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = false;
				break;
			}
		}
		else if (get_event && ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}

		/* TIMER UPDATES  ======================================================== */
		else if (get_event && ev.type == ALLEGRO_EVENT_TIMER) {
			num_frames++;
			if (al_current_time() - game_time >= 1) {
				game_time = al_current_time();
				game_FPS = num_frames;
				num_frames = 0;
			}

			update_str =  "SD_ENGINE v1.0  |  FPS: " + to_string(game_FPS) + "  |  "
						+ "TIME: " + to_string(al_get_timer_count(run_time)) + "s" + "  |  "
						+ "DEBUG: ";
			text_obj.getText().SetMessage(&update_str);
		}

		/* INPUT-BASED UPDATES =================================================== */
		if (keys[RIGHT])
			test_obj.getPhysics().ApplyForce(5);

		/* OBJECT UPDATES ======================================================== */
		for (itr = objects.begin(); itr != objects.end(); itr++) {
			if ((*itr).hasPhysics()) {
				(*itr).getPhysics().Gravity();
			}
			if ((*itr).hasCollider()) {
				(*itr).getCollider().CheckWindowBounds();
			}
			if ((*itr).hasRenderer()) {
				(*itr).getRenderer().Redraw();
			}
			if ((*itr).hasText()) {
				(*itr).getText().Redraw();
			}
		}
		
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	/* DESTROY ALLEGRO OBJECTS ============================================= */

	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}