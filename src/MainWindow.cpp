#include "MainWindow.h"
#include <iostream>
#include <string>
#include <vector>
///
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>

#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Tree_Item.H>

MainWindow::MainWindow(int x, int y, int w, int h, const char* l = 0) :
	Fl_Double_Window(x, y, w, h, l), width(w), height(h), pading(10)
{
	event_sys = std::make_shared<EventSystem>();

	db_helper = std::make_unique<DbHelper>("localhost", "root", "1111", "");

	if(!db_helper->connect())
	{
		#ifdef DEBUG
		std::cout<<"Error connect"<<std::endl;
		#endif
	}

	begin();


	//
	Fl_Menu_Bar* menu = new Fl_Menu_Bar(0, 0, width, 25);
	menu->add("File/New", 0, NULL);
	menu->add("File/Open", 0, NULL);
	menu->add("File/Quit", 0, NULL);
    //
	Fl_Box* status = new Fl_Box(pading, height - 30, width - (pading * 2), 25, "Status: Ready");
	status->box(FL_DOWN_FRAME);

    
	
	tabs = std::make_unique<TabControl>(220, 30, 570 ,530, event_sys);
	//tabs->add_cb_create_db_btn(on_create_db_btn_click, this);

	nav_panel = std::make_unique<NavPanel>(pading, 30, 200, 30);
	
	nav_panel->add_cb_home_btn(on_home_btn_click, tabs.get());
	nav_panel->add_cb_add_db_btn(on_show_tab_control, this);
	nav_panel->add_cb_refresh_btn(on_refresh_btn_click,this);
    

    

	db_list = std::make_unique<DbTree>(pading, 60, 200, 500);

	db_list->init_tree(db_helper->get_schema());

	db_list->callback(on_click_tree, this);

	
    
    // db_managment_group = std::make_unique<Fl_Group>(220, 60, 570 ,500);
    // db_managment_group->box(FL_DOWN_FRAME);

    end();


    event_sys->subscribe("on_click_create_db_btn", [this](Fl_Widget* w) {

		Fl_Input* input = (Fl_Input*)w;
		if(input)
		{
			std::string db_name = input->value();

			if(!db_helper->create_db(db_name))
			{
				#ifdef DEBUG
	 			std::cout << "Fail create db";
	    		#endif
			}
		}
		

	});
	


	event_sys->subscribe("on_click_row_action", [this](Fl_Widget* w){
		
		IconLabelGroup* l =  (IconLabelGroup*) w;
		if(l)
		{
			std::string a_name= l->get_action_name();
			std::string type = l->get_data_type();
			std::string value = l->get_data_value();
			
			std::cout << a_name << " " << type << " " << value;

			if(a_name == "Structure")
			{
				if(type == "Databases")
				{
					set_selected_db(value);
					

					event_sys->trigger("on_show_table_list", this);

				}
				else if(type == "Tables")
				{

				}
				else if(type == "Atributes")
				{

				}
			}
			else if(a_name == "Insert")
			{
				if(type == "Databases")
				{

				}
				else if(type == "Tables")
				{

				}
				else if(type == "Atributes")
				{
					
				}
			}
			else if(a_name == "Drop")
			{

				if(type == "Databases")
				{
					
					if(!db_helper->drop_db(value))
					{
						#ifdef DEBUG
			 			std::cout << "Fail drop db";
			    		#endif
					}
				}
				else if(type == "Tables")
				{

				}
				else if(type == "Atributes")
				{
					
				}
				
			}
		}
	});



}


std::string MainWindow::get_selected_db()
{
	return selected_db;
}

void MainWindow::set_selected_db(const std::string& s_db)
{
	selected_db = s_db;
}

void MainWindow::on_home_btn_click(Fl_Widget* w, void* v)
{
	(void)w;//
	TabControl* tabs = (TabControl*)v;
	tabs->show_home(); 
}

void MainWindow::on_show_tab_control(Fl_Widget* w , void* v)
{
	(void)w;//
	MainWindow* win = (MainWindow*)v;
	win->tabs->show_tabs();
	win->event_sys->trigger("on_show_db_list", win); 
	
}


void MainWindow::on_refresh_btn_click(Fl_Widget* w , void* v)
{
	(void)w;//
	MainWindow* win = (MainWindow*)v;
	win->refresh_all_visible_widgets();
	win->event_sys->trigger("on_show_db_list", win);
}

void MainWindow::refresh_all_visible_widgets()
{
	db_list->init_tree(db_helper->get_schema());
	//tabs->show_db_names(db_helper->get_db_names());
	
}

void MainWindow::on_click_tree(Fl_Widget* w, void* v)
{
	(void)w;//
	MainWindow* win = (MainWindow*) v;

	
    if (Fl::event() == FL_PUSH) 
    {
        Fl_Tree_Item* item = win->db_list->callback_item();

        if (item)
        {
        	win->tabs->show_tabs(); 
        	auto* type = static_cast<std::pair<std::string, std::string>*>(item->user_data());
        	if(type)
        	{
        		if(type->first == "db")
	        	{
	        		win->tabs->show_structure_db();
	        		win->set_selected_db(type->second);
	        		win->event_sys->trigger("on_show_db_list", win);
	        		
	        		
	        	}
	        	else if(type->first == "table")
	        	{
	        		win->tabs->show_structure_table();
	        		win->event_sys->trigger("on_show_table_list", win);
	        	}
	        	else if(type->first == "atribute")
	        	{
	        		win->tabs->show_structure_atribute();
	        	}

        	}
        	
        }
    }
}

