#pragma once

class Collider {
protected:
	float *x_position;
	float *y_position;

	int *window_width;
	int *window_height;

public:
	Collider();

	void Initialize(float *x_pos, float *y_pos, int *window_width, 
		int *width_height);
	void CheckWindowBounds(void);
};