#ifndef DATALIST_H
#define DATALIST_H
#include <memory>
#include <FL/Fl_Group.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Scroll.H>
#include "DataRow.h"
#include "EventSystem.h"
#include <list>
class DataList : public Fl_Group{

public:
	DataList(int x, int y, int w, int h, std::shared_ptr<EventSystem> e_sys);
	void set_header_name(const std::string& new_name);

	~DataList();
private:

	Fl_Box h_name;
	Fl_Box h_action;
	std::list<DataRow*> rows; 

	Fl_Scroll data_scroll;
};



#endif