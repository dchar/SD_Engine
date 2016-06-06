#pragma once

/* FIXME: should come from globals.h */
const int TEMP_WIDTH = 800;
const int TEMP_HEIGHT= 600;

class Collider {
protected:
	float *x_position;
	float *y_position;

public:
	Collider();

	void Initialize(float *x_pos, float *y_pos);
	void CheckWindowBounds(void);
};