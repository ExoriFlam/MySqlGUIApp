#include "DataRow.h"

DataRow::DataRow(int x, int y, int w, int h, const std::string& _name, const std::string& type, std::shared_ptr<EventSystem> e_sys)
	:Fl_Group(x, y, w, h), check(0, 0, 0, 0), name(0, 0, 0, 0)
{

	row_type = type;
	event_sys = e_sys;
	check.resize(x, y, 15, 30);
	name.resize(x + 40, y, w / 3, 30); //220

	name.copy_label(_name.c_str());
	cur_x = w / 3 ;
	
	box(FL_THIN_DOWN_BOX);

	this->resizable(&check);//
	this->resizable(&name);//
	
	end();
	
}

void DataRow::add_action(const std::string& image_path, const std::string& label)
{

	//int width = label.length() * 10 + 20;
	int width = this->w() * 2 / 3 / 3;
	actions.push_back(std::make_unique<IconLabelGroup>(this->x() + cur_x, this->y(), width, 30, image_path, label));
    actions.back()->set_action_name(label);
    actions.back()->set_data_type(row_type);
    actions.back()->set_data_value(std::string(this->name.label()));
    cur_x += width;
    actions.back()->callback(on_click_row_action, this);
    this->add(actions.back().get());
    this->resizable(actions.back().get());
}

void DataRow::on_click_row_action(Fl_Widget* widget, void* v)
{
	auto row = (DataRow*) v;
	
	row->event_sys->trigger("on_click_row_action", widget);
}

