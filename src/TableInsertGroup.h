#ifndef TABLEINSERTGROUP_H
#define TABLEINSERTGROUP_H

#include <memory>

#include <FL/Fl_Group.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Button.H>

#include "EventSystem.h"
#include "TableInsertList.h"

class TableInsertGroup : public Fl_Group{
public:
    TableInsertGroup(int x, int y, int w, int h, std::shared_ptr<EventSystem> e_sys);

    
private:

    std::shared_ptr<EventSystem> event_sys;
    
    Fl_Box label_table_name;
    Fl_Input input_table_name;
    Fl_Box label_add_col;
    Fl_Int_Input input_add_col;
    Fl_Button add_col_btn;
    Fl_Box line; 

   	std::unique_ptr<TableInsertList> ins_list;
};

#endif //TABLEINSERTGROUP_H