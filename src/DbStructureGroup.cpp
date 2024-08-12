#include "DbStructureGroup.h"
#include "MainWindow.h"
#include <iostream>

DbStructureGroup::DbStructureGroup(int x, int y, int w, int h, std::shared_ptr<EventSystem> e_sys):
	Fl_Group(x, y, w, h), header(0, 0, 0, 0), label_create_db(0, 0, 0, 0), input_create_db(0, 0, 0, 0),
	btn_create_db(0, 0, 0, 0), line(0, 0, 0, 0)
{
	event_sys = e_sys;
	
	int padding = 50;
	int row_height = 30;
	float scale_row_factor = .0f;
	int relative_w;

	relative_w = w * 0.1;

	header.resize(x + padding, y + 10, relative_w, row_height);
	header.label("Databases");
	header.labelfont(FL_HELVETICA_BOLD);
	header.labelsize(20);
	
	relative_w = w * 0.1;
	label_create_db.resize(x + padding, y + 55, relative_w, row_height);
	label_create_db.label("Create Database");
	label_create_db.labelfont(FL_HELVETICA);
	label_create_db.labelsize(14);
	//label_create_db.box(FL_DOWN_BOX);
	scale_row_factor = 0.1;
	
	relative_w = w * 0.07;
	input_create_db.resize(x + padding + w * scale_row_factor , y + 55, relative_w, row_height);
	input_create_db.labelsize(14);
	input_create_db.color(FL_WHITE);
	scale_row_factor += 0.07f;
	
	
	relative_w = w * 0.05;
	btn_create_db.resize(x + padding + w * scale_row_factor, y + 55, relative_w, row_height);
	btn_create_db.label("Create");
	btn_create_db.callback(add_cb_create_db_btn, this);
	

	line.resize(x + 10, y + 100, w - 20, 2);
	line.color(FL_BLACK);
	line.box(FL_FLAT_BOX);
	
	db_list = std::make_unique<DataList>(x + 10, y + 110, w-20, h - 145 - 30, e_sys);

	db_list->set_header_name("Databases");
	db_list->box(FL_DOWN_BOX);
	db_list->end();
	
	this->resizable(&header);//
	this->resizable(&label_create_db);//
	this->resizable(&input_create_db);//
	this->resizable(&btn_create_db);//
	this->resizable(&line);//
	this->resizable(db_list.get());//
	
	event_sys->subscribe("on_show_db_list",[this](Fl_Widget* w){
		MainWindow* win = (MainWindow*) w;
		show_dbs(win->db_helper->get_db_names());
	});
	
	end();
	
}

void DbStructureGroup::show_dbs(const std::vector<std::string>& db_names)
{
	
	db_list->add_rows(db_names);
}

void DbStructureGroup::add_cb_create_db_btn(Fl_Widget* widget, void* v)
{
	(void)widget;//
	
	DbStructureGroup* db_s = (DbStructureGroup*) v;

	db_s->event_sys->trigger("on_click_create_db_btn", &db_s->input_create_db);
	
}

