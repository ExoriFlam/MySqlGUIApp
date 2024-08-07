#ifndef TABLESTRUCTGROUP_H
#define TABLESTRUCTGROUP_H
#include <FL/Fl_Group.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Button.H>
#include <memory>
#include "EventSystem.h"
#include "DataList.h"
#include "DataRow.h"
class TableStructureGroup : public Fl_Group{
public:
	TableStructureGroup(int x, int y, int w, int h, std::shared_ptr<EventSystem> e_sys);

	void show_tables(const std::vector<std::string>& table_names);

	std::string get_input_table_name();
	std::string get_input_nbr_cols();
	
	static void on_click_create_table(Fl_Widget* w, void* v);
private:

	std::shared_ptr<EventSystem> event_sys;

	Fl_Box header;

	Fl_Box vert_line;
	
	Fl_Box selected_db;

	Fl_Box label_create_table;

	Fl_Box label_table_name;

	Fl_Input input_table_name;

	Fl_Box label_nbr_cols;

	Fl_Int_Input input_nbr_colums;

	Fl_Button btn_create_table;
	
	Fl_Box line;

	std::unique_ptr<DataList> table_list;
	
};

#endif