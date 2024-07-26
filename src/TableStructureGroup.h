#ifndef TABLESTRUCTGROUP_H
#define TABLESTRUCTGROUP_H
#include <FL/Fl_Group.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Button.H>
#include "TableList.h"
#include <memory>

class TableStructureGroup : public Fl_Group{
public:
	TableStructureGroup(int x, int y, int w, int h);

private:

	std::unique_ptr<Fl_Box> header;

	std::unique_ptr<Fl_Box> label_create_table;

	std::unique_ptr<Fl_Box> label_table_name;

	std::unique_ptr<Fl_Input> input_table_name;

	std::unique_ptr<Fl_Box> label_nbr_cols;

	std::unique_ptr<Fl_Int_Input> input_nbr_colums;

	std::unique_ptr<Fl_Button> btn_create_table;
	
	std::unique_ptr<Fl_Box> line;

	std::unique_ptr<TableList> table_list;
	//std::unique_ptr<Fl_Scroll> table;

	//std::vector<std::pair<Fl_Box*, Fl_Box*>> rows;
};

#endif