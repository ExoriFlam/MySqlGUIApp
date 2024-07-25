#include "SQLGroup.h"

SQLGroup::SQLGroup(int x, int y, int w, int h):
	Fl_Group(x, y, w, h)
{
	//label_group = std::make_unique<IconLabelGroup>(x, y, w, h, "../image/refresh.png", "SQL");
	//label(label_group.get()->label());
	//icon = std::make_unique<Fl_PNG_Image>("../image/home.png");

	//image(icon.get()->copy(15, 15));
	label("SQL");

	//box(FL_DOWN_BOX);


	end();
	
}