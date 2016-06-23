#include "renderer.h"

Renderer::Renderer() {
	this->image = NULL;
	this->position_ptr = nullptr;
	this->width = nullptr;
	this->height = nullptr;
}

void Renderer::Initialize(ALLEGRO_BITMAP *image, VectorXY *position, float *width, float *height) {
	this->image = image;
	this->position_ptr = position;
	this->width = width;
	this->height = height;
}

void Renderer::Redraw(void) {
	al_draw_scaled_bitmap(this->image, 0, 0,
		100, 100, (*this->position_ptr).x, (*this->position_ptr).y, *this->width, 
		*this->height, 0);
}
