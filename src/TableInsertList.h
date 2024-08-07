#ifndef TABLEINSLIST_H
#define TABLEINSLIST_H

#include <memory>
#include <list>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include "EventSystem.h"
#include "TableInsertRow.h"

class TableInsertList : public Fl_Group
{
public:
	TableInsertList(int x, int y, int w, int h, std::shared_ptr<EventSystem> e_sys);
	void add_rows(int count);
	void clear_rows();
	std::string get_rows_query();
private:
	int init_y;
	int cur_y;
	Fl_Box lable_name;
	Fl_Box lable_type;
	Fl_Box lable_lenght;
	Fl_Box lable_default;
	Fl_Box lable_nullable;
	Fl_Box lable_index;
	Fl_Box lbale_auto_inc;
	

	Fl_Scroll insert_rows_scroll;
	std::list<std::unique_ptr<TableInsertRow>> insert_rows_list;
	std::shared_ptr<EventSystem> event_sys;
};


#endif // TABLEINSLIST_H