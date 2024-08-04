#ifndef STRUCTGROUP_H
#define STRUCTGROUP_H
#include <FL/Fl_Group.H>
#include "DbStructureGroup.h"
#include "TableStructureGroup.h"
#include "AtributeStructureGroup.h"
#include "EventSystem.h"
#include <string>
#include <memory>

class StructureGroup : public Fl_Group{

public:

	StructureGroup(int x ,int y ,int w , int h, std::shared_ptr<EventSystem> e_sys);
	// void show() override;

    // void show_dbs(const std::vector<std::string>& db_names);
    // void add_cb_create_db_btn(Fl_Callback* cb, void* v);
    //std::string get_input_db_name();

    void show_db_group();
    void show_table_group();
    void show_atribute_group();

private:
	std::unique_ptr<DbStructureGroup> db_struct_gr;
	std::unique_ptr<TableStructureGroup> table_struct_gr;
	std::unique_ptr<AtributeStructureGroup> atribute_struct_gr;
	//std::shared_ptr<EventSystem> event_sys;
};


#endif