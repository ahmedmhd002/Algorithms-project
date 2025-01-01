#ifndef UTILITY_FUNCTIONS_H
#define UTILITY_FUNCTIONS_H

#include <stdexcept>

// Custom vector implementation to replace std::vector
template<typename T>
class CustomVector {
private:
    T* data;
    int size;
    int capacity;

public:
    CustomVector();
    CustomVector(int size, const T& defaultValue);
    CustomVector(const CustomVector& other);
    CustomVector& operator=(const CustomVector& other);
    ~CustomVector();
    void push_back(const T& value);
    T& operator[](int index);
    const T& operator[](int index) const;
    int getSize() const;
    void clear();
};

// Pair structure to replace std::pair
struct Interval {
    int start;
    int end;
    Interval(int s = 0, int e = 0) : start(s), end(e) {}
};

// Function declarations
void customSort(CustomVector<Interval>& intervals);
CustomVector<Interval> parseInput();
void printResult(int result, bool isGreedy = true);
void swapIntervals(Interval& a, Interval& b);
bool compareIntervals(const Interval& a, const Interval& b);

// Template implementations
template<typename T>
CustomVector<T>::CustomVector() : data(nullptr), size(0), capacity(0) {
    capacity = 1;  // Start with a minimum capacity
    data = new T[capacity];
}

template<typename T>
CustomVector<T>::CustomVector(int size, const T& defaultValue) : size(size), capacity(size) {
    if (size <= 0) {
        size = 0;
        capacity = 1;
    }
    data = new T[capacity];
    for (int i = 0; i < size; ++i) {
        data[i] = defaultValue;
    }
}

template<typename T>
CustomVector<T>::CustomVector(const CustomVector& other) : data(nullptr), size(0), capacity(0) {
    size = other.size;
    capacity = other.capacity;
    data = new T[capacity];
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

template<typename T>
CustomVector<T>& CustomVector<T>::operator=(const CustomVector& other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        capacity = other.capacity;
        data = new T[capacity];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

template<typename T>
CustomVector<T>::~CustomVector() {
    delete[] data;
}

template<typename T>
void CustomVector<T>::push_back(const T& value) {
    if (size >= capacity) {
        int newCapacity = (capacity == 0) ? 1 : capacity * 2;
        T* newData = new T[newCapacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }
    data[size++] = value;
}

template<typename T>
T& CustomVector<T>::operator[](int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[index];
}

template<typename T>
const T& CustomVector<T>::operator[](int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[index];
}

template<typename T>
int CustomVector<T>::getSize() const {
    return size;
}

template<typename T>
void CustomVector<T>::clear() {
    delete[] data;
    data = nullptr;
    size = 0;
    capacity = 0;
}

#endif