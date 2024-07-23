#ifndef DBTREE_H
#define DBTREE_H

#include <FL/Fl_Tree.H>
#include <FL/Fl_PNG_Image.H>

#include <memory>

#include "types.h"


class DbTree : public Fl_Tree{

public:
	DbTree(int x, int y, int w, int h);
//this->db_list = std::make_unique<Fl_Tree>(10, 50, 200, 520);
private:
	//std::unique_ptr<Fl_Tree> db_list;

	std::unique_ptr<Fl_PNG_Image> db_img;
	std::unique_ptr<Fl_PNG_Image> table_img;
	std::unique_ptr<Fl_PNG_Image> atribute_img;
	

	DbSchema schema;
};


#endif