#include "TableStructureGroup.h"
#include <iostream>
#include "MainWindow.h"
#include "IconLabelGroup.h"
TableStructureGroup::TableStructureGroup(int x, int y, int w, int h, std::shared_ptr<EventSystem> e_sys)
    : Fl_Group(x, y, w, h), event_sys(e_sys),
      header(0, 0, 0, 0), label_create_table(0, 0, 0, 0), label_table_name(0, 0, 0, 0),
      input_table_name(0, 0, 0, 0), label_nbr_cols(0, 0, 0, 0), input_nbr_colums(0, 0, 0, 0),
      btn_create_table(0, 0, 0, 0), line(0, 0, 0, 0)
{
   
    header.resize(x + 50, y + 10, 50, 30);
    header.label("Tables");
    header.labelfont(FL_HELVETICA_BOLD);
    header.labelsize(20);

    label_create_table.resize(x + 50, y + 55, 70, 30);
    label_create_table.label("Create Table");
    label_create_table.labelfont(FL_HELVETICA);
    label_create_table.labelsize(14);

    label_table_name.resize(x + 50, y + 90, 20, 30);
    label_table_name.label("Name");
    label_table_name.labelfont(FL_HELVETICA);
    label_table_name.labelsize(14);

    input_table_name.resize(x + 90, y + 90, 110, 30);
    input_table_name.color(FL_WHITE);

    label_nbr_cols.resize(x + 250, y + 90, 60, 30);
    label_nbr_cols.label("Number of columns");
    label_nbr_cols.labelfont(FL_HELVETICA);
    label_nbr_cols.labelsize(14);

    input_nbr_colums.resize(x + 355, y + 90, 40, 30);
    input_nbr_colums.color(FL_WHITE);

    btn_create_table.resize(x + 410, y + 90, 65, 30);
    btn_create_table.label("Create");

    line.resize(x + 10, y + 130, w - 20, 2);
    line.color(FL_BLACK);
    line.box(FL_FLAT_BOX);

    table_list = std::make_unique<DataList>(x + 10, y + 132, w - 20, 340, e_sys);
    table_list->set_header_name("Tables");
    table_list->end();

    end();

    

    event_sys->subscribe("on_show_table_list",[this](Fl_Widget* w){

		MainWindow* win = (MainWindow*) w;

		std::string selected_db = win->get_selected_db();
		
		if(!selected_db.empty())
		{
			show_tables(win->db_helper->get_table_names(selected_db));
		}
		
	});
}


void TableStructureGroup::show_tables(const std::vector<std::string> table_names)
{
	if(table_names.empty())
	{

		#ifdef DEBUG
		std::cout << "empty table_names";
		#endif
		return;
	}

	table_list->add_rows(table_names);
}