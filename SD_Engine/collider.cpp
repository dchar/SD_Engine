#include "collider.h"

Collider::Collider() {
	this->x_position = nullptr;
	this->y_position = nullptr;
}

void Collider::Initialize(float *x_pos, float *y_pos) {
	this->x_position = x_pos;
	this->y_position = y_pos;
}

void Collider::CheckWindowBounds(void) {
	int cast_x_pos = static_cast<int>(*this->x_position);
	int cast_y_pos = static_cast<int>(*this->y_position);

	if (cast_y_pos < 0) {
		(*this->y_position) = 0;
	}
	if (cast_y_pos > TEMP_HEIGHT - 50) {
		(*this->y_position) = TEMP_HEIGHT - 50;
	}
}