# native-vector

a custom C++ dynamic array implementation exploring low level memory management and move semantics.

---

## Features
  - Dynamic resizing (capacity doubling)
  - Contiguous memory storage
  - Copy constructor and copy assignment
  - Move constructor and move assignment
  - Index based access (operator[])
  - Bounds checked access (at)
  - Size and capacity tracking

---

## Project Structure
```
native-vector/
  └─ src
      ├─ main.cpp
      └─ vector.cpp
```

### vector.hpp
  - Contains the full implementation of the Vector class
  - Handles memory management, resizing, and element storage
  - Implements the Rule of 5 (copy/move semantics)

### main.cpp
  - Entry point for testing the vector
  - Demonstrates usage of the container
  - Verifies behavior like resizing and copying

---

## How It Works

### 1. Internal Structure

The vector maintains:
  - data -> pointer to allocated memory
  - size -> number of elements stored
  - capacity -> total allocated space   

   
### 2. Dynamic Resizing

When the vector runs out of space:
  1. A new block of memory is allocated (usually double the capacity)
  2. Existing elements are copied to the new block
  3. Old memory is freed

### 3. Copy vs Move
  - Copy operations duplicate the data
  - Move operations transfer ownership without copying

**This significantly improves performance for temporary objects.**

---

## Build & Run

### Build

Make sure you have a C++ compiler installed (GCC/Clang).

Compile the project:
```
g++ main.cpp -o vector
```

### Run
```
./vector
```

### USage Example
```
Vector<int> v;

for (int i = 0; i < 10; i++) {
    v.push_back(i);
}

for (size_t i = 0; i < v.get_size(); i++) {
    std::cout << v[i] << " ";
}
```
