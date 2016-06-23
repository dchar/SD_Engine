#include "object.h"


/* CONSTRUCTORS ============================================================ */
Object::Object() {
	this->position = VectorXY(0, 0);
	this->width = 0;
	this->height = 0;
	this->scale = 0.0f;

	this->renderer_ptr = nullptr;
	this->physics_ptr = nullptr;
}

void Object::Initialize(float x_pos, float y_pos, float width, float height) {
	this->position = VectorXY(x_pos, y_pos);
	this->width = width;
	this->height = height;
	this->scale = 1.0f;

	this->renderer_ptr = nullptr;
	this->physics_ptr = nullptr;
}

void Object::Destroy(void) {
	
}

/* GETTER AND SETTER METHODS FOR OBJECT PARAMETERS ========================= */
void Object::set_x_position(float pos) {
	this->position.x = pos;
}
void Object::set_y_position(float pos) {
	this->position.y = pos;
}

int Object::get_x_position(void) {
	return this->position.x;
}
int Object::get_y_position(void) { 
	return this->position.y;
}

/* OBJECT COMPONENTS ======================================================= */

void Object::addRenderer(string image_path) {
	ALLEGRO_BITMAP *image = al_load_bitmap(image_path.c_str());
	this->renderer_ptr= new Renderer();
	this->renderer_ptr->Initialize(image, &this->position, &this->width, &this->height);
}

void Object::addPhysics(void) {
	this->physics_ptr = new Physics();
	this->physics_ptr->Initialize(&this->position);
}

void Object::addCollider(float *window_width, float *window_height) {
	this->collider_ptr = new Collider();
	this->collider_ptr->Initialize(&this->position, window_width, window_height);
}

void Object::addText(ALLEGRO_FONT *font, string *string_ptr) {
	this->text_ptr = new Text();
	this->text_ptr->Initialize(font, string_ptr, &this->position);
}

bool Object::hasRenderer(void) {
	if (this->renderer_ptr != nullptr) {
		return true;
	}
	else return false;
}

bool Object::hasPhysics(void) {
	if (this->physics_ptr != nullptr) {
		return true;
	}
	else return false;
}

bool Object::hasCollider(void) {
	if (this->collider_ptr != nullptr) {
		return true;
	}
	else return false;
}

bool Object::hasText(void) {
	if (this->text_ptr != nullptr) {
		return true;
	}
	else return false;
}

Renderer Object::getRenderer(void) {
	return (*this->renderer_ptr);
}

Physics Object::getPhysics(void) {
	return (*this->physics_ptr);
}

Physics* Object::getPhysicsPointer(void) {
	return this->physics_ptr;
}

Collider Object::getCollider(void) {
	return (*this->collider_ptr);
}

Text Object::getText(void) {
	return (*this->text_ptr);
}

Text* Object::getTextPointer(void) {
	return this->text_ptr;
}

/* THROWAWAY METHODS ======================================================= */
void Object::PrintPosition(void) {
	fprintf(stdout, "XPOS: %5.2f", (this->position.x));
	fprintf(stdout, "   |   ");
	fprintf(stdout, "YPOS: %5.2f\n", (this->position.y));
}