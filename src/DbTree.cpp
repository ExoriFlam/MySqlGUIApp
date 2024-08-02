#include "DbTree.h"
#include <FL/Fl_Tree_Item.H>
#include <iostream>
#include <utility> 

DbTree::DbTree(int x, int y, int w, int h):
	Fl_Tree(x, y, w, h), db_img("../image/db.png"), table_img("../image/dbtable.png"), atribute_img("../image/dbatr.png")
{
	root_label("Db List");
	
	when(FL_WHEN_CHANGED);
	
	
}




void DbTree::init_tree(const DbSchema& schema)
{
	if(schema.size() == 0)
	{
		#ifdef DEBUG
		std::cout << "db structure is empty";
		
		#endif
		return;
	}
	clear();
	
	for(const auto& dbkv : schema)
	{

		std::string db_name = dbkv.first;

		Fl_Tree_Item* node_db_name = add(db_name.c_str());
		node_db_name->usericon(&db_img);

		auto db_pair = std::make_pair(std::string("db"),db_name);
		node_db_name->user_data(new std::pair<std::string, std::string>(db_pair));
		close(node_db_name);

		

		const Tables& tables = dbkv.second;

		for(const auto& tablekv : tables)
		{
			const std::string table_name = db_name + "/" + tablekv.first;

			Fl_Tree_Item* node_table_name = add(table_name.c_str());
			node_table_name->usericon(&table_img);
			auto table_pair = std::make_pair(std::string("table"),tablekv.first);
			node_table_name->user_data(new std::pair<std::string, std::string>(table_pair));
			close(node_table_name);
			const Atributes& atributes = tablekv.second;

			for(const auto& atribute : atributes)
			{
				const std::string atrib_name = table_name + "/" + atribute;

				Fl_Tree_Item* node_atribute_name = add(atrib_name.c_str());
				node_atribute_name->usericon(&atribute_img);
				auto atrib_pair = std::make_pair(std::string("atribute"), atribute);
				node_atribute_name->user_data(new std::pair<std::string, std::string>(atrib_pair));
				close(node_atribute_name);
			}
		}

	}
	root_label("Db List");
	
}


