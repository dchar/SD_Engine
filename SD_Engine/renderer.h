#pragma once

#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

class Renderer {
protected:
	ALLEGRO_BITMAP *image;
public:
	Renderer(ALLEGRO_BITMAP *);

	//void draw(void);
	/* void redraw(void) REDRAW ALLEGRO BITMAP */
};