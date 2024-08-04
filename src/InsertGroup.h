#ifndef INSERTGROUP_H
#define INSERTGROUP_H

#include <memory>
#include <FL/Fl_Group.H>
#include "EventSystem.h"
#include "TableInsertGroup.h"

class InsertGroup : public Fl_Group
{
public:
	InsertGroup(int x, int y, int w , int h, std::shared_ptr<EventSystem> e_sys);

	//void show_insert_table_group();
	
private:

	std::unique_ptr<TableInsertGroup> table_insert_gr;

};

#endif