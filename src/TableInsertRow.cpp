#include "TableInsertRow.h"

TableInsertRow::TableInsertRow(int x, int y, int w, int h, std::shared_ptr<EventSystem> e_sys):
	Fl_Group(x, y, w, h)
{
	
	event_sys = e_sys;
	(void)event_sys;
	end();
}