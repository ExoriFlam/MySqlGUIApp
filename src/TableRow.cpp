#include "TableRow.h"

TableRow::TableRow(int x, int y, int w, int h, const char* t_name)
	:Fl_Group(x, y, w, h)
{
	begin();
	check = std::make_unique<Fl_Check_Button>(x, y, 15, 30);
	table_name = std::make_unique<Fl_Box>(x + 40, y, 220, 30);
	table_name->copy_label(t_name);

	actions.push_back(new IconLabelGroup(x + 280, y, 100, 30, "../image/structure.png", "Structure"));
    actions.push_back(new IconLabelGroup(x + 380, y, 70, 30, "../image/insert.png", "Insert"));
    actions.push_back(new IconLabelGroup(x + 450, y, 40, 30, "../image/drop.png", "Drop"));

	for(const auto& actiontab : actions)
	{
		add(actiontab);
	}
	box(FL_THIN_DOWN_BOX);
	end();
}

