#ifndef EVENTSYSTEM_H
#define EVENTSYSTEM_H

#include <functional>
#include <map>
#include <vector>
#include <string>
#include <FL/Fl_Widget.H>

class EventSystem {
public:
    

    void subscribe(const std::string& event_name, std::function<void(Fl_Widget*)> callback);

    void trigger(const std::string& event_name, Fl_Widget* data );

private:
    std::map<std::string, std::vector<std::function<void(Fl_Widget*)>>> listeners;
};

#endif