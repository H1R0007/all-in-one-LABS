#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <iostream>

int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    setlocale(LC_ALL, "RUS");
    for (int i = 0; i < 10; ++i) {
        int x = i;
        int* do_not_del = new int(x);
        std::cout << "Утечка: " << *do_not_del << " (адрес: " << do_not_del << ")" << std::endl;
        //delete do_not_del;
    }

    std::cout << "Память утекла!" << std::endl;
    return 0;
}