#include "MainWindow.h"
#include <iostream>
#include <string>
#include <vector>
///
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Tree_Item.H>

MainWindow::MainWindow(int x, int y, int w, int h, const char* l = 0) :
	Fl_Double_Window(x, y, w, h, l)
{
	this->db_helper = std::make_unique<DbHelper>("localhost", "root", "1111", "");

	if(!this->db_helper->connect())
	{
		#ifdef DEBUG
		std::cout<<"Error connect"<<std::endl;
		#endif
	}

	this->begin();
	this->add_db = std::make_unique<AddDbButton>(10,15, 30,30);

	this->add_db->callback(add_db_but_cb,this);

	this->add_db->set_image("../image/addDb.png");

	this->db_list = std::make_unique<DbTree>(10, 50, 200, 520);

	this->db_list->update_schema(db_helper->get_schema());

	this->db_list->init_tree();
	///
	// Fl_PNG_Image* image = new Fl_PNG_Image("../image/db.png");
	// Fl_Tree_Item* node1 = db_list->add("Db List");
 //    node1->usericon(image);
 //    db_list->redraw();
	///
    //this->db_list->first()->label("Db List",image);

    // std::vector<std::string> db_names = db_helper->get_db_names();

    // if(db_names.size() > 0)
    // {
    // 	for(std::string& name : db_names)
    // 	{
    // 		db_list->add(name.c_str());
    // 	}
    // }
    

    ///
    db_managment_group = std::make_unique<Fl_Group>(220, 50, 570 ,520);
    db_managment_group->box(FL_DOWN_FRAME);
    this->end();
}

void MainWindow::add_db_but_cb(Fl_Widget* o, void* v)
{
	MainWindow* win = (MainWindow*)v;
	AddDbButton* btn = (AddDbButton*)o;
	win->add_db_but_cbi(btn);
}

void MainWindow::add_db_but_cbi(AddDbButton* wid)
{
	this->db_managment_group->clear(); 
    this->db_managment_group->redraw(); 
	this->db_managment_group->begin();

	Fl_Input* db_name_input = new Fl_Input(305, 80, 260, 30, "DB Name:");
	db_name_input->maximum_size(64);
    
    Fl_Button* submit_btn = new Fl_Button(305, 160, 260, 30, "Submit");
    submit_btn->callback(submit_db_name_but_cb, this);
    this->db_managment_group->end();
    this->db_managment_group->redraw();

}

void MainWindow::submit_db_name_but_cb(Fl_Widget* o, void* v)
{
	MainWindow* win = (MainWindow*)v;
	Fl_Button* btn = (AddDbButton*)o;
	win->submit_db_name_but_cbi(btn);
}

void MainWindow::submit_db_name_but_cbi(Fl_Button* wid)
{
	Fl_Input* input = (Fl_Input*)db_managment_group->child(0);
	std::string db_name = input->value();
	this->db_helper->create_db(db_name);
}