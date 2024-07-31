#ifndef ICONLABELGROUP_H
#define ICONLABELGROUP_H
#include <string>
#include <FL/Fl_Group.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_PNG_Image.H>
#include <memory>

class IconLabelGroup : public Fl_Group {
public:
    IconLabelGroup(int x, int y, int w, int h, const std::string& img_path, const std::string& label);

    void callback(Fl_Callback* cb, void* data);

protected:
	int handle(int event) override;

private:
    Fl_PNG_Image icon;
    Fl_Box image_box;
    Fl_Box label_box;
    Fl_Callback* cb_;
    void* cb_data_;
};


#endif