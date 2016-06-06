#include "object.h"

/* CONSTRUCTORS ============================================================ */
Object::Object() {
	this->id = -1;

	this->x_position = 0;
	this->y_position = 0;

	this->x_velocity = 0;
	this->y_velocity = 0;

	this->renderer_ptr = nullptr;
	this->physics_ptr= nullptr;
}

void Object::Initialize(int id, int x_pos, int y_pos) {
	this->id = id;

	this->x_position = x_pos;
	this->y_position = y_pos;

	this->renderer_ptr = nullptr;
	this->physics_ptr = nullptr;
}

/* GETTER AND SETTER METHODS FOR OBJECT PARAMETERS ========================= */
int Object::get_object_id(void) {
	return this->id;
}

void Object::set_object_id(int id) {
	this->id = id;
}

/* OBJECT COMPONENTS ======================================================= */
void Object::AddRenderer(string image_path) {
	ALLEGRO_BITMAP *image = al_load_bitmap(image_path.c_str());
	this->renderer_ptr= new Renderer(image);
}

Renderer Object::GetRenderer(void) {
	return (*this->renderer_ptr);
}

void Object::AddPhysics(void) {
	this->physics_ptr = new Physics();
	this->physics_ptr->Initialize(&this->x_position, &this->y_position,
		&this->x_velocity, &this->y_velocity);
}

Physics Object::GetPhysics(void) {
	return (*this->physics_ptr);
}

void Object::IncrementXPosition(void) {
	this->x_position++;
}

void Object::PrintPosition(void) {
	fprintf(stdout, "XPOS: %5.2f", (this->x_position));
	fprintf(stdout, "   |   ");
	fprintf(stdout, "YPOS: %5.2f\n", (this->y_position));
}