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

	FILE *debugfile;
	errno_t err = fopen_s(&debugfile, "debug.out", "w+");

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
	ALLEGRO_TIMER *game_timer, *run_timer;
	ALLEGRO_BITMAP *default_bitmap = al_load_bitmap(DEFAULT_IMAGE_PATH);
	ALLEGRO_FONT *lucida_font = al_load_font(LUCIDA_SANS_ITALIC, 14, 0);
	ALLEGRO_FONT *sans_font_8 = al_load_font(OPEN_SANS, 8, 0);
	ALLEGRO_FONT *sans_font_12 = al_load_font(OPEN_SANS, 12, 0);

	float WIDTH = 800;
	float HEIGHT = 600;
	float *window_width = &WIDTH;
	float *window_height = &HEIGHT;
	float game_time = 0.0;
	float previous_time, current_time, delta_time;

	int game_FPS = 0;
	int num_frames = 0;

	list<Object> objects;
	list<Object>::iterator itr;

	/* TESTING ============================================================= */

	string status1 = "STATUS 1";
	string status2 = "STATUS 2";
	string *status_ptr1 = &status1;
	string *status_ptr2 = &status2;

	/* Initialize game Objects */
	Object test_obj, break_obj, info_label;
	test_obj.Initialize(WIDTH / 2, HEIGHT / 2, 10, 10);
	break_obj.Initialize(WIDTH / 4, HEIGHT / 4, 5, 5);
	info_label.Initialize(15, 15, 1, 1);

	/* Add Object Components */
	test_obj.addPhysics();
	test_obj.addRenderer(DEFAULT_IMAGE_PATH);
	test_obj.addCollider(window_width, window_height);
	test_obj.addText(sans_font_8, status_ptr2);

	info_label.addText(sans_font_12, status_ptr1);

	break_obj.addPhysics();
	break_obj.addRenderer(DEFAULT_IMAGE_PATH);

	/* Add Objects to game list*/
	objects.push_back(test_obj);
	objects.push_back(break_obj);
	objects.push_back(info_label);

	/* INITIALIZE TIMER AND BEGIN GAME LOOP ================================ */

	Physics *physics_tmp_ptr;
	Text *text_tmp_ptr;

	game_timer = al_create_timer(1.0 / 60);
	run_timer = al_create_timer(1.0);

	al_register_event_source(event_queue, al_get_timer_event_source(game_timer));

	al_start_timer(game_timer);
	al_start_timer(run_timer);
	game_time = al_current_time();
	previous_time = al_current_time();

	while (1) {
		ALLEGRO_EVENT ev;
		ALLEGRO_TIMEOUT timeout;
		al_init_timeout(&timeout, 0.06);
		bool get_event = al_wait_for_event_until(event_queue, &ev, &timeout);

		current_time = al_current_time();
		delta_time = current_time - previous_time;
		previous_time = current_time;

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
			case ALLEGRO_KEY_SPACE:
				keys[SPACE] = true;
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
			case ALLEGRO_KEY_SPACE:
				keys[SPACE] = false;
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

			string update_str =  "SD_ENGINE v1.0  |  FPS: " + to_string(game_FPS) + "  |  "
						+ "TIME: " + to_string(al_get_timer_count(run_timer)) + "s" + "  |  "
						+ "DEBUG: ";

			text_tmp_ptr = info_label.getTextPointer();
			(*text_tmp_ptr).SetMessage(&update_str);

		}

		/* INPUT-BASED UPDATES =================================================== */
		if (keys[RIGHT])
			test_obj.getPhysics().MoveLaterally(5);
		if (keys[LEFT])
			test_obj.getPhysics().MoveLaterally(-5);
		if (keys[SPACE])
			(*test_obj.getPhysicsPointer()).AddLateralForce();
		else
			(*test_obj.getPhysicsPointer()).ZeroLateralForce();
			//test_obj.set_y_position(50);

		/* OBJECT UPDATES ======================================================== */
		for (itr = objects.begin(); itr != objects.end(); itr++) {
			if ((*itr).hasPhysics()) {
				physics_tmp_ptr = (*itr).getPhysicsPointer();
				(*physics_tmp_ptr).SetDeltaTime(delta_time);
				(*physics_tmp_ptr).ApplyLateralForces();
				(*physics_tmp_ptr).Gravity();
				(*physics_tmp_ptr).LogVariables(debugfile);

				string test_obj_str = "X: " + to_string(test_obj.get_x_position()) + "   Y: " + to_string(test_obj.get_y_position());
				test_obj_str += "\nFX: " + to_string((*physics_tmp_ptr).get_x_force()) + "   FY: " + to_string((*physics_tmp_ptr).get_y_force());
				test_obj_str += "\nVX: " + to_string((*physics_tmp_ptr).get_x_velocity()) + "\nVY: " + to_string((*physics_tmp_ptr).get_y_velocity());

				text_tmp_ptr = test_obj.getTextPointer();
				(*text_tmp_ptr).SetXOffset(50);
				(*text_tmp_ptr).SetLineHeight(10);
				(*text_tmp_ptr).SetMessage(&test_obj_str);

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