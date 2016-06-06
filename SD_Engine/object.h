#pragma once

#include <string>

#include "renderer.h"
#include "physics.h"

using namespace std;

class Object {
protected:
	int id;

	float x_position;
	float y_position;

	float x_velocity;
	float y_velocity;

	int x_bound;
	int y_bound;

	Renderer *renderer_ptr;
	Physics *physics_ptr;

public:
	Object();

	void Initialize(int id, int x_pos, int y_pos);
	void AddRenderer(string image_path);
	void AddPhysics(void);

	int get_object_id(void);
	Physics GetPhysics(void);
	Renderer GetRenderer(void);

	void set_object_id(int id);
	// set_x
	// set_y

	/* Throaway methods */
	void PrintPosition(void);
	void IncrementXPosition(void);
};