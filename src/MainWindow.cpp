#include "MainWindow.h"
#include <iostream>
#include <string>
#include <vector>
///
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Box.H>


#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Tree_Item.H>

MainWindow::MainWindow(int x, int y, int w, int h, const char* l = 0) :
	Fl_Double_Window(x, y, w, h, l), width(w), height(h), pading(10)
{
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

    
	
    nav_panel = std::make_unique<NavPanel>(pading, 30,200,30);

	db_list = std::make_unique<DbTree>(pading, 60, 200, 500);

	db_list->init_tree(db_helper->get_schema());

	
    
    db_managment_group = std::make_unique<Fl_Group>(220, 60, 570 ,500);
    db_managment_group->box(FL_DOWN_FRAME);

    end();
}

// void MainWindow::add_db_but_cb(Fl_Widget* o, void* v)
// {
// 	MainWindow* win = (MainWindow*)v;
// 	AddDbButton* btn = (AddDbButton*)o;
// 	win->add_db_but_cbi(btn);
// }

// void MainWindow::add_db_but_cbi(AddDbButton* wid)
// {
// 	this->db_managment_group->clear(); 
//     this->db_managment_group->redraw(); 
// 	this->db_managment_group->begin();

// 	Fl_Input* db_name_input = new Fl_Input(305, 80, 260, 30, "DB Name:");
// 	db_name_input->maximum_size(64);
    
//     Fl_Button* submit_btn = new Fl_Button(305, 160, 260, 30, "Submit");
//     submit_btn->callback(submit_db_name_but_cb, this);
//     this->db_managment_group->end();
//     this->db_managment_group->redraw();

// }

// void MainWindow::submit_db_name_but_cb(Fl_Widget* o, void* v)
// {
// 	MainWindow* win = (MainWindow*)v;
// 	Fl_Button* btn = (AddDbButton*)o;
// 	win->submit_db_name_but_cbi(btn);
// }

// void MainWindow::submit_db_name_but_cbi(Fl_Button* wid)
// {
// 	Fl_Input* input = (Fl_Input*)db_managment_group->child(0);
// 	std::string db_name = input->value();
// 	this->db_helper->create_db(db_name);
// }