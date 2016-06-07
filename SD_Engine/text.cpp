#include "text.h"



Text::Text() {
	this->x_position = nullptr;
	this->y_position = nullptr;

	this->string_msg_ptr = nullptr;
	this->font = NULL;
}

void Text::Initialize(ALLEGRO_FONT *font, string *msg, float *x_pos, float *y_pos) {
	this->x_position = x_pos;
	this->y_position = y_pos;

	this->string_msg_ptr = msg;
	this->font = font;

	al_draw_text(this->font, al_map_rgb(255, 255, 255), (*this->x_position),
		(*this->y_position), 0, (*this->string_msg_ptr).c_str());
}

void Text::SetMessage(string *msg) {
	(*this->string_msg_ptr).assign(*msg);
}

void Text::Redraw(void) {
	al_draw_text(this->font, al_map_rgb(255, 255, 255), (*this->x_position),
		(*this->y_position), 0, (*this->string_msg_ptr).c_str());
}