#include "IconButton.h"
#include <iostream>

IconButton::IconButton(int x, int y, int w, int h, const char* l):
	Fl_Button(x, y, w, h, l), img(nullptr) {}


void IconButton::set_icon(const char* png_file_name)
{
	img = std::make_unique<Fl_PNG_Image>(png_file_name);
	int btn_w = this->w();
	int btn_h = this->h();

	if(img->w() > 0 && img->h() > 0)
	{
		this->image(img->copy(btn_w-5 ,btn_h-5));
	}
	else
	{
		this->image(nullptr);

		#ifdef DEBUG
		std::cout << "error loading button image";
		#endif
	}
	
}