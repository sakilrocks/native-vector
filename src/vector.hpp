
#pragma once

#include <cstddef>
#include <stdexcept>

template<typename T>
class Vector {
private:
    T* data;
    size_t size;
    size_t capacity;

    void reallocate(size_t new_capacity) {
        T* new_data = new T[new_capacity];

        for (size_t i = 0; i < size; i++) {
            new_data[i] = data[i];
        }

        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

public:

    // constructor
    Vector() : data(nullptr), size(0), capacity(0) {}

    // destructor
    ~Vector() {
        delete[] data;
    }

    // copy Constructor
    Vector(const Vector& other) {
        size = other.size;
        capacity = other.capacity;
        data = new T[capacity];

        for (size_t i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    // move constructor
    Vector(Vector&& other) noexcept {
        data = other.data;
        size = other.size;
        capacity = other.capacity;

        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }

    // copy assignment
    Vector& operator=(const Vector& other) {
        if (this == &other) return *this;

        delete[] data;

        size = other.size;
        capacity = other.capacity;
        data = new T[capacity];

        for (size_t i = 0; i < size; i++) {
            data[i] = other.data[i];
        }

        return *this;
    }

    // move assignment
    Vector& operator=(Vector&& other) noexcept {
        if (this == &other) return *this;

        delete[] data;

        data = other.data;
        size = other.size;
        capacity = other.capacity;

        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;

        return *this;
    }

    // push back
    void push_back(const T& value) {
        if (size == capacity) {
            size_t new_capacity = (capacity == 0) ? 1 : capacity * 2;
            reallocate(new_capacity);
        }

        data[size++] = value;
    }

    // access operator
    T& operator[](size_t index) {
        return data[index];
    }

    const T& operator[](size_t index) const {
        return data[index];
    }

    // safe access
    T& at(size_t index) {
        if (index >= size) throw std::out_of_range("Index out of range");
        return data[index];
    }

    // getters
    size_t get_size() const {
        return size;
    }

    size_t get_capacity() const {
        return capacity;
    }

};