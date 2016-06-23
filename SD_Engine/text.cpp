#include "text.h"

Text::Text() {
	this->font = nullptr;
	this->string_msg_ptr = nullptr;
	this->position_ptr = nullptr;
	this->offset = VectorXY(0, 0);
	this->max_width = 0;
	this->line_height = 0;
}

void Text::Initialize(ALLEGRO_FONT *font, string *msg, VectorXY *position) {
	this->font = font;
	this->string_msg_ptr = msg;
	this->position_ptr = position;
	this->offset = VectorXY(0, 0);
	this->max_width = 1000;
	this->line_height = 15;

	al_draw_multiline_text(this->font, al_map_rgb(255, 255, 255), (*this->position_ptr).x,
		(*this->position_ptr).y, this->max_width, this->line_height, 0, (*this->string_msg_ptr).c_str());
}

void Text::SetMessage(string *msg) {
	(*this->string_msg_ptr).assign(*msg);
}

void Text::SetXOffset(float off) {
	this->offset.x = off;
}

void Text::SetYOffset(float off) {
	this->offset.y = off;
}

void Text::SetMaxWidth(float max) {
	this->max_width = max;
}

void Text::SetLineHeight(float height) {
	this->line_height = height;
}

void Text::Redraw(void) {
	float x_pos = (*this->position_ptr).x + this->offset.x;
	float y_pos = (*this->position_ptr).y + this->offset.y;

	al_draw_multiline_text(this->font, al_map_rgb(255, 255, 255), x_pos,
		y_pos, this->max_width, this->line_height, 0, (*this->string_msg_ptr).c_str());
}