#include "NavPanel.h"

NavPanel::NavPanel(int x, int y, int w, int h) :
	Fl_Group(x, y, w, h),
	btn_width(30), padding(1)
{
	home = std::make_unique<IconButton>(x + padding , y + padding, btn_width, h - padding);
	add_db = std::make_unique<IconButton>(x + btn_width + (padding * 2), y + padding, btn_width, h - padding);
	refresh = std::make_unique<IconButton>(x + (btn_width * 2) + (padding * 3), y  + padding, btn_width, h - padding);
	home->set_icon("../image/home.png");
	add_db->set_icon("../image/addDb.png");
	refresh->set_icon("../image/refresh.png");

	this->add(home.get());
    this->add(add_db.get());
    this->add(refresh.get());


    this->end();
    box(FL_DOWN_FRAME);
}

void NavPanel::add_cb_home_btn(Fl_Callback* cb, void* v)
{
	home->callback(cb, v);
}

void NavPanel::add_cb_add_db_btn(Fl_Callback* cb, void* v)
{
	add_db->callback(cb, v);
}

void NavPanel::add_cb_refresh_btn(Fl_Callback* cb, void* v)
{
	refresh->callback(cb, v);
}
