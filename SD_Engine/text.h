#pragma once

#include <string>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include "vector_xy.h"

using namespace std;

class Text {
protected:
	ALLEGRO_FONT *font;
	string *string_msg_ptr;

	VectorXY *position_ptr;
	VectorXY offset;

	float max_width;
	float line_height;
public:
	Text();
	void Initialize(ALLEGRO_FONT *font, string *msg, VectorXY *position);

	void SetMessage(string *msg);
	void SetXOffset(float x_off);
	void SetYOffset(float y_off);
	void SetMaxWidth(float max);
	void SetLineHeight(float height);

	void Redraw(void);
};