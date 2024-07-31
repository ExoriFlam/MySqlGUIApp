#include "DataList.h"

DataList::DataList(int x, int y, int w, int h, std::shared_ptr<EventSystem> e_sys)
	:Fl_Group(x, y, w, h), h_name(0,0,0,0), h_action(0,0,0,0), data_scroll(0,0,0,0)
{
	
	h_name.resize(x, y, w / 3, 30);
	
	h_name.labelfont(FL_HELVETICA_BOLD);
	h_name.labelsize(15);
	h_name.box(FL_NO_BOX);

	h_action.resize(x + (w / 3), y, w * 2 / 3, 30);
	h_action.label("Action");
	h_action.labelfont(FL_HELVETICA_BOLD);
	h_action.labelsize(15);
	h_action.box(FL_NO_BOX);

	data_scroll.resize(x, y + 30, w, h);
	
	int y1 = y + 30;

	for(int i = 0; i < 10; i++)
	{
		DataRow* row = new DataRow(x, y1 + (i * 30), w, 30,"example_table_name_table_name", e_sys);
		
		row->add_action("../image/structure.png","Structure");
		row->add_action("../image/insert.png","Insert");
		row->add_action("../image/drop.png","Drop");

		if(i % 2 == 0)
		{
			row->color(FL_WHITE);
		}
		
		rows.push_back(row);
		data_scroll.add(rows.back());
	}
	data_scroll.end();
	
}

void DataList::set_header_name(const std::string& new_name)
{
	h_name.copy_label(new_name.c_str());
}

DataList:: ~DataList()
{
	for(DataRow* row : this->rows)
	{
		delete row;
	}
}