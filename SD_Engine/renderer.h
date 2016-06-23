#pragma once

#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

#include "vector_xy.h"

class Renderer {
protected:
	ALLEGRO_BITMAP *image;
	VectorXY *position_ptr;

	float *width;
	float *height;

public:
	Renderer();

	void Initialize(ALLEGRO_BITMAP *image, VectorXY *position, float *width, float *height);
	void Redraw(void);
};