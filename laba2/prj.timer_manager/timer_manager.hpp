#include <string>
#include <queue>
#include <map>


class EventScheduler {
    std::map<int, std::string> events;
    std::priority_queue<int, std::vector<int>, std::greater<>> time_queue;

public:
    void add_event(int time, const std::string& event);
    std::string process_next();
};