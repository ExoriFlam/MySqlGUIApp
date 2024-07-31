#ifndef DATAROW_H
#define DATAROW_H
#include <memory>
#include <vector>
#include <list>
#include <string>
#include <FL/Fl_Group.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Check_Button.H>
#include "IconLabelGroup.h"
#include "EventSystem.h"

class DataRow : public Fl_Group{

public:
	DataRow(int x, int y, int w, int h, const std::string& _name, std::shared_ptr<EventSystem> e_sys);
    ~DataRow();
    void add_action(const std::string& image_path, const std::string& label);
    static void on_click_row_action(Fl_Widget* widget, void* v);




private:
	int cur_x;
	std::shared_ptr<EventSystem> event_sys;
	Fl_Check_Button check;
	Fl_Box name;
	//std::list<std::shared_ptr<IconLabelGroup>> actions;   
	std::list<IconLabelGroup*> actions;   
	
};



#endif