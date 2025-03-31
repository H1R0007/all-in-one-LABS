#include "timer_manager.hpp"



void EventScheduler::add_event(int time, const std::string& event) {
    if (events.find(time) != events.end()) {
        events[time] = event;
    }
    else {
        events[time] = event;
        time_queue.push(time);
    }
}


std::string EventScheduler::process_next() {
    if (time_queue.empty()) {
        return "";
    }

    int next_time = time_queue.top();

    std::string event = events[next_time];

    time_queue.pop();

    events.erase(next_time);

    return event;
}