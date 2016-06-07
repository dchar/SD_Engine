#include "renderer.h"

Renderer::Renderer() {
	this->image = NULL;

	this->ptr_x_position = nullptr;
	this->ptr_y_position = nullptr;
}

void Renderer::Initialize(ALLEGRO_BITMAP *image, float *object_x_pos, float *object_y_pos) {
	this->image = image;

	this->ptr_x_position = object_x_pos;
	this->ptr_y_position = object_y_pos;

	al_draw_bitmap(this->image, (*this->ptr_x_position), (*this->ptr_y_position), 0);
}


void Renderer::Redraw(void) {
	al_draw_bitmap(this->image, (*this->ptr_x_position), (*this->ptr_y_position), 0);
}
