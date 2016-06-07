#include "physics.h"

using namespace std;

Physics::Physics() {
	x_position = nullptr;
	y_position = nullptr;

	x_velocity = 0;
	y_velocity = 0;

	gravity_constant = 0.8;
}

void Physics::Initialize(float *x_pos, float *y_pos) {
	this->x_position = x_pos;
	this->y_position = y_pos;

	this->x_velocity = 0;
	this->y_velocity = 0;
	this->mass = 1.0;
}

void Physics::ApplyForce(float magnitude) {
	float force = 1 * magnitude;
	(*this->x_position) += force;
}

void Physics::Gravity(void) {
	(*this->y_position) += this->mass * 9.81 * gravity_constant;
}

void Physics::SetGravityConstant(float constant) {
	this->gravity_constant = constant;
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