#include <iostream>
#include <algorithm> 

class MyVector {
private:
    int* data;
    size_t size;

public:
    explicit MyVector(size_t size = 0) : size(size), data(size ? new int[size] : nullptr) {
        std::cout << "constructor for size " << size << std::endl;
    }

    ~MyVector() {
        delete[] data;
    }

    MyVector(const MyVector& other) : size(other.size), data(size ? new int[size] : nullptr) {
        std::cout << "Copy constructor for size " << size << std::endl;
        std::copy(other.data, other.data + size, data);
    }

    MyVector& operator=(const MyVector& other) {
        std::cout << "Copy operator= for size " << other.size << std::endl;
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = size ? new int[size] : nullptr;
            std::copy(other.data, other.data + size, data);
        }
        return *this;
    }

    MyVector(MyVector&& other) noexcept : data(other.data), size(other.size) {
        std::cout << "Move constructor for size " << size << std::endl;
        other.data = nullptr;
        other.size = 0;
    }

    MyVector& operator=(MyVector&& other) noexcept {
        std::cout << "Move operator= for size " << other.size << std::endl;
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }

    void fill(int value) {
        for (size_t i = 0; i < size; ++i) {
            data[i] = value;
        }
    }

    size_t GetSize() const { 
        return size; 
    }
};