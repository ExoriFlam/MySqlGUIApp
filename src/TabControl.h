#ifndef TABCONTROL_H
#define TABCONTROL_H

#include <FL/Fl_Tabs.H>
#include "StructureGroup.h"
#include "SQLGroup.h"
#include <memory>

class TabControl : public Fl_Tabs{

public:

	TabControl(int x,int y,int  w,int h);

private:

	std::unique_ptr<StructureGroup> structure_group;
	//
	std::unique_ptr<SQLGroup> sql_group;

};

#endif