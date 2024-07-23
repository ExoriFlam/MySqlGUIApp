#include "DbTree.h"
#include <FL/Fl_Tree_Item.H>

DbTree::DbTree(int x, int y, int w, int h):
	Fl_Tree(x, y, w, h)
{
	//db_list = std::make_unique<Fl_Tree>(x, y, w, h);
	
	db_img = std::make_unique<Fl_PNG_Image>("../image/db.png");
    table_img = std::make_unique<Fl_PNG_Image>("../image/dbtable.png");
    atribute_img = std::make_unique<Fl_PNG_Image>("../image/dbatr.png");

	first()->label("Db List");

	// Fl_Tree_Item* node1 = db_list->add("Db List");
 	//    node1->usericon(image);
 	//    db_list->redraw();
	///
    //this->db_list->first()->label("Db List",image);
}