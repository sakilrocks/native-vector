
#include <iostream>
#include "vector.hpp"

int main() {
    Vector<int> v;

    // Add elements
    for (int i = 0; i < 10; i++) {
        v.push_back(i * 2);
    }

    // Print elements
    std::cout << "elements: ";
    for (size_t i = 0; i < v.get_size(); i++) {
        std::cout << v[i] << " ";
    }

    std::cout << "\nsize: " << v.get_size();
    std::cout << "\ncapacity: " << v.get_capacity() << "\n";

    // Test copy
    Vector<int> v2 = v;

    std::cout << "copied vector: ";
    for (size_t i = 0; i < v2.get_size(); i++) {
        std::cout << v2[i] << " ";
    }

    std::cout << std::endl;

    return 0;

}