#include "TabControl.h"
#include <iostream>
TabControl::TabControl(int x, int y, int w, int h, std::shared_ptr<EventSystem> e_sys):
	Fl_Tabs(x, y, w, h), structure_group(nullptr), sql_group(nullptr), insert_group(nullptr)
{
	structure_group = std::make_unique<StructureGroup>(x , y + 25, w , h, e_sys);
	//structure_group->color(FL_WHITE);
	//structure_group->selection_color(FL_WHITE);
	

	add(structure_group.get());
	
	sql_group = std::make_unique<SQLGroup>(x , y + 25, w , h );
	add(sql_group.get());
		
	insert_group = std::make_unique<InsertGroup>(x , y + 25, w , h, e_sys);

	add(insert_group.get());
	end();

	value(structure_group.get());
	
	home_group = std::make_unique<HomeGroup>(x + 5, y + 25, w - 10, h - 35 );
	show_home();
}

void TabControl::show_home()
{
	home_group->show();
	home_group->redraw();
	sql_group->hide();
	structure_group->hide();
	insert_group->hide();
	this->deactivate();
}

void TabControl::show_tabs()
{
	sql_group->show();
	insert_group->show(); // 
	structure_group->show();
	structure_group->show_db_group();
	home_group->hide();
	structure_group->redraw();
	this->activate();
}




void TabControl::show_structure_db()
{
	structure_group->show_db_group();
}
void TabControl::show_structure_table()
{
	structure_group->show_table_group();
}
void TabControl::show_structure_atribute()
{
	structure_group->show_atribute_group();
}

// void TabControl::show_insert_table()
// {
// 	insert_group->show_insert_table_group();
// }


// int TabControl::handle(int event)
// {
//     if (event == FL_PUSH)
//     {
//         Fl_Widget *child = which(Fl::event_x(), Fl::event_y());

//         if (child && !child->active())
//         {
//         	//std::cout << "123";
//             return 1;
//         }
//     }
//     return Fl_Tabs::handle(event);
// }