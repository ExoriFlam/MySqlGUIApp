#include "TableStructureGroup.h"

TableStructureGroup::TableStructureGroup(int x, int y, int w, int h)
	: Fl_Group(x, y, w, h)
{

	header = std::make_unique<Fl_Box>(x + 50, y + 10, 50, 30, "Tables");
	header->labelfont(FL_HELVETICA_BOLD);
	header->labelsize(20);
	

	label_create_table = std::make_unique<Fl_Box>(x + 50, y + 55, 70, 30, "Create Table");
	label_create_table->labelfont(FL_HELVETICA);
	label_create_table->labelsize(14);
	

	label_table_name = std::make_unique<Fl_Box>(x + 50, y + 90, 20, 30, "Name");
	label_table_name->labelfont(FL_HELVETICA);
	label_table_name->labelsize(14);


	input_table_name = std::make_unique<Fl_Input>(x + 90, y + 90, 110, 30);
	input_table_name->color(FL_WHITE);


	label_nbr_cols = std::make_unique<Fl_Box>(x + 250, y + 90, 60, 30, "Number of colums");
	label_nbr_cols->labelfont(FL_HELVETICA);
	label_nbr_cols->labelsize(14);

	input_nbr_colums = std::make_unique<Fl_Int_Input>(x + 355, y + 90, 40, 30);
	input_nbr_colums->color(FL_WHITE);
	
	
	btn_create_table = std::make_unique<Fl_Button>(x + 410, y + 90, 65, 30, "Create ");

	line = std::make_unique<Fl_Box>(x + 10, y + 130, w - 20, 2);
	line->color(FL_BLACK);
	line->box(FL_FLAT_BOX);

	table_list= std::make_unique<TableList>(x + 10 , y + 132, w -20, 340);


	

	end();
} 