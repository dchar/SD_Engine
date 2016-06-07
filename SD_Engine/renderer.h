#pragma once

#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>


class Renderer {
protected:
	ALLEGRO_BITMAP *image;

	float *ptr_x_position;
	float *ptr_y_position;

public:
	Renderer();

	void Initialize(ALLEGRO_BITMAP *image, float *x_pos, float *y_pos);
	void Redraw(void);

};