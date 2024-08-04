#ifndef DBTREE_H
#define DBTREE_H

#include <FL/Fl_Tree.H>
#include <FL/Fl_PNG_Image.H>
#include <list>
#include <utility> 
#include <memory>
#include "types.h"


using UserData = std::pair<std::string, std::string>;
using UserDataList = std::list<std::shared_ptr<UserData>>;


class DbTree : public Fl_Tree{

public:

	DbTree(int x, int y, int w, int h);

	
	void init_tree(const DbSchema& schema);

	

private:
	
	//static void tree_callback(Fl_Widget* widget, void* data);
	void add_user_data(Fl_Tree_Item* node, const std::string& k, const std::string& v);

	Fl_PNG_Image db_img;
	Fl_PNG_Image table_img;
	Fl_PNG_Image atribute_img;

	UserDataList u_data;

};



#endif