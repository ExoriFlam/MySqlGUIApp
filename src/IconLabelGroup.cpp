#include "IconLabelGroup.h"
#include <iostream>
IconLabelGroup::IconLabelGroup(int x, int y, int w, int h, const std::string& img_path, const std::string& label)
    : Fl_Group(x, y, w, h), cb_(nullptr), cb_data_(nullptr), image_box(0, 0, 0, 0), label_box(0, 0, 0, 0), icon(img_path.c_str())
{
    
    image_box.resize(x, y, 20, 30);
    image_box.image(icon.copy(15,15));
    image_box.box(FL_NO_BOX);
    
    label_box.resize(x + 20, y, w - 35, 30);
    label_box.copy_label(label.c_str());
    label_box.box(FL_NO_BOX);
    label_box.align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
    label_box.color(FL_BLUE);
    

    end();
}


void IconLabelGroup::callback(Fl_Callback* cb, void* data)
{
    cb_ = cb;
    cb_data_ = data;
}

int IconLabelGroup::handle(int event)
{

    switch(event)
    {
        case FL_PUSH:
            if(Fl::event_inside(this))
            {
                if(cb_)
                {
                    cb_(this, cb_data_);
                } 
                return 1;  
            }
            break;
        case FL_DRAG:
        case FL_RELEASE:
            return 1;  
        default:
            break;
    }

    return Fl_Group::handle(event);
}

