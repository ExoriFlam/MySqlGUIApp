#include "DataList.h"
#include <iostream>
DataList::DataList(int x, int y, int w, int h, std::shared_ptr<EventSystem> e_sys)
	:Fl_Group(x, y, w, h), data_scroll(0,0,0,0) ,h_name(0,0,0,0), h_action(0,0,0,0), event_sys(e_sys)
{
	data_scroll.end();
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
	data_scroll.type(Fl_Scroll::BOTH);
	
	
	this->end();
	
}

void DataList::set_header_name(const std::string& new_name)
{
	h_name.copy_label(new_name.c_str());
}

void DataList::add_rows(const std::vector<std::string>& labels)
{
	if (labels.size() == 0) return;

	int y = this->y() + 30;
	int x = this->x();
	int w = this->w();

	for(int i = 0; i < labels.size(); i++)
	{
		//DataRow* row = new DataRow(x, y + (i * 30), w, 30, labels[i], event_sys);
		rows.push_back(std::make_unique<DataRow>(x, y + (i * 30), w, 30, labels[i], event_sys));
		rows.back()->add_action("../image/structure.png","Structure",labels[i]);
		rows.back()->add_action("../image/insert.png","Insert",labels[i]);
		rows.back()->add_action("../image/drop.png","Drop",labels[i]);

		if(i % 2 == 0)
		{
			rows.back()->color(FL_WHITE);
		}
		
		//rows.push_back(row);
		data_scroll.add(rows.back().get());
	}
}


DataList:: ~DataList()
{
	
	  std::cout << "Number of children: " << data_scroll.children() << std::endl;
	// for(DataRow* row : this->rows)
	// {
	// 	delete row;
	// }
	
}