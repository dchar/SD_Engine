#pragma once

#include <string>
#include <vector>

#include "renderer.h"
#include "physics.h"
#include "collider.h"
#include "text.h"
#include "vector_xy.h"

using namespace std;

class Object {
protected:
	VectorXY position;
	VectorXY min_bound;
	VectorXY max_bound;

	float width;
	float height;
	float scale;

	Renderer *renderer_ptr;
	Physics *physics_ptr;
	Collider *collider_ptr;
	Text *text_ptr;

public:
	Object();

	void Initialize(float x_pos, float y_pos, float width, float height);
	void Destroy(void);

	void addRenderer(string image_path);
	void addPhysics(void);
	void addCollider(float *window_width, float *window_height);
	void addText(ALLEGRO_FONT *font, string *string_ptr);

	bool hasPhysics(void);
	bool hasRenderer(void);
	bool hasCollider(void);
	bool hasText(void);

	Physics getPhysics(void);
	Physics* getPhysicsPointer(void);

	Renderer getRenderer(void);
	// Renderer*

	Collider getCollider(void);
	// Collider*

	Text getText(void);
	Text* getTextPointer(void);

	void set_x_position(float pos);
	void set_y_position(float pos);

	int get_x_position(void);
	int get_y_position(void);

	/* Throw-away methods */
	void PrintPosition(void);
};