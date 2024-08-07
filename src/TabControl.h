#ifndef TABCONTROL_H
#define TABCONTROL_H

#include <FL/Fl_Tabs.H>
#include "HomeGroup.h"
#include "StructureGroup.h"
#include "SQLGroup.h"
#include "InsertGroup.h"
#include <memory>
#include "EventSystem.h"

class TabControl : public Fl_Tabs{

public:

	TabControl(int x,int y,int  w,int h, std::shared_ptr<EventSystem> e_sys);

	// int handle(int event) override;

	void show_home();
	void show_tabs();
	void show_insert();
	


	void show_structure_db();
	void show_structure_table();
	void show_structure_atribute();

	//void show_insert_table();
	void set_table_name(const std::string& t_name);
    void add_rows(int count);	
    
private:

	std::unique_ptr<StructureGroup> structure_group;
	//
	std::unique_ptr<SQLGroup> sql_group;

	std::unique_ptr<InsertGroup> insert_group;

	std::unique_ptr<HomeGroup> home_group;
	
};

#endif