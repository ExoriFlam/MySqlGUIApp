#ifndef ICONLABELGROUP_H
#define ICONLABELGROUP_H

#include <FL/Fl_Group.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_PNG_Image.H>
#include <memory>

class IconLabelGroup : public Fl_Group {
public:
    IconLabelGroup(int x, int y, int w, int h, const char* img_path, const char* label);
private:
    std::unique_ptr<Fl_PNG_Image> icon;
    std::unique_ptr<Fl_Box> image_box;
    std::unique_ptr<Fl_Box> label_box;
};


#endif