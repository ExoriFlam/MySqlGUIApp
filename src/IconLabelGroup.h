#ifndef ICONLABELGROUP_H
#define ICONLABELGROUP_H
#include <string>
#include <FL/Fl_Group.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_PNG_Image.H>
#include <memory>
#include <string>

class IconLabelGroup : public Fl_Group {
public:
    IconLabelGroup(int x, int y, int w, int h, const std::string& img_path, const std::string& label);

    void callback(Fl_Callback* cb, void* data);
    std::string get_label();

    std::string get_row_data();
    void set_row_data(const std::string& r_data);
protected:
	int handle(int event) override;

private:
    Fl_PNG_Image icon;
    Fl_Box image_box;
    Fl_Box label_box;
    std::string row_data;
    Fl_Callback* cb_;
    void* cb_data_;
};


#endif