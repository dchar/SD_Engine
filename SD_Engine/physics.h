#pragma once

#include <iostream>
#include <cmath>
#include "vector_xy.h"

class Physics {
protected:
	VectorXY *position_ptr;
	VectorXY force;
	VectorXY velocity;
	VectorXY acceleration;

	float gravity_constant;
	float delta_time;
	float mass;

	bool in_flight;

public:
	Physics();
	void Initialize(VectorXY *position);

	void ApplyLateralForces(void);
	void AddLateralForce(void);
	void ZeroLateralForce(void);
	void Gravity(void);

	void SetDeltaTime(float dt);
	void SetMass(float mass);

	float get_x_force(void);
	float get_y_force(void);

	float get_x_velocity(void);
	float get_y_velocity(void);
	
	float get_x_acceleration(void);
	float get_y_acceleration(void);

	void MoveLaterally(float magnitude);
	void PrintPosition(void);
	void LogVariables(FILE *f);
};
