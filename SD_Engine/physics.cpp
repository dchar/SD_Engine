#include "physics.h"

using namespace std;

Physics::Physics() {
	x_position = nullptr;
	y_position = nullptr;

	x_velocity = nullptr;
	y_velocity = nullptr;
}

void Physics::Initialize(float *x_pos, float *y_pos, float *x_velo, float *y_velo) {
	this->x_position = x_pos;
	this->y_position = y_pos;

	this->x_velocity = x_velo;
	this->y_velocity = y_velo;
}



void Physics::PhysicsIncrementYPosition(void) {
	if (this->y_position != nullptr) { 
		(*this->y_position)++; 
	}
}

void Physics::PrintPosition(void) {
	fprintf(stdout, "XPOS: %5.2f", (*x_position));
	fprintf(stdout, "   |   ");
	fprintf(stdout, "YPOS: %5.2f\n", (*y_position));
}