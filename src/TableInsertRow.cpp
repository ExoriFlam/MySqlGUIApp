#include "TableInsertRow.h"

TableInsertRow::TableInsertRow(int x, int y, int w, int h, std::shared_ptr<EventSystem> e_sys):
	Fl_Group(x, y, w, h), name(0, 0, 0, 0), type(0, 0, 0, 0), length(0, 0, 0, 0), default_val(0, 0, 0, 0),
	nullable(0, 0, 0, 0), index(0, 0, 0, 0), auto_inc(0, 0, 0, 0)
{
	
	event_sys = e_sys;

	name.resize(x + 10 , y + 10, 100, 30);
	//name.color(FL_WHITE);
	
    type.resize(x + 110, y + 10, 75, 30);
    type.callback(on_change_type_val, &auto_inc);
	
	
	type.add("INT");
	type.add("TINYINT");
	type.add("BOOLEAN");
	type.add("BIGINT");
	type.add("FLOAT");
	type.add("DOUBLE");

	type.add("CHAR");
	type.add("VARCHAR");
	type.add("TEXT");
	type.add("BINARY");

	type.add("DATE");
	type.add("TIME");
	type.add("DATETIME");
	type.add("TIMESTAMP");
	type.add("YEAR");
	

    length.resize(x + 185, y + 10, 120, 30);
	//length.color(FL_WHITE);

    default_val.resize(x + 305 , y + 10, 80, 30);
    default_val.add("NULL");
    default_val.add("CURRENT_TIMESTAMP");
	//default_val.color(FL_WHITE);

    nullable.resize(x + 395, y + 10, 25, 30);
	

    index.resize(x + 425, y + 10, 80, 30);
    index.add("...");
    //index.add("PRIMARY");
    index.add("UNIQUE");
    index.value(0);
    auto_inc.resize(x + 525, y + 10, 25, 30);
    auto_inc.callback(on_change_auto_inc, &index);
    auto_inc.deactivate();
	

	this->box(FL_THIN_DOWN_BOX);
	

	end();


}


void TableInsertRow::on_change_type_val(Fl_Widget* w, void* v)
{
	Fl_Check_Button* check_button = (Fl_Check_Button*)v;
	Fl_Choice* type_choice = (Fl_Choice*) w;
	if(type_choice)
	{

		const Fl_Menu_Item* item = type_choice->mvalue();
		
		if(item)
		{
			
			std::string text = item->label();
			if(text == "INT" || text == "TINYINT" || text == "BIGINT")
			{
				check_button->activate();
			}
			else
			{
				check_button->deactivate();
				check_button->value(0);
			}

		}
	}

}

void TableInsertRow::on_change_auto_inc(Fl_Widget* w, void* v)
{
    Fl_Check_Button* check_btn_a_i = (Fl_Check_Button*)w;
    Fl_Choice* index_ch = (Fl_Choice*)v;
    
    if(check_btn_a_i)
    {
        if(check_btn_a_i->value())
        { 
            if(index_ch)
            {
                if(index_ch->find_index("PRIMARY") == -1)
                { 
                    index_ch->add("PRIMARY");
                }
            }
        }
        else
        { 
            if(index_ch)
            {
                int index = index_ch->find_index("PRIMARY");
                if(index >= 0)
                { 
                    index_ch->remove(index);

                    if(index_ch->size() > 0)
                    {
                        index_ch->value(0);
                    }
                }
            }
        }
    }
}

std::string TableInsertRow::get_sql_row()
{
   std::string result;

  
    const char* name_value = name.value();
    result += name_value ? name_value : "";
    if(result.empty())
    {
    	return "error";
    }
    result += " ";

    
    const char* type_value = type.text();
    if(!type_value)
    {
    	return "error";
    }  
    result += type_value ? type_value : "";

    std::string val_len = length.value() ? length.value() : "";

    if (!val_len.empty())
    {
        result += "(";
        result += val_len;
        result += ")";
    }

    result += " ";

    
    if (auto_inc.value())
    {
        result += "AUTO_INCREMENT ";
    }

    
    const char* idx_value = index.text();  
    if (idx_value && *idx_value != '\0')
    {

    	if(std::string(idx_value) != "...")
    	{
    		result += idx_value;

	        if (std::string(idx_value) == "PRIMARY")
	        {
	            result += " KEY";
	        }
    	}
        
    }

    
    if (nullable.value())
    {
        if (!auto_inc.value())
        {
            result += " NULL";
        }
    }
    else
    {
        result += " NOT NULL";
    }

    
    const char* def_value = default_val.text(); 
    if (def_value && *def_value != '\0')
    {
        result += " DEFAULT ";
        result += def_value;
    }

    return result;
}