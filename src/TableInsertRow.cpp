#include "TableInsertRow.h"

TableInsertRow::TableInsertRow(int x, int y, int w, int h, std::shared_ptr<EventSystem> e_sys):
	Fl_Group(x, y, w, h), name(0, 0, 0, 0), type(0, 0, 0, 0), length(0, 0, 0, 0), default_val(0, 0, 0, 0),
	nullable(0, 0, 0, 0), index(0, 0, 0, 0), auto_inc(0, 0, 0, 0)
{
	
	event_sys = e_sys;

	name.resize(x + 10 , y + 10, 100, 30);
	//name.color(FL_WHITE);
	
    type.resize(x + 110, y + 10, 75, 30);
    
	
	
	type.add("INT");
	type.add("TINYINT");
	type.add("BOOLEAN");
	type.add("BIGINT");
	type.add("FLOAT");
	type.add("DOUBLE");

	type.add("CHAR");
	type.add("VARCHAR");
	type.add("TEXT");
	type.add("BINARY");

	type.add("DATE");
	type.add("TIME");
	type.add("DATETIME");
	type.add("TIMESTAMP");
	type.add("YEAR");
	

    length.resize(x + 185, y + 10, 120, 30);
	//length.color(FL_WHITE);

    default_val.resize(x + 305 , y + 10, 80, 30);
    default_val.add("NULL");
    default_val.add("CURRENT_TIMESTAMP");
	//default_val.color(FL_WHITE);

    nullable.resize(x + 395, y + 10, 25, 30);
	

    index.resize(x + 425, y + 10, 80, 30);
    index.add("...");
    index.add("PRIMARY");
    index.add("UNIQUE");

    auto_inc.resize(x + 525, y + 10, 25, 30);

	

	this->box(FL_THIN_DOWN_BOX);
	

	end();
}