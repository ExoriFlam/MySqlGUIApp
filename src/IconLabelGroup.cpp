#include "IconLabelGroup.h"

IconLabelGroup::IconLabelGroup(int x, int y, int w, int h, const char* img_path, const char* label)
    : Fl_Group(x, y, w, h), icon(nullptr), image_box(nullptr), label_box(nullptr)
{
    icon = std::make_unique<Fl_PNG_Image>(img_path);

    image_box = std::make_unique<Fl_Box>(x, y, 20, 30);
    image_box->image(icon.get()->copy(15,15));
    image_box->box(FL_NO_BOX);

    label_box = std::make_unique<Fl_Box>(x + 20, y, w - 35, 30, label);
    label_box->box(FL_NO_BOX);
    label_box->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
    label_box->color(FL_BLUE);

    end();
}