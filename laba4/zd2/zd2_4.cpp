#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <sstream>
#include <map>

template<typename T>
void mySwap(T& a, T& b) {
    T temp = std::move(a);
    a = std::move(b);
    b = std::move(temp);
}

template<typename Container>
std::string containerToString(const Container& cont) {
    std::ostringstream oss;
    oss << "[";
    bool first = true;
    for (const auto& elem : cont) {
        if (!first) {
            oss << ", ";
        }
        oss << elem;
        first = false;
    }
    oss << "]";
    return oss.str();
}

template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& p) {
    return os << "{" << p.first << ": " << p.second << "}";
}

int main() {
    // Тест с целыми числами
    int x = 5, y = 10;
    std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
    mySwap(x, y);
    std::cout << "After swap: x = " << x << ", y = " << y << std::endl;

    // Тест со строками
    std::string s1 = "Hello", s2 = "World";
    std::cout << "Before swap: s1 = " << s1 << ", s2 = " << s2 << std::endl;
    mySwap(s1, s2);
    std::cout << "After swap: s1 = " << s1 << ", s2 = " << s2 << std::endl;

    // Тест с числами с плавающей точкой
    double d1 = 3.14, d2 = 2.71;
    std::cout << "Before swap: d1 = " << d1 << ", d2 = " << d2 << std::endl;
    mySwap(d1, d2);
    std::cout << "After swap: d1 = " << d1 << ", d2 = " << d2 << std::endl;

    // Тест с vector<int>
    std::vector<int> vec = { 1, 2, 3, 4, 5 };
    std::cout << "Vector: " << containerToString(vec) << std::endl;

    // Тест с list<string>
    std::list<std::string> lst = { "apple", "banana", "cherry" };
    std::cout << "List: " << containerToString(lst) << std::endl;

    // Тест с set<double>
    std::set<double> st = { 3.14, 2.71, 1.41 };
    std::cout << "Set: " << containerToString(st) << std::endl;

    //Тест с map<int, string>
    std::map<int, std::string> mp = { {1, "one"}, {2, "two"}, {3, "three"} };
    std::cout << "Map: " << containerToString(mp) << std::endl;

    return 0;
}