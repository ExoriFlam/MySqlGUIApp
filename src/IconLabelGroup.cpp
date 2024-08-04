#include "IconLabelGroup.h"
#include <iostream>
IconLabelGroup::IconLabelGroup(int x, int y, int w, int h, const std::string& img_path, const std::string& label)
    : Fl_Group(x, y, w, h), image_box(0, 0, 0, 0), label_box(0, 0, 0, 0) , cb_(nullptr), cb_data_(nullptr)
{
    std::unique_ptr<Fl_PNG_Image> img = std::make_unique<Fl_PNG_Image>(img_path.c_str());
    icon_copy = std::unique_ptr<Fl_Image>(img->copy(15, 15));// copy return Fl_Image* with new mem

    image_box.resize(x, y, 20, 30);
    image_box.image(icon_copy.get());
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

std::string IconLabelGroup::get_action_name()
{
    return action_name;
}
void IconLabelGroup::set_action_name(const std::string& a_name)
{
    action_name = a_name;
}

std::string IconLabelGroup::get_data_type()
{
    return data_type;
}
void IconLabelGroup::set_data_type(const std::string& d_type)
{
    data_type = d_type;
}

std::string IconLabelGroup::get_data_value()
{
    return data_value;
}
void IconLabelGroup::set_data_value(const std::string& d_val)
{
    data_value = d_val;
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

