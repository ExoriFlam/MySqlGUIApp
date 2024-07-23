#include "AddDbButton.h"

AddDbButton::AddDbButton(int x, int y, int w, int h, const char* l):
	Fl_Button(x, y, w, h, l), img {nullptr} {}

void AddDbButton::set_image(const char* file_name)
{
	img = std::make_unique<Fl_PNG_Image>(file_name);

	if(img->fail())
	{
		return;
	}
	this->image(img->copy(25,25));
}

AddDbButton::~AddDbButton() {
	
    this->image(nullptr);
    img.reset();
}