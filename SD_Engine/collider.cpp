#include "collider.h"

Collider::Collider() {
	this->x_position = nullptr;
	this->y_position = nullptr;

	this->window_width = nullptr;
	this->window_height = nullptr;
}

void Collider::Initialize(float *x_pos, float *y_pos, int *window_width, 
	int *window_height) 
{
	this->x_position = x_pos;
	this->y_position = y_pos;

	this->window_width = window_height;
	this->window_height = window_height;
}

void Collider::CheckWindowBounds(void) {
	int cast_x_pos = static_cast<int>(*this->x_position);
	int cast_y_pos = static_cast<int>(*this->y_position);
	int height = *this->window_height;
	int width = *this->window_width;

	if (cast_y_pos < 0) {
		(*this->y_position) = 0;
	}
	if (cast_y_pos > height - 50) {
		(*this->y_position) = height - 50;
	}

}