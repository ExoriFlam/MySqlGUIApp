#ifndef NAVPANEL_H
#define NAVPANEL_H

#include <memory>
#include <FL/Fl_Group.H>
#include "IconButton.h"

class NavPanel : public Fl_Group{

public:
	NavPanel(int x, int y, int w, int h);
	void add_cb_home_btn(Fl_Callback* cb, void* v);
	void add_cb_add_db_btn(Fl_Callback* cb, void* v);
	void add_cb_refresh_btn(Fl_Callback* cb, void* v);
private:

	const int btn_width;
	const int padding;
	
	std::unique_ptr<IconButton> home;
	std::unique_ptr<IconButton> add_db;
	std::unique_ptr<IconButton> refresh;

};

#endif