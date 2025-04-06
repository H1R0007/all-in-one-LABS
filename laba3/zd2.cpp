#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <iostream>
#include <fstream>


int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    setlocale(LC_ALL, "RUS");
    for (int i = 0; i < 10; ++i) {
        int x = i;
        auto ptr = std::make_unique<int>(x);
        std::cout << "Значение: " << *ptr << " (адрес: " << ptr.get() << ")" << std::endl;;
    }

    std::cout << "Память не утекла!" << std::endl;

    return 0;
}