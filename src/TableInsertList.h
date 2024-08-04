#ifndef TABLEINSLIST_H
#define TABLEINSLIST_H

#include <memory>
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

private:
	Fl_Box lable_name;
	Fl_Box lable_type;
	Fl_Box lable_lenght;
	Fl_Box lable_default;
	Fl_Box lable_nullable;
	Fl_Box lable_index;
	Fl_Box lbale_auto_inc;
	Fl_Button save_btn;
	Fl_Scroll insert_rows_list;
	
};


#endif // TABLEINSLIST_H