#ifndef TABCONTROL_H
#define TABCONTROL_H

#include <FL/Fl_Tabs.H>
#include "HomeGroup.h"
#include "StructureGroup.h"
#include "SQLGroup.h"
#include <memory>

class TabControl : public Fl_Tabs{

public:

	TabControl(int x,int y,int  w,int h);

	// int handle(int event) override;

	void show_home();
	void show_tabs();

	void show_db_names(const std::vector<std::string>& db_names);

	void add_cb_create_db_btn(Fl_Callback* cb, void* v);
	std::string get_input_db_name();

	void show_structure_db();
	void show_structure_table();
	void show_structure_atribute();

private:

	std::unique_ptr<StructureGroup> structure_group;
	//
	std::unique_ptr<SQLGroup> sql_group;

	std::unique_ptr<HomeGroup> home_group;
	
};

#endif