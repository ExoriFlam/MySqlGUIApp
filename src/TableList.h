#ifndef TABLELIST_H
#define TABLELIST_H
#include <memory>
#include <FL/Fl_Group.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Scroll.H>
#include "TableRow.h"

class TableList : public Fl_Group{

public:
	TableList(int x, int y, int w, int h);
private:
	std::unique_ptr<Fl_Box> h_table_name;
	std::unique_ptr<Fl_Box> h_table_action;
	std::vector<TableRow*> rows; 

	std::unique_ptr<Fl_Scroll> table;
};



#endif