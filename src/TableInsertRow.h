#ifndef TABLEINSROW_H
#define TABLEINSROW_H

#include <memory>
#include <vector>
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Check_Button.H>
#include "EventSystem.h"
class TableInsertRow : public Fl_Group
{
public:

	TableInsertRow(int x, int y, int w, int h, std::shared_ptr<EventSystem> e_sys);

	std::string get_sql_row();

	static void on_change_type_val(Fl_Widget* w, void* v);
	static void on_change_auto_inc(Fl_Widget* w, void* v);
private:

  std::shared_ptr<EventSystem> event_sys;

  Fl_Input name;
  Fl_Choice type;
  Fl_Input length;
  Fl_Choice default_val;
  Fl_Check_Button nullable;
  Fl_Choice index;
  Fl_Check_Button auto_inc;

 

};


#endif // TABLEINSROW_H