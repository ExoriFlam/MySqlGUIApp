#include "TableInsertList.h"
#include <iostream>
TableInsertList::TableInsertList(int x, int y, int w, int h, std::shared_ptr<EventSystem> e_sys):
	Fl_Group(x, y, w, h), lable_name(0, 0, 0, 0), lable_type(0, 0, 0, 0), lable_lenght(0, 0, 0, 0),
	lable_default(0, 0, 0, 0), lable_nullable(0, 0, 0, 0), lable_index(0, 0, 0, 0),
	lbale_auto_inc(0, 0, 0, 0), save_btn(0, 0, 0, 0), insert_rows_scroll(0, 0, 0, 0) 
{
	event_sys = e_sys;
	insert_rows_scroll.end();

	lable_name.resize(x + 5, y, 100, 30);
	lable_name.label("Name");
	lable_name.labelfont(FL_HELVETICA_BOLD);
	lable_name.labelsize(18);
    //lable_name.box(FL_DOWN_BOX);

    lable_type.resize(x + 105, y, 75, 30);
	lable_type.label("Type");
	lable_type.labelfont(FL_HELVETICA_BOLD);
	lable_type.labelsize(18);
    //lable_type.box(FL_DOWN_BOX);

    lable_lenght.resize(x + 180, y, 120, 30);
	lable_lenght.label("Val/Length");
	lable_lenght.labelfont(FL_HELVETICA_BOLD);
	lable_lenght.labelsize(18);
    //lable_lenght.box(FL_DOWN_BOX);

    lable_default.resize(x + 300, y, 80, 30);
	lable_default.label("Default");
	lable_default.labelfont(FL_HELVETICA_BOLD);
	lable_default.labelsize(18);
    //lable_default.box(FL_DOWN_BOX);


    lable_nullable.resize(x + 380, y, 50, 30);
	lable_nullable.label("Null");
	lable_nullable.labelfont(FL_HELVETICA_BOLD);
	lable_nullable.labelsize(18);
    //lable_nullable.box(FL_DOWN_BOX);

    lable_index.resize(x + 430, y, 80, 30);
	lable_index.label("Index");
	lable_index.labelfont(FL_HELVETICA_BOLD);
	lable_index.labelsize(18);
    //lable_index.box(FL_DOWN_BOX);

    lbale_auto_inc.resize(x + 510, y, 50, 30);
	lbale_auto_inc.label("A.I");
	lbale_auto_inc.labelfont(FL_HELVETICA_BOLD);
	lbale_auto_inc.labelsize(18);
    //lbale_auto_inc.box(FL_DOWN_BOX);

    insert_rows_scroll.resize(x + 5, y + 35, w - 10, 380);
    insert_rows_scroll.type(Fl_Scroll::BOTH_ALWAYS);
	
    //insert_rows_scroll.color(FL_WHITE);
    

    save_btn.resize(x + 10, y + 420, 60, 30);
	save_btn.label("Save");
	end();
	init_y = y + 40;
	cur_y = init_y;
	

}


void TableInsertList::add_rows(int count)
{
	
	int x = this->x();
	int w = this->w();
	int size_list = insert_rows_list.size();
	
	insert_rows_list.clear();
	insert_rows_scroll.clear();

	

	for(int i = 0; i < count + size_list; i++)
	{
		insert_rows_list.push_back(std::make_unique<TableInsertRow>(x + 5,cur_y,w - 10, 50,event_sys));
		
		insert_rows_scroll.add(insert_rows_list.back().get());

		if(insert_rows_list.size() == 1)
		{
			insert_rows_list.back()->color(fl_rgb_color(70, 130, 180));
		}
		else if(insert_rows_list.size() % 2 == 0)
		{
			insert_rows_list.back()->color(FL_WHITE);
		}
		else if(insert_rows_list.size() % 2 != 0)
		{
			insert_rows_list.back()->color(fl_rgb_color(119, 136, 153));
		}

		cur_y += 50;
	}

	

	cur_y = init_y;
	insert_rows_scroll.redraw();
	
}

void TableInsertList::clear_rows()
{
	insert_rows_list.clear();
	insert_rows_scroll.clear();
	cur_y = init_y;
}