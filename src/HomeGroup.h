#ifndef HOMEGROUP_H
#define HOMEGROUP_H
#include <FL/Fl_Group.H>
//#include <FL/Fl_Multiline_Output.H>
#include <FL/Fl_Box.H>
#include <memory>

class HomeGroup : public Fl_Group{

public:

	HomeGroup(int x ,int y ,int w , int h);

private:

	//std::unique_ptr<Fl_Multiline_Output> text;
	std::unique_ptr<Fl_Box> text;
	
};


#endif
