#ifndef ADDDBBTN_H
#define ADDDBBTN_H
#include <FL/Fl_Button.H>
#include <FL/Fl_PNG_Image.H>
#include <memory>


class AddDbButton : public Fl_Button
{
public:

	AddDbButton(int x, int y, int w, int h, const char* l = 0);

	void set_image(const char* file_name);
	~AddDbButton();
private:
	
	std::unique_ptr <Fl_PNG_Image> img;
};


#endif