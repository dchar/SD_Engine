#include <iostream>

#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_font.h>
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

	// comment
	al_init_image_addon();
	al_init_font_addon();
	al_install_keyboard();

	/* REGISTER EVENT SOURCES ============================================== */

	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();

	/* GAME GLOBALS ======================================================== */
	list<Object> objects;
	list<Object>::iterator itr;

	ALLEGRO_BITMAP *default_bitmap = al_load_bitmap(DEFAULT_IMAGE_PATH);

	/* TESTING ============================================================= */

	/* Object and component testing */
	Object test_obj;
	Physics physics_ptr;

	test_obj.Initialize(1, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	test_obj.AddPhysics();
	physics_ptr = test_obj.GetPhysics();

	objects.push_back(test_obj);
	

	/* GAME LOOP =========================================================== */
	while (1) {
		ALLEGRO_EVENT ev;
		ALLEGRO_TIMEOUT timeout;
		al_init_timeout(&timeout, 0.06);

		bool get_event = al_wait_for_event_until(event_queue, &ev, &timeout);

		/* KEY HANDLING ==================================================== */
		if (get_event && ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch(ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				physics_ptr.PrintPosition();
				break;
			case ALLEGRO_KEY_DOWN:
				test_obj.PrintPosition();
				break;
			case ALLEGRO_KEY_RIGHT:
				physics_ptr.PhysicsIncrementYPosition();
				break;
			case ALLEGRO_KEY_LEFT:
				break;
			}
		}
		else if (get_event && ev.type == ALLEGRO_EVENT_KEY_UP) {
			
		}
		else if (get_event && ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}


		/* PHYSICS UPDATES ================================================= */
		test_obj.IncrementXPosition();

		for (itr = objects.begin(); itr != objects.end(); itr++) {
			(*itr).GetPhysics().PrintPosition();
		}

		/* RENDERING ======================================================= */


		/* RESET DISPLAY */
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	/* DESTROY ALLEGRO OBJECTS ============================================= */

	al_destroy_display(display);
	al_destroy_event_queue(event_queue);


	return 0;
}