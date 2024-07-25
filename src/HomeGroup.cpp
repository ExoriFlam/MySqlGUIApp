#include "HomeGroup.h"

HomeGroup::HomeGroup(int x, int y, int w, int h):
	Fl_Group(x, y, w, h)
{
	//text_box.label("qweqweasdfasdasdasdasd");
	//text_box.size(w, h);
	
	//text = std::make_unique<Fl_Multiline_Output>(x,y,w,h);
	text = std::make_unique<Fl_Box>(x, y + 10, w, h);

	 

	
	 text->label(
        "Welcome to MySqlGUIApp!\n\n"
        "MySqlGUIApp is a user-friendly interface designed\n"
        "to simplify your interactions with MySQL databases.\n"
        "Whether you are a database administrator or a\n"
        "developer, our application offers a comprehensive\n"
        "set of tools for managing and working with your\n"
        "databases efficiently.\n\n"
        "Features Include:\n"
        "Intuitive Interface:\n"
        "Easy navigation and management of your databases,\n"
        "tables, and records.\n"
        "Powerful Tools:\n"
        "Create, modify, and delete databases and tables\n"
        "with just a few clicks.\n"
        "Data Management:\n"
        "Insert, update, and delete records effortlessly.\n"
        "Database Schema Overview:\n"
        "Get a clear view of your database structure and\n"
        "relationships.\n"
        "Backup and Restore:\n"
        "Ensure your data is safe with our backup and\n"
        "restore functionalities.\n"
        "Explore MySqlGUIApp to experience seamless\n"
        "database management and enhance your productivity.\n"
        "Thank you for choosing MySqlGUIApp!"
    );
	//text_box.box(FL_NO_BOX);
	//text_box->align(FL_ALIGN_LEFT | FL_ALIGN_TOP);
	text->labelsize(15);
	text->box(FL_NO_BOX);
	text->align( FL_ALIGN_LEFT | FL_ALIGN_TOP | FL_ALIGN_INSIDE);

	text->labelfont(FL_HELVETICA); 
	

	//box(FL_DOWN_BOX);


	end();
	
}