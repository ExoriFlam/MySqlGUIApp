#include "InsertGroup.h"

InsertGroup::InsertGroup(int x, int y, int w, int h, std::shared_ptr<EventSystem> e_sys):
	Fl_Group(x, y, w, h), table_insert_gr(nullptr)
{
	
	label("Insert");
	
	table_insert_gr = std::make_unique<TableInsertGroup>(x, y, w, h, e_sys);
	

	//box(FL_DOWN_BOX);


	end();
}

void InsertGroup::set_table_name(const std::string& t_name)
{
	table_insert_gr->set_table_name(t_name);
}
void InsertGroup::add_rows(int count)
{
	table_insert_gr->add_rows(count);
}

void InsertGroup::clear_rows()
{
	table_insert_gr->clear_rows();
}