#ifndef NAVPANEL_H
#define NAVPANEL_H

#include <memory>
#include <FL/Fl_Group.H>
#include "IconButton.h"

class NavPanel : public Fl_Group{

public:
	NavPanel(int x, int y, int w, int h);

private:

	const int btn_width;
	const int padding;
	
	IconButton home;
	IconButton add_db;
	IconButton refresh;

};

#endif