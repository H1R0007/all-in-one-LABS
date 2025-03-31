#include "timer_manager.hpp"
#include <iostream>

int main()
{
    EventScheduler es;
    es.add_event(5, "Backup");
    es.add_event(2, "Update");
    es.add_event(10, "Restart");

    if (es.process_next() == "Update" && es.process_next() == "Backup" && es.process_next() == "Restart") {
        std::cout << "test1 - complete successfull" << std::endl;
    }
    else {
        std::cout << "Error!" << std::endl;
    }

    EventScheduler es1;
    es1.add_event(5, "Backup");
    es1.add_event(5, "Update"); // Перезапись

    if (es1.process_next() == "Update") {
        std::cout << "test2 - complete successfull" << std::endl;
    }
    else {
        std::cout << "Error!" << std::endl;
    }

    return 0;
}

