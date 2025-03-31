#include <iostream>
#include "Josephus.hpp"

int main()
{
    if (josephus_problem({ 1,2,3,4,5,6,7 }, 3) == 4) {
        std::cout << "test1 - complete" << std::endl;
    }
    else {
        std::cout << "Error on test1!" << std::endl;
    }
    /////////////////////////////////////////////////
    if (josephus_problem({ 1,2,3,4 }, 1) == 4) {
        std::cout << "test2 - complete" << std::endl;
    }
    else {
        std::cout << "Error on test2!" << std::endl;
    }
    /////////////////////////////////////////////////
    if (josephus_problem({ 1,2,3 }, 5) == 1) {
        std::cout << "test3 - complete" << std::endl;
    }
    else {
        std::cout << "Error on test3!" << std::endl;
    }
    /////////////////////////////////////////////////
    if (josephus_problem({ 42 }, 10) == 42) {
        std::cout << "test4 - complete" << std::endl;
    }
    else {
        std::cout << "Error on test4!" << std::endl;
    }
    /////////////////////////////////////////////////
    if (josephus_problem({ 1,2,3,4 }, 2) == 1) {
        std::cout << "test5 - complete" << std::endl;
    }
    else {
        std::cout << "Error on test5!" << std::endl;
    }
    /////////////////////////////////////////////////
    if (josephus_problem({ 1,2,3,4,5 }, 2) == 3) {
        std::cout << "test6 - complete" << std::endl;
    }
    else {
        std::cout << "Error on test6!" << std::endl;
    }
    ////////////////////////////////////////////////
    if (josephus_problem({ 1,2,3,4 }, 4) == 2) {
        std::cout << "test7 - complete" << std::endl;
    }
    else {
        std::cout << "Error on test7!" << std::endl;
    }
    /////////////////////////////////////////////////
    std::vector<int> big_array(1000);
    for (int i = 0; i < 1000; ++i) big_array[i] = i + 1;
    if (josephus_problem(big_array, 7) == 404) {
        std::cout << "test8 - complete" << std::endl;
    }
    else {
        std::cout << "Error on test8!" << std::endl;
    }
    return 0;
}