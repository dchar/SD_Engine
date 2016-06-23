#include "collider.h"

#include <stdio.h>

Collider::Collider() {
	this->position = nullptr;
	this->window_width = nullptr;
	this->window_height = nullptr;
}

void Collider::Initialize(VectorXY *position, float *window_width, float *window_height) 
{
	this->position = position;
	this->window_width = window_width;
	this->window_height = window_height;
}

void Collider::CheckWindowBounds(void) {
	if ((*this->position).x < 0) {
		(*this->position).x = 0;
	}
	else if ((*this->position).x > *this->window_width - 50) {
		(*this->position).x = *this->window_width - 50;
	}

	if ((*this->position).y < 0) {
		(*this->position).y = 0;
	}
	else if ((*this->position).y > *this->window_height - 50) {
		(*this->position).y = *this->window_height - 50;
	}
}