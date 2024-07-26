#ifndef TABLEROW_H
#define TABLEROW_H
#include <memory>
#include <vector>
#include <FL/Fl_Group.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Check_Button.H>
#include "IconLabelGroup.h"

class TableRow : public Fl_Group{

public:
	TableRow(int x, int y, int w, int h, const char* t_name);


private:
	
	std::unique_ptr<Fl_Check_Button> check;
	std::unique_ptr<Fl_Box> table_name;
	std::vector<IconLabelGroup*> actions;   
	
};



#endif