#include "StructureGroup.h"

StructureGroup::StructureGroup(int x, int y, int w, int h, std::shared_ptr<EventSystem> e_sys):
	Fl_Group(x, y, w, h)
{
	label("Structure");

	db_struct_gr = std::make_unique<DbStructureGroup>(x, y, w, h, e_sys);
	table_struct_gr = std::make_unique<TableStructureGroup>(x, y, w, h);
	atribute_struct_gr = std::make_unique<AtributeStructureGroup>(x, y, w, h);

	db_struct_gr->hide();
	table_struct_gr->hide();
	atribute_struct_gr->hide();

	end();
	
}


void StructureGroup::show_db_group()
{

	table_struct_gr->hide();
	atribute_struct_gr->hide();
	db_struct_gr->show();
	
}

void StructureGroup::show_table_group()
{
	atribute_struct_gr->hide();
	db_struct_gr->hide();
	table_struct_gr->show();
}

void StructureGroup::show_atribute_group()
{
	db_struct_gr->hide();
	table_struct_gr->hide();
	atribute_struct_gr->show();
}


void StructureGroup::show_dbs(const std::vector<std::string>& db_names)
{
	db_struct_gr->show_dbs(db_names);
}

// void StructureGroup::add_cb_create_db_btn(Fl_Callback* cb, void* v)
// {
// 	db_struct_gr->add_cb_create_db_btn(cb, v);
// }

std::string StructureGroup::get_input_db_name()
{
	return db_struct_gr->get_input_value();
}
// void StructureGroup::show()
// {
//     Fl_Group::show(); 
//     db_struct_gr->show_dbs() 
// }