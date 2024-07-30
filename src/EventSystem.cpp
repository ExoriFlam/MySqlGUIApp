#include "EventSystem.h"

void EventSystem::subscribe(const std::string& event_name, std::function<void(Fl_Widget*)> callback)
{
	listeners[event_name].push_back(callback);
}

void EventSystem::trigger(const std::string& event_name, Fl_Widget* data = nullptr)
{
	auto it = listeners.find(event_name);
	if (it != listeners.end())
	{
	    for (auto& callback : it->second)
	    {
	        callback(data);
	    }
	}
}