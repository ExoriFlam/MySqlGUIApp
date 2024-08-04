#include "DbTree.h"
#include <FL/Fl_Tree_Item.H>
#include <iostream>



DbTree::DbTree(int x, int y, int w, int h):
	Fl_Tree(x, y, w, h), db_img("../image/db.png"), table_img("../image/dbtable.png"), atribute_img("../image/dbatr.png")
{
	root_label("Db List");
	
	when(FL_WHEN_CHANGED);
	
	
}

void DbTree::add_user_data(Fl_Tree_Item* node, const std::string& k, const std::string& v)
{
	if(node)
	{
		u_data.push_back(std::make_shared<UserData>(k,v));
		node->user_data(u_data.back().get());
	}
}


void DbTree::init_tree(const DbSchema& schema)
{
	
	
	u_data.clear();
	clear();
	

	if(schema.empty())
	{
		#ifdef DEBUG
		std::cout << "db structure is empty";
		
		#endif
		return;
	}
	

	
	 

	for(const auto& dbkv : schema)
	{

		std::string db_name = dbkv.first;

		Fl_Tree_Item* node_db_name = add(db_name.c_str());
		node_db_name->usericon(&db_img);
		add_user_data(node_db_name,"db",db_name);
		close(node_db_name);
		
		const Tables& tables = dbkv.second;

		for(const auto& tablekv : tables)
		{
			const std::string table_name = db_name + "/" + tablekv.first;

			Fl_Tree_Item* node_table_name = add(table_name.c_str());
			node_table_name->usericon(&table_img);
			add_user_data(node_table_name,"table", tablekv.first);
			close(node_table_name);
			
			const Atributes& atributes = tablekv.second;

			for(const auto& atribute : atributes)
			{
				const std::string atrib_name = table_name + "/" + atribute;

				Fl_Tree_Item* node_atribute_name = add(atrib_name.c_str());
				node_atribute_name->usericon(&atribute_img);
				add_user_data(node_atribute_name,"atribute",atribute);
				close(node_atribute_name);
				
			}
		}

	}

 
	 add_user_data(this->root(),"root","root");
	 root_label("Db List");
	 


}


