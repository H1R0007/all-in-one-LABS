#include "MyArray.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <cassert>

void TestDefaultConstructor() {
    ArrayT<int> arr;
    assert(arr.Size() == 0);
    assert(arr.Capacity() == 0);
    std::cout << "TestDefaultConstructor passed\n";
}

void TestSizeConstructor() {
    ArrayT<int> arr(5);
    assert(arr.Size() == 5);
    assert(arr.Capacity() == 5);

    try {
        ArrayT<int> invalid(-1);
        assert(false && "Expected exception not thrown");
    }
    catch (const std::invalid_argument&) {
        std::cout << "TestSizeConstructor passed\n";
    }
}

void TestCopyConstructor() {
    ArrayT<int> src(3);
    src[0] = 1; src[1] = 2; src[2] = 3;

    ArrayT<int> copy(src);
    assert(copy.Size() == 3);
    assert(copy[0] == 1 && copy[1] == 2 && copy[2] == 3);
    std::cout << "TestCopyConstructor passed\n";
}

void TestAssignmentOperator() {
    ArrayT<std::string> arr1(2);
    arr1[0] = "hello"; arr1[1] = "world";

    ArrayT<std::string> arr2;
    arr2 = arr1;

    assert(arr2.Size() == 2);
    assert(arr2[0] == "hello" && arr2[1] == "world");
    std::cout << "TestAssignmentOperator passed\n";
}

void TestAccessOperator() {
    ArrayT<double> arr(3);
    arr[0] = 1.1; arr[1] = 2.2; arr[2] = 3.3;

    assert(arr[0] == 1.1 && arr[1] == 2.2 && arr[2] == 3.3);

    try {
        double val = arr[-1];
        assert(false && "Expected exception not thrown");
    }
    catch (const std::invalid_argument&) {}

    try {
        double val = arr[3];
        assert(false && "Expected exception not thrown");
    }
    catch (const std::invalid_argument&) {
        std::cout << "TestAccessOperator passed\n";
    }
}

void TestResize() {
    ArrayT<int> arr(2);
    arr[0] = 10; arr[1] = 20;

    // Уменьшение размера
    arr.Resize(1);
    assert(arr.Size() == 1 && arr[0] == 10);

    // Увеличение размера
    arr.Resize(3);
    assert(arr.Size() == 3 && arr[0] == 10);

    // Отрицательный размер
    try {
        arr.Resize(-1);
        assert(false && "Expected exception not thrown");
    }
    catch (const std::invalid_argument&) {
        std::cout << "TestResize passed\n";
    }
}

void TestInsert() {
    ArrayT<char> arr(3);
    arr[0] = 'a'; arr[1] = 'c'; arr[2] = 'd';

    // Вставка в середину
    arr.Insert(1, 'b');
    assert(arr.Size() == 4);
    assert(arr[0] == 'a' && arr[1] == 'b');
    assert(arr[2] == 'c' && arr[3] == 'd');

    // Вставка в начало
    arr.Insert(0, 'x');
    assert(arr.Size() == 5 && arr[0] == 'x');

    // Вставка в конец
    arr.Insert(5, 'z');
    assert(arr.Size() == 6 && arr[5] == 'z');

    // Неверный индекс
    try {
        arr.Insert(-1, 'x');
        assert(false && "Expected exception not thrown");
    }
    catch (const std::invalid_argument&) {}

    try {
        arr.Insert(7, 'x');
        assert(false && "Expected exception not thrown");
    }
    catch (const std::invalid_argument&) {
        std::cout << "TestInsert passed\n";
    }
}

void TestRemove() {
    ArrayT<int> arr(4);
    arr[0] = 1; arr[1] = 2; arr[2] = 3; arr[3] = 4;

    // Удаление из середины
    arr.Remove(1);
    assert(arr.Size() == 3);
    assert(arr[0] == 1 && arr[1] == 3 && arr[2] == 4);

    // Удаление первого элемента
    arr.Remove(0);
    assert(arr.Size() == 2 && arr[0] == 3);

    // Удаление последнего элемента
    arr.Remove(1);
    assert(arr.Size() == 1 && arr[0] == 3);

    // Неверный индекс
    try {
        arr.Remove(-1);
        assert(false && "Expected exception not thrown");
    }
    catch (const std::invalid_argument&) {}

    try {
        arr.Remove(1);
        assert(false && "Expected exception not thrown");
    }
    catch (const std::invalid_argument&) {
        std::cout << "TestRemove passed\n";
    }
}

void TestComplexTypes() {
    ArrayT<std::vector<int>> arr(2);
    arr[0] = { 1, 2, 3 };
    arr[1] = { 4, 5 };

    assert(arr.Size() == 2);
    assert(arr[0].size() == 3 && arr[1].size() == 2);
    std::cout << "TestComplexTypes passed\n";
}

int main() {
    TestDefaultConstructor();
    TestSizeConstructor();
    TestCopyConstructor();
    TestAssignmentOperator();
    TestAccessOperator();
    TestResize();
    TestInsert();
    TestRemove();
    TestComplexTypes();

    std::cout << "All tests passed successfully!\n";
    return 0;
}