#include <FL/Fl.H>
#include "MainWindow.h"
#define DEBUG

#include <iostream>

int main(int argc, char **argv) {

    

    MainWindow window(50, 50, 1920, 1080, "MySqlGUI");
    
    //Fl::visual(FL_DOUBLE | FL_INDEX);

    window.resizable(&window);

    window.show(argc, argv);
   

    return Fl::run();
}