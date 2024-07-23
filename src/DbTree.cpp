#include "DbTree.h"
#include <FL/Fl_Tree_Item.H>

DbTree::DbTree(int x, int y, int w, int h):
	Fl_Tree(x, y, w, h)
{
	
	db_img = std::make_unique<Fl_PNG_Image>("../image/db.png");
    table_img = std::make_unique<Fl_PNG_Image>("../image/dbtable.png");
    atribute_img = std::make_unique<Fl_PNG_Image>("../image/dbatr.png");

	first()->label("Db List");
	

	
}

void DbTree::update_schema(const DbSchema& new_schema)
{
	this->schema = new_schema;
}

void DbTree::init_tree()
{
	if(schema.size() == 0)
	{
		#ifdef DEBUG
		std::cout << "db structure is empty";
		
		#endif
		return;
	}
	for(const auto& dbkv : this->schema)
	{

		std::string db_name = dbkv.first;

		Fl_Tree_Item* node_db_name = add(db_name.c_str());
		node_db_name->usericon(db_img.get());
		close(node_db_name);

		const Tables& tables = dbkv.second;

		for(const auto& tablekv : tables)
		{
			const std::string table_name = db_name + "/" + tablekv.first;

			Fl_Tree_Item* node_table_name = add(table_name.c_str());
			node_table_name->usericon(table_img.get());
			close(node_table_name);
			const Atributes& atributes = tablekv.second;

			for(const auto& atribute : atributes)
			{
				const std::string atrib_name = table_name + "/" + atribute;

				Fl_Tree_Item* node_atribute_name = add(atrib_name.c_str());
				node_atribute_name->usericon(atribute_img.get());
				close(node_atribute_name);
			}
		}

	}
	
}