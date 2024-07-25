#ifndef DBSTRGROUP_H
#define DBSTRGROUP_H

#include <FL/Fl_Group.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
//#include <FL/Fl_Table.H>
//#include <FL/Fl_Check_Button.H>
//#include <FL/Fl_Pack.H>
#include <FL/Fl_Scroll.H>
#include <memory>
#include <vector>
#include <utility>
class DbStructureGroup : public Fl_Group{

public:

	DbStructureGroup(int x ,int y ,int w , int h);

	void show_dbs(const std::vector<std::string>& db_names);

	void add_cb_create_db_btn(Fl_Callback* cb, void* v);

	std::string get_input_value();
	
private:
	std::unique_ptr<Fl_Box> header;

	std::unique_ptr<Fl_Box> label_create_db;

	std::unique_ptr<Fl_Input> input_create_db;

	std::unique_ptr<Fl_Button> btn_create_db;
	
	std::unique_ptr<Fl_Box> databases_header;
	std::unique_ptr<Fl_Box> action_header;
	//std::unique_ptr<Fl_Pack> table;

	std::unique_ptr<Fl_Scroll> table;

	std::vector<std::pair<Fl_Box*, Fl_Box*>> rows;


};


#endif