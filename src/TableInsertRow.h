#ifndef TABLEINSROW_H
#define TABLEINSROW_H

#include <memory>
#include <FL/Fl_Group.H>
#include "EventSystem.h"
class TableInsertRow : public Fl_Group
{
public:

	TableInsertRow(int x, int y, int w, int h, std::shared_ptr<EventSystem> e_sys);


private:
  std::shared_ptr<EventSystem> event_sys;
  
};


#endif // TABLEINSROW_H