#pragma once

#include <string>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

using namespace std;

class Text {
protected:
	float *x_position;
	float *y_position;

	string *string_msg_ptr;
	ALLEGRO_FONT *font;
public:
	Text();

	void Initialize(ALLEGRO_FONT *font, string *msg, float *x_pos, float *y_pos);
	void SetMessage(string *msg);
	void Redraw(void);
};