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

    std::string get_action_name();
    void set_action_name(const std::string& a_name);

    std::string get_data_type();
    void set_data_type(const std::string& d_type);

    std::string get_data_value();
    void set_data_value(const std::string& d_val);

protected:
	int handle(int event) override;

private:
	
    std::unique_ptr<Fl_Image> icon_copy;
    Fl_Box image_box;
    Fl_Box label_box;
    std::string action_name;
    std::string data_type;
    std::string data_value;
    Fl_Callback* cb_;
    void* cb_data_;
};


#endif