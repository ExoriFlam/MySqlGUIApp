#ifndef MAINWIN_H
#define MAINWIN_H
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Tree.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Box.H>

#include "DbHelper.h"
#include "EventSystem.h"
#include "NavPanel.h"
#include "DbTree.h"
#include "TabControl.h"
#include "HomeGroup.h"
#include <memory>

class MainWindow : public Fl_Double_Window{

public:
	MainWindow(int x, int y, int w, int h, const char* l);

private:

	int width;
	int height;
	int pading;

	

	std::unique_ptr<NavPanel> nav_panel;
	std::unique_ptr<DbTree> db_list;
	std::unique_ptr<TabControl> tabs;
	std::shared_ptr<EventSystem> event_sys;

	std::unique_ptr<DbHelper> db_helper;

	// void recursive_redraw(Fl_Widget* widget);
	void refresh_all_visible_widgets();

	//navbar btns actions
	static void on_home_btn_click(Fl_Widget* w , void* v);
	static void on_show_tab_control(Fl_Widget* w , void* v);
	static void on_refresh_btn_click(Fl_Widget* w , void * v);

	//DbTree btn actions
	static void on_click_tree(Fl_Widget* w, void* v);


	//structure view
	////Databases
	//static void on_create_db_btn_click(Fl_Widget* w , void* v);
	////Tables
	////Atributes



};


#endif