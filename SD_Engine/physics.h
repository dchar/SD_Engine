#pragma once

#include <iostream>

class Physics {
protected:
	float *x_position;
	float *y_position;

	float *x_velocity;
	float *y_velocity;
public:
	Physics();

	void Initialize(float *x_pos, float *y_pos, float *x_velo, float *y_velo);
	

	void PhysicsIncrementYPosition(void);
	void PrintPosition(void);
};
