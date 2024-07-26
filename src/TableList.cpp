#include "TableList.h"

TableList::TableList(int x, int y, int w, int h)
	:Fl_Group(x, y, w, h)
{
	
	h_table_name = std::make_unique<Fl_Box>(x, y, w / 3, 30);
	h_table_name->label("Table");
	h_table_name->labelfont(FL_HELVETICA_BOLD);
	h_table_name->labelsize(15);
	h_table_name->box(FL_NO_BOX);

	h_table_action= std::make_unique<Fl_Box>(x + (w / 3), y, w * 2 / 3, 30);
	h_table_action->label("Action");
	h_table_action->labelfont(FL_HELVETICA_BOLD);
	h_table_action->labelsize(15);
	h_table_action->box(FL_NO_BOX);

	table =std::make_unique<Fl_Scroll>(x, y + 30, w, h);
	int y1 = y + 60;
	for(int i = 0; i < 20; i++)
	{
		TableRow* row = new TableRow(x, y1 + (i * 30), w, 30, "example_table_name_table_name");
		if(i % 2 == 0)
		{
			row->color(FL_WHITE);
		}
		
		rows.push_back(row);
		table->add(row);
	}
	
	
}