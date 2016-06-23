#include "physics.h"

using namespace std;

Physics::Physics() {
	this->position_ptr = nullptr;
	this->force = VectorXY(0, 0);
	this->velocity = VectorXY(0, 0);
	this->acceleration = VectorXY(0, 0);

	this->gravity_constant = float(9.81);
	this->delta_time = 0.1f;
	this->mass = 1.0;
}

void Physics::Initialize(VectorXY *position) {
	this->position_ptr = position;
	this->force = VectorXY(0, 0);
	this->velocity = VectorXY(0, 0);
	this->acceleration = VectorXY(0, 0);

	this->gravity_constant = float(9.81);
	this->mass = 1.0;
	this->delta_time = 0.1f;
}

void Physics::ApplyLateralForces(void) {
	this->acceleration.x = this->force.x / this->mass;

	(*this->position_ptr).x += this->velocity.x * this->delta_time + (0.5f * pow(this->delta_time, 2) * this->acceleration.x);

	float temp_acceleration = this->force.x / this->mass;
	float avg_acceleration = (acceleration.x + temp_acceleration) / 2.0f;
	this->velocity.x += avg_acceleration * this->delta_time;
}

void Physics::AddLateralForce(void) {
	this->force.x = 10;
}

void Physics::ZeroLateralForce(void) {
	this->force.x = 0;
}

void Physics::Gravity(void) {
	float new_y_acceleration, avg_acceleration;
	this->acceleration.y = this->gravity_constant;

	this->force.y = this->mass * this->gravity_constant;
	/* Air Resistance */

	if (delta_time > 0) {
		float delta_position = (this->delta_time * this->velocity.y) + (0.5f * pow(this->delta_time, 2) * this->acceleration.y);
		(*this->position_ptr).y += delta_position;
		
		new_y_acceleration = this->force.y / this->mass;
		avg_acceleration = (new_y_acceleration + this->acceleration.y) * 0.5f;

		float delta_velocity = avg_acceleration * this->delta_time;
		this->velocity.y += delta_velocity;
	}
}

void Physics::SetDeltaTime(float dt) {
	this->delta_time = dt;
}

void Physics::SetMass(float mass) {
	this->mass = mass;
}

float Physics::get_x_force(void) {
	return this->force.x;
}

float Physics::get_y_force(void) {
	return this->force.y;
}

float Physics::get_x_velocity(void) {
	return this->velocity.x;
}

float Physics::get_y_velocity(void) {
	return this->velocity.y;
}

float Physics::get_x_acceleration(void) {
	return this->acceleration.x;
}

float Physics::get_y_acceleration(void) {
	return this->acceleration.y;
}

void Physics::MoveLaterally(float magnitude) {
	float force = 1 * magnitude;
	((*this->position_ptr).x) += force;
}




void Physics::PrintPosition(void) {
	fprintf(stdout, "XPOS: %5.2f", (*position_ptr).x);
	fprintf(stdout, "   |   ");
	fprintf(stdout, "YPOS: %5.2f\n", (*position_ptr).y);
}

void Physics::LogVariables(FILE *f) {
	fprintf(f, "--- PHYSICS ---\n");
	fprintf(f, "X_VELO:    %f\t\t", this->velocity.x);
	fprintf(f, "Y_VELO:    %f\n", this->velocity.y);
	fprintf(f, "DT VAL:    %f\n", this->delta_time);
	fprintf(f, "MASS  :    %f\n", this->mass);
}