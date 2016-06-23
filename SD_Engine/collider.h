#pragma once

#include "vector_xy.h"

class Collider {
protected:
	VectorXY *position;

	float *window_width;
	float *window_height;

public:
	Collider();

	void Initialize(VectorXY *position, float *window_width, float *width_height);
	void CheckWindowBounds(void);
};