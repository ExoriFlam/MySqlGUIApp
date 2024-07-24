#ifndef SQLGROUP_H
#define SQLGROUP_H
#include <FL/Fl_Group.H>
#include "IconLabelGroup.h"
#include <memory>

class SQLGroup : public Fl_Group{

public:

	SQLGroup(int x ,int y ,int w , int h);

private:

	std::unique_ptr<IconLabelGroup> label_group;
	
};


#endif