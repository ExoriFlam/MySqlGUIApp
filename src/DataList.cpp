#include "DataList.h"

DataList::DataList(int x, int y, int w, int h, std::shared_ptr<EventSystem> e_sys)
	:Fl_Group(x, y, w, h), h_name(0,0,0,0), h_action(0,0,0,0), event_sys(e_sys), data_scroll(0,0,0,0)
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

	this->resizable(&h_name);//
	this->resizable(&h_action);//
	this->resizable(&h_action);//
	this->resizable(&data_scroll);//
	
	
	this->end();
	
}

void DataList::set_header_name(const std::string& new_name)
{
	h_name.copy_label(new_name.c_str());
	type = new_name;
}

void DataList::add_rows(const std::vector<std::string>& labels)
{
	if (labels.empty())
	{
		rows.clear();
		data_scroll.clear();
		return;
	} 

	int y = this->y() + 30;
	int x = this->x();
	int w = this->w();

	rows.clear();
	data_scroll.clear();
    

	for(size_t i = 0; i < labels.size(); i++)
	{
		
		rows.push_back(std::make_unique<DataRow>(x, y + (i * 30), w, 30, labels[i], type, event_sys));


		rows.back()->add_action("../image/structure.png","Structure");
		
		if(type == "Tables")
		{
			rows.back()->add_action("../image/insert.png","Insert");
		}
		
		rows.back()->add_action("../image/drop.png","Drop");

		if(i % 2 == 0)
		{
			rows.back()->color(FL_WHITE);
		}
		
		
		data_scroll.add(rows.back().get());
	}

	data_scroll.redraw();
}

