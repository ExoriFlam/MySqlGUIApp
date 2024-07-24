#include "TabControl.h"

TabControl::TabControl(int x, int y, int w, int h):
	Fl_Tabs(x, y, w, h), structure_group(nullptr), sql_group(nullptr)
{
	structure_group = std::make_unique<StructureGroup>(x + 5, y + 25, w - 10, h - 35 );
	add(structure_group.get());
	sql_group = std::make_unique<SQLGroup>(x + 5, y + 25, w - 10, h - 35 );
	add(sql_group.get());
	end();
	value(structure_group.get());
	
	
}

