#pragma once

#include <iostream>

class Physics {
protected:
	float *x_position;
	float *y_position;

	float x_velocity;
	float y_velocity;
	float mass;

	float gravity_constant;
public:
	Physics();
	void Initialize(float *x_pos, float *y_pos);

	void ApplyForce(float magnitude);
	void Gravity(void);
	void SetGravityConstant(float constant);

	void PhysicsIncrementYPosition(void);
	void PrintPosition(void);
};
