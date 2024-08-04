#include "IconButton.h"
#include <iostream>

IconButton::IconButton(int x, int y, int w, int h, const char* l):
	Fl_Button(x, y, w, h, l) {}


void IconButton::set_icon(const std::string& png_file_name)
{
	int btn_w = this->w();
	int btn_h = this->h();

	std::unique_ptr<Fl_PNG_Image> img = std::make_unique<Fl_PNG_Image>(png_file_name.c_str());
    img_copy = std::unique_ptr<Fl_Image>(img->copy(btn_w-5 ,btn_h-5));// copy return Fl_Image*
	
	this->image(img_copy.get());
	
}