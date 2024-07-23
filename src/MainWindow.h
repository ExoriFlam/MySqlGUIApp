#ifndef MAINWIN_H
#define MAINWIN_H
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Tree.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Box.H>
#include "AddDbButton.h"
#include "DbHelper.h"
#include "DbTree.h"
#include <memory>

class MainWindow : public Fl_Double_Window{

public:
	MainWindow(int x, int y, int w, int h, const char* l);

private:

	std::unique_ptr<AddDbButton> add_db;

	// std::unique_ptr<Fl_Tree> db_list;
	std::unique_ptr<DbTree> db_list;

	
	std::unique_ptr<Fl_Group> db_managment_group;

	std::unique_ptr<DbHelper> db_helper;

	static void add_db_but_cb(Fl_Widget* o, void* v);
	void add_db_but_cbi(AddDbButton* wid);


	static void submit_db_name_but_cb(Fl_Widget* o, void* v);
	void submit_db_name_but_cbi(Fl_Button* wid);
};


#endif