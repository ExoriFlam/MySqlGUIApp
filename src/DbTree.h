#ifndef DBTREE_H
#define DBTREE_H

#include <FL/Fl_Tree.H>
#include <FL/Fl_PNG_Image.H>



#include "types.h"


class DbTree : public Fl_Tree{

public:

	DbTree(int x, int y, int w, int h);

	
	void init_tree(const DbSchema& schema);

	

private:

	//static void tree_callback(Fl_Widget* widget, void* data);
	

	Fl_PNG_Image db_img;
	Fl_PNG_Image table_img;
	Fl_PNG_Image atribute_img;

	

};



#endif