#include "StructureGroup.h"

StructureGroup::StructureGroup(int x, int y, int w, int h):
	Fl_Group(x, y, w, h)
{
	//label_group = std::make_unique<IconLabelGroup>(x, y, w, h, "../image/home.png", "Structure");
	label("Structure");
	//image(label_group.get());
	//icon = std::make_unique<Fl_PNG_Image>("../image/home.png");

	//image(icon.get()->copy(15, 15));
	//label("Structure");

	box(FL_DOWN_BOX);


	end();
	
}