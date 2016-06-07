#pragma once

#include <string>


#include "renderer.h"
#include "physics.h"
#include "collider.h"
#include "text.h"

using namespace std;

class Object {
protected:
	int id;

	float x_position;
	float y_position;

	/*
	float x_velocity;
	float y_velocity;
	*/
	int x_bound;
	int y_bound;

	Renderer *renderer_ptr;
	Physics *physics_ptr;
	Collider *collider_ptr;
	Text *text_ptr;

public:
	Object();

	void Initialize(int id, int x_pos, int y_pos);
	void Destroy(void);

	void addRenderer(string image_path);
	void addPhysics(void);
	void addCollider(int *window_width, int *window_height);
	void addText(ALLEGRO_FONT *font, string *string_ptr);

	bool hasPhysics(void);
	bool hasRenderer(void);
	bool hasCollider(void);
	bool hasText(void);

	Physics getPhysics(void);
	Renderer getRenderer(void);
	Collider getCollider(void);
	Text getText(void);

	void set_object_id(int id);
	int get_object_id(void);


	/* Throw-away methods */
	void PrintPosition(void);
	void IncrementXPosition(void);
};