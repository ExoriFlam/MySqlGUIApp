#include "DataRow.h"
#include <iostream>
DataRow::DataRow(int x, int y, int w, int h, const std::string& _name, std::shared_ptr<EventSystem> e_sys)
	:Fl_Group(x, y, w, h), check(0, 0, 0, 0), name(0, 0, 0, 0)
{
	
	event_sys = e_sys;
	check.resize(x, y, 15, 30);
	name.resize(x + 40, y, 220, 30);

	name.copy_label(_name.c_str());
	cur_x = 280;
	
	box(FL_THIN_DOWN_BOX);
	end();
	
}

void DataRow::add_action(const std::string& image_path, const std::string& label, const std::string& r_data)
{

	int width = label.length() * 10 + 20;
	actions.push_back(std::make_unique<IconLabelGroup>(this->x() + cur_x, this->y(), width, 30, image_path, label));
    actions.back()->set_row_data(r_data);
    cur_x += width;
    actions.back()->callback(on_click_row_action, this);
    this->add(actions.back().get());
}

void DataRow::on_click_row_action(Fl_Widget* widget, void* v)
{
	auto row = (DataRow*) v;
	
	row->event_sys->trigger("on_click_row_action", widget);
}


// DataRow:: ~DataRow()
// {

	
// }