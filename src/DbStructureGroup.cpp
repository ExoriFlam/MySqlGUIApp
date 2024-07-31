#include "DbStructureGroup.h"
#include <iostream>

DbStructureGroup::DbStructureGroup(int x, int y, int w, int h, std::shared_ptr<EventSystem> e_sys):
	Fl_Group(x, y, w, h), header(0, 0, 0, 0), label_create_db(0, 0, 0, 0), input_create_db(0, 0, 0, 0),
	btn_create_db(0, 0, 0, 0), line(0, 0, 0, 0)
{
	event_sys = e_sys;

	header.resize(x + 50, y + 10, 50, 30);
	header.label("Databases");
	header.labelfont(FL_HELVETICA_BOLD);
	header.labelsize(20);
	
	
	label_create_db.resize(x + 50, y + 55, 50, 30);
	label_create_db.label("Create Database");
	label_create_db.labelfont(FL_HELVETICA);
	label_create_db.labelsize(14);

	
	
	input_create_db.resize(x + 140, y + 60, 90, 30);
	input_create_db.color(FL_WHITE);
	
	
	btn_create_db.resize(x + 240, y + 60, 60, 30);
	btn_create_db.label("Create");
	btn_create_db.callback(add_cb_create_db_btn, this);
	

	line.resize(x + 10, y + 100, w - 20, 2);
	line.color(FL_BLACK);
	line.box(FL_FLAT_BOX);

	data_list = std::make_unique<DataList>(x + 10, y + 110, w-20, 340, e_sys);
	data_list->set_header_name("Databases");
	//data_list.resize(x + 10, y + 110, w-20, 340);

	// databases_header = std::make_unique<Fl_Box>(x + 10, y + 110, 200, 30, "Databases");
	// databases_header->box(FL_UP_BOX);
	// action_header = std::make_unique<Fl_Box>(x + 205, y + 110, 200, 30, "Actions");
	// action_header->box(FL_UP_BOX);

	

	// table = std::make_unique<Fl_Scroll>(x + 10, y + 145, 405, 350);
	// table->type(Fl_Scroll::VERTICAL);

	end();
	
}

void DbStructureGroup::show_dbs(const std::vector<std::string>& db_names)
{
	if(db_names.size() == 0)
	{

		#ifdef DEBUG
		std::cout << "empty db_names";
		#endif
		return;
	}

	// rows.clear();
	// table->clear();
	
	// rows.reserve(db_names.size());

	// for (int i = 0; i < db_names.size(); ++i) {

 //        auto box1 = new Fl_Box(x() + 10, y() + 145 + (i * 31), 200, 30);
 //        auto box2 = new Fl_Box(x() + 205, y() + 145 + (i * 31), 200, 30, "Check privileges" );
 //        box1->labelcolor(FL_BLUE);
 //        box1->labelfont(FL_HELVETICA_ITALIC);
 //        box1->labelsize(14);
 //        box1->copy_label(db_names[i].c_str());
 //        box1->box(FL_DOWN_BOX);

 //        box2->labelcolor(FL_BLUE);
 //        box2->labelfont(FL_HELVETICA_ITALIC);
 //        box2->labelsize(14);
 //        box2->box(FL_DOWN_BOX);
 //        if( i %  2 == 0)
 //        {
 //        	box1->color(FL_WHITE);
 //        	box2->color(FL_WHITE);
 //        }

 //        rows.emplace_back(box1, box2);
 //        table->add(box1);
 //        table->add(box2);
 //    }

}

void DbStructureGroup::add_cb_create_db_btn(Fl_Widget* widget, void* v)
{
	DbStructureGroup* db_s = (DbStructureGroup*) v;

	db_s->event_sys->trigger("on_click_create_db_btn", &db_s->input_create_db);
	
}

std::string DbStructureGroup::get_input_value()
{
	return std::string(input_create_db.value());
}