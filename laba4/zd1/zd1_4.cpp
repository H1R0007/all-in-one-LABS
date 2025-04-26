#include "MyVector.hpp"
#include <chrono>

template<typename Func>
double measureTime(Func f) {
    auto start = std::chrono::high_resolution_clock::now();
    f();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    return diff.count();
}

int main() {
    const size_t LARGE_SIZE = 10000000;

    double copyTime = measureTime([&]() {
        MyVector original(LARGE_SIZE);
        original.fill(1);
        MyVector copy = original; // Вызов конструктора копирования
        });

    std::cout << "Copy constructor time: " << copyTime << " seconds\n";

    double moveTime = measureTime([&]() {
        MyVector original(LARGE_SIZE);
        original.fill(1);
        MyVector moved = std::move(original); // Вызов move конструктора
        });

    std::cout << "Move constructor time: " << moveTime << " seconds\n";

    double copyAssignTime = measureTime([&]() {
        MyVector original(LARGE_SIZE);
        original.fill(1);
        MyVector copyAssigned;
        copyAssigned = original; // Вызов копирующего оператора присваивания
        });

    std::cout << "Copy operator= time: " << copyAssignTime << " seconds\n";

    double moveAssignTime = measureTime([&]() {
        MyVector original(LARGE_SIZE);
        original.fill(1);
        MyVector moveAssigned;
        moveAssigned = std::move(original); // Вызов move оператора присваивания
        });

    std::cout << "Move operator= time: " << moveAssignTime << " seconds\n";

    return 0;
}