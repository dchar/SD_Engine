#include "object.h"


/* CONSTRUCTORS ============================================================ */
Object::Object() {
	this->id = -1;

	this->x_position = 0;
	this->y_position = 0;

	this->renderer_ptr = nullptr;
	this->physics_ptr = nullptr;
}

void Object::Initialize(int id, int x_pos, int y_pos) {
	this->id = id;

	this->x_position = x_pos;
	this->y_position = y_pos;

	this->renderer_ptr = nullptr;
	this->physics_ptr = nullptr;
}

void Object::Destroy(void) {
	
}

/* GETTER AND SETTER METHODS FOR OBJECT PARAMETERS ========================= */
int Object::get_object_id(void) {
	return this->id;
}

void Object::set_object_id(int id) {
	this->id = id;
}

/* OBJECT COMPONENTS ======================================================= */

void Object::addRenderer(string image_path) {
	ALLEGRO_BITMAP *image = al_load_bitmap(image_path.c_str());
	this->renderer_ptr= new Renderer();
	this->renderer_ptr->Initialize(image, &this->x_position, &this->y_position);
}

void Object::addPhysics(void) {
	this->physics_ptr = new Physics();
	this->physics_ptr->Initialize(&this->x_position, &this->y_position);
}

void Object::addCollider(int *window_width, int *window_height) {
	this->collider_ptr = new Collider();
	this->collider_ptr->Initialize(&this->x_position, &this->y_position,
		window_width, window_height);
}

void Object::addText(ALLEGRO_FONT *font, string *string_ptr) {
	this->text_ptr = new Text();
	this->text_ptr->Initialize(font, string_ptr, &this->x_position, &this->y_position);
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

Collider Object::getCollider(void) {
	return (*this->collider_ptr);
}

Text Object::getText(void) {
	return (*this->text_ptr);
}


/* THROWAWAY METHODS ======================================================= */
void Object::IncrementXPosition(void) {
	this->x_position++;
}

void Object::PrintPosition(void) {
	fprintf(stdout, "XPOS: %5.2f", (this->x_position));
	fprintf(stdout, "   |   ");
	fprintf(stdout, "YPOS: %5.2f\n", (this->y_position));
}