#ifndef ICONBTN_H
#define ICONBTN_H

#include <FL/Fl_Button.H>
#include <FL/Fl_PNG_Image.H>
#include <memory>


class IconButton : public Fl_Button
{
public:

	IconButton(int x, int y, int w, int h, const char* l = 0);

	void set_icon(const char* png_file_name);

private:
	
	std::unique_ptr<Fl_PNG_Image> img;
};


#endif