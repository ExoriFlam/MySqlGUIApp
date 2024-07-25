#include "TableStructureGroup.h"

TableStructureGroup::TableStructureGroup(int x, int y, int w, int h)
	: Fl_Group(x, y, w, h)
{

	
	

	header = std::make_unique<Fl_Box>(x + 50, y + 10, 50, 30, "Tables");
	header->labelfont(FL_HELVETICA_BOLD);
	header->labelsize(20);
	

	label_create_table = std::make_unique<Fl_Box>(x + 50, y + 55, 50, 30, "Create Table");
	label_create_table->labelfont(FL_HELVETICA);
	label_create_table->labelsize(14);
	

	label_table_name = std::make_unique<Fl_Box>(x + 50, y + 90, 50, 30, "Name");
	label_table_name->labelfont(FL_HELVETICA);
	label_table_name->labelsize(14);


	input_table_name = std::make_unique<Fl_Input>(x + 140, y + 90, 90, 30);
	input_table_name->color(FL_WHITE);


	label_nbr_cols = std::make_unique<Fl_Box>(x + 235, y + 90, 60, 30, "Number of colums");
	label_nbr_cols->labelfont(FL_HELVETICA);
	label_nbr_cols->labelsize(14);

	input_nbr_colums = std::make_unique<Fl_Int_Input>(x + 300, y + 90, 30, 30);
	input_nbr_colums->color(FL_WHITE);
	

	btn_create_table = std::make_unique<Fl_Button>(x + 50, y + 120, 60, 30, "Create ");


	// databases_header = std::make_unique<Fl_Box>(x + 10, y + 110, 200, 30, "Databases");
	// databases_header->box(FL_UP_BOX);
	// action_header = std::make_unique<Fl_Box>(x + 205, y + 110, 200, 30, "Actions");
	// action_header->box(FL_UP_BOX);

	

	// table = std::make_unique<Fl_Scroll>(x + 10, y + 145, 405, 350);
	// table->type(Fl_Scroll::VERTICAL);

	end();
} 