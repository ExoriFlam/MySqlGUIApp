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
	this->size_range(800, 600);

	event_sys = std::make_shared<EventSystem>();

	db_helper = std::make_unique<DbHelper>("localhost", "root", "1111", "");

	if(!db_helper->connect())
	{
		#ifdef DEBUG
		std::cout<<"Error connect"<<std::endl;
		#endif
	}

	


	//
	Fl_Menu_Bar* menu = new Fl_Menu_Bar(0, 0, width, 25);
	menu->add("File/New", 0, NULL);
	menu->add("File/Open", 0, NULL);
	menu->add("File/Quit", 0, NULL);
    //
	Fl_Box* status = new Fl_Box(pading, height - 30, width - (pading * 2), 25, "Status: Ready");
	status->box(FL_DOWN_FRAME);

    
	
	tabs = std::make_unique<TabControl>(220, 30, width - (pading * 2) - 220 ,height - 60 , event_sys);
	this->resizable(tabs.get());//
	

	nav_panel = std::make_unique<NavPanel>(pading, 30, 200, 30);
	//this->resizable(nav_panel.get());//

	nav_panel->add_cb_home_btn(on_home_btn_click, tabs.get());
	nav_panel->add_cb_add_db_btn(on_show_tab_control, this);
	nav_panel->add_cb_refresh_btn(on_refresh_btn_click,this);
    

    

	db_list = std::make_unique<DbTree>(pading, 60, 200, height - 90);

	db_list->init_tree(db_helper->get_schema());

	db_list->callback(on_click_tree, this);
	//this->resizable(db_list.get());//
	
    
    // db_managment_group = std::make_unique<Fl_Group>(220, 60, 570 ,500);
    // db_managment_group->box(FL_DOWN_FRAME);

    end();

    add_events();

    

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

	        		//win->tabs->show_structure_db();
	        		win->tabs->show_structure_table();
	        		win->set_selected_db(type->second);
	        		win->event_sys->trigger("on_show_table_list", win);
	        		
	        		
	        	}
	        	else if(type->first == "table")
	        	{
	        		
	        		//win->event_sys->trigger("on_show_table_list", win);
	        	}
	        	else if(type->first == "atribute")
	        	{
	        		win->tabs->show_structure_atribute();
	        	}
	        	else if(type->first == "root")
	        	{

	        		win->tabs->show_tabs();
	        		win->event_sys->trigger("on_show_db_list", win);

	        		
	        		
					
	        	}

        	}
        	
        }
    }
}

void MainWindow::add_events()
{

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
			else
			{
				event_sys->trigger("on_show_db_list", this);
				refresh_all_visible_widgets();
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
			
			

			if(a_name == "Structure")
			{
				if(type == "Databases")
				{
					set_selected_db(value);
					
					tabs->show_structure_table();
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
				if(type == "Tables")
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
					else
					{
						event_sys->trigger("on_show_db_list", this);
						refresh_all_visible_widgets();
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

	event_sys->subscribe("on_create_table",[this](Fl_Widget* w){

		TableStructureGroup* tsg = (TableStructureGroup*)w;
		tabs->show_insert();
		std::string nbr_cols_str = tsg->get_input_nbr_cols();
		int nbr_cols;

		if(!nbr_cols_str.empty())
		{
			nbr_cols = std::stoi(nbr_cols_str);
		}
		else
		{
			nbr_cols = 0;
		}

		tabs->set_table_name(tsg->get_input_table_name());
		tabs->add_rows(nbr_cols);

	});



	event_sys->subscribe("on_click_add_btn", [this](Fl_Widget* w){

		TableInsertGroup* tig = (TableInsertGroup*)w;
		std::string nbr_cols_str = tig->get_input_nbr_cols();
		int nbr_cols;
		if(!nbr_cols_str.empty())
		{
			nbr_cols = std::stoi(nbr_cols_str);
		}
		else
		{
			nbr_cols = 0;
		}
		tabs->add_rows(nbr_cols);
	});

	event_sys->subscribe("on_click_save_btn", [this](Fl_Widget* w){

		TableInsertGroup* tig = (TableInsertGroup*)w;
		std::string query = tig->get_sql_query();

		if(query != "error")
		{

			db_helper->execute_modification_query("USE " + selected_db + ";");

			if(db_helper->execute_modification_query(query))
			{
				#ifdef DEBUG
				std::cout << "Successfully executed query\n" << query;
				#endif
			}
			else
			{
				#ifdef DEBUG
				std::cout << "Fail executed query\n" << query;
				#endif
			}
		}

		tabs->show_tabs();
		
	});
}