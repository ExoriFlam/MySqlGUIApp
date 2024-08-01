#include "IconLabelGroup.h"
#include <iostream>
IconLabelGroup::IconLabelGroup(int x, int y, int w, int h, const std::string& img_path, const std::string& label)
    : Fl_Group(x, y, w, h), cb_(nullptr), cb_data_(nullptr), image_box(0, 0, 0, 0), label_box(0, 0, 0, 0), icon(img_path.c_str())
{
    
    image_box.resize(x, y, 20, 30);
    image_box.image(icon.copy(15,15));
    image_box.box(FL_NO_BOX);
    
    label_box.resize(x + 20, y, w - 20, 30);
    label_box.copy_label(label.c_str());
    label_box.box(FL_NO_BOX);
    label_box.align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
    label_box.labelcolor(FL_BLACK);
    

    end();
}

std::string IconLabelGroup::get_label()
{
    return std::string(label_box.label());
}

std::string IconLabelGroup::get_row_data()
{
    return row_data;
}
void IconLabelGroup::set_row_data(const std::string& r_data)
{
    row_data = r_data;
}


void IconLabelGroup::callback(Fl_Callback* cb, void* data)
{
    cb_ = cb;
    cb_data_ = data;
}

int IconLabelGroup::handle(int event)
{

    switch (event)
    {
        case FL_PUSH:
            if (Fl::event_inside(this))
            {
                //if (cb_) cb_(this, cb_data_);
                return 1; 
            }
            break;
        case FL_RELEASE:
            if (Fl::event_inside(this))
            {
                if (cb_) cb_(this, cb_data_);
                return 1; 
            }
            break;
        case FL_ENTER:

            
            label_box.labelcolor(FL_BLUE);
            label_box.redraw();
            return 1; 
            
           
        case FL_LEAVE:

           
            
            label_box.labelcolor(FL_BLACK);
            label_box.redraw();
            return 1; 
            
            
        case FL_DRAG:
            return 1;  
            break;
    }

    return Fl_Group::handle(event);
}

