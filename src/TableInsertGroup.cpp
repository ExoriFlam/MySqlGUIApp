#include "TableInsertGroup.h"


TableInsertGroup::TableInsertGroup(int x, int y, int w, int h, std::shared_ptr<EventSystem> e_sys)
    : Fl_Group(x, y, w, h), event_sys(e_sys), label_table_name(0,0,0,0), input_table_name(0, 0, 0, 0),
    label_add_col(0,0,0,0), input_add_col(0,0,0,0), add_col_btn(0,0,0,0), line(0, 0, 0, 0),save_btn(0, 0, 0, 0)
{
	label_table_name.resize(x + 20, y + 10, 130, 30);
	label_table_name.label("Table name:");
	label_table_name.labelfont(FL_HELVETICA_BOLD);
    label_table_name.labelsize(18);
    //label_table_name.box(FL_DOWN_BOX);
	
	input_table_name.resize(x + 155, y + 10, 125, 30);
	input_table_name.color(FL_WHITE);

	label_add_col.resize(x + 285, y + 10, 155, 30);
	label_add_col.label("Add columns:");
	label_add_col.labelfont(FL_HELVETICA_BOLD);
    label_add_col.labelsize(18);
    //label_add_col.box(FL_DOWN_BOX);

    input_add_col.resize(x + 445, y + 10, 35, 30);
    input_add_col.value(0);
	input_add_col.color(FL_WHITE);

	add_col_btn.resize(x + 485, y + 10, 65, 30);
    add_col_btn.label("Add");

 	line.resize(x + 10, y + 45, w - 20, 2);
 	line.color(FL_BLACK);
    line.box(FL_FLAT_BOX);

    ins_list = std::make_unique<TableInsertList>(x, y + 53, w, 420,e_sys);
    //ins_list->color(FL_WHITE);
    ins_list->end();
    save_btn.resize(x + 10, y + 475, 60, 30);
	save_btn.label("Save");
	
    end();
    save_btn.callback(on_click_save_btn, this);
    add_col_btn.callback(on_click_add_btn, this);
    //ins_list->box(FL_DOWN_BOX);
}

void TableInsertGroup::on_click_add_btn(Fl_Widget* w, void* v)
{
	(void)w;
	TableInsertGroup* tig = (TableInsertGroup*)v;
	tig->event_sys->trigger("on_click_add_btn", tig);
}

void TableInsertGroup::on_click_save_btn(Fl_Widget* w, void* v)
{
	(void)w;
	TableInsertGroup* tig = (TableInsertGroup*)v;
	tig->event_sys->trigger("on_click_save_btn", tig);

}

void TableInsertGroup::set_table_name(const std::string& t_name)
{
 	input_table_name.value(t_name.c_str());
}

void TableInsertGroup::add_rows(int count)
{
	ins_list->add_rows(count);

}

void TableInsertGroup::clear_rows()
{
	ins_list->clear_rows();
}
std::string TableInsertGroup::get_input_nbr_cols()
{
	return std::string(input_add_col.value());
}

std::string TableInsertGroup::get_sql_query()
{
	std::string query = "CREATE TABLE ";
	query += input_table_name.value();
	query += " (";
	std::string rows_q = ins_list->get_rows_query();
	if(rows_q == "error")
	{
		return "error";
	}
	query += rows_q;
	query += " );";

	return query;
}