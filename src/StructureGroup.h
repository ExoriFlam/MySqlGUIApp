#ifndef STRUCTGROUP_H
#define STRUCTGROUP_H
#include <FL/Fl_Group.H>
#include "DbStructureGroup.h"
#include <string>
#include <memory>

class StructureGroup : public Fl_Group{

public:

	StructureGroup(int x ,int y ,int w , int h);
	// void show() override;

    void show_dbs(const std::vector<std::string>& db_names);
    void add_cb_create_db_btn(Fl_Callback* cb, void* v);
    std::string get_input_db_name();
private:
	std::unique_ptr<DbStructureGroup> db_struct_gr;
	
};


#endif