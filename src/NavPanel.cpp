#include "NavPanel.h"

NavPanel::NavPanel(int x, int y, int w, int h) :
	Fl_Group(x, y, w, h),
	btn_width(30), padding(1),
	home(x + padding , y + padding, btn_width, h - padding),
	add_db(x + btn_width + (padding * 2), y + padding, btn_width, h - padding),
	refresh(x + (btn_width * 2) + (padding * 3), y  + 1, btn_width, h - 1)
{
	home.set_icon("../image/home.png");
	add_db.set_icon("../image/addDb.png");
	refresh.set_icon("../image/refresh.png");

	this->add(home);
    this->add(add_db);
    this->add(refresh);


    this->end();
    box(FL_DOWN_FRAME);
}