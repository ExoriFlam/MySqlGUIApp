#ifndef STRUCTGROUP_H
#define STRUCTGROUP_H
#include <FL/Fl_Group.H>
//#include "IconLabelGroup.h"
#include <memory>

class StructureGroup : public Fl_Group{

public:

	StructureGroup(int x ,int y ,int w , int h);

private:

	//std::unique_ptr<IconLabelGroup> label_group;
};


#endif