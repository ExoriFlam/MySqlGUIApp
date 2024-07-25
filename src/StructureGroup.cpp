#include "StructureGroup.h"

StructureGroup::StructureGroup(int x, int y, int w, int h):
	Fl_Group(x, y, w, h)
{
	//label_group = std::make_unique<IconLabelGroup>(x, y, w, h, "../image/home.png", "Structure");
	label("Structure");
	db_struct_gr = std::make_unique<DbStructureGroup>(x, y, w, h);
	//image(label_group.get());
	//icon = std::make_unique<Fl_PNG_Image>("../image/home.png");

	//image(icon.get()->copy(15, 15));
	//label("Structure");

	//box(FL_DOWN_BOX);


	end();
	
}

void StructureGroup::show_dbs(const std::vector<std::string>& db_names)
{
	db_struct_gr->show_dbs(db_names);
}

void StructureGroup::add_cb_create_db_btn(Fl_Callback* cb, void* v)
{
	db_struct_gr->add_cb_create_db_btn(cb, v);
}

std::string StructureGroup::get_input_db_name()
{
	return db_struct_gr->get_input_value();
}
// void StructureGroup::show()
// {
//     Fl_Group::show(); 
//     db_struct_gr->show_dbs() 
// }