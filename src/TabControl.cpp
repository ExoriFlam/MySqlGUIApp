#include "TabControl.h"
#include <iostream>
TabControl::TabControl(int x, int y, int w, int h, std::shared_ptr<EventSystem> e_sys):
	Fl_Tabs(x, y, w, h), structure_group(nullptr), sql_group(nullptr)
{
	structure_group = std::make_unique<StructureGroup>(x , y + 25, w , h, e_sys);
	add(structure_group.get());
	
	sql_group = std::make_unique<SQLGroup>(x , y + 25, w , h );
	add(sql_group.get());
		
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
	this->deactivate();
}

void TabControl::show_tabs()
{
	sql_group->show();
	structure_group->show();
	structure_group->show_db_group();
	home_group->hide();
	structure_group->redraw();
	this->activate();
}

void TabControl::show_db_names(const std::vector<std::string>& db_names)
{
	//structure_group->redraw();
	//structure_group->show_dbs(db_names);
	
}


// void TabControl::add_cb_create_db_btn(Fl_Callback* cb, void* v)
// {
// 	structure_group->add_cb_create_db_btn(cb, v);
// }

// std::string TabControl::get_input_db_name()
// {
// 	return structure_group->get_input_db_name();
// }



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