# Custom Data Structures in C++

This repository contains a collection of custom data structures implemented in C++. These data structures can be useful for various programming tasks, and they include:

1. **Vector**: A dynamic array implementation that can resize itself as needed.
2. **Linked List**: A singly linked list implementation.
3. **Double Linked List**: A doubly linked list implementation.
4. **Circular Linked List**: A circular singly linked list implementation.
5. **Double Circular Linked List**: A circular doubly linked list implementation.
6. **Queue**: A basic queue data structure.
7. **Stack**: A basic stack data structure.
8. **Binary Tree**: An implementation of a binary tree.
9. **Tree**: An implementation of a generic tree.
10. **Graph**: An implementation of a graph data structure.

## Vector

The `Vector` class is a dynamic array that can grow in size as elements are added. It includes the following methods:

```cpp
#include "Vector.h"

int main() {
    // Create a vector of integers
    Vector<int> myVector;

    // Add elements to the vector
    myVector.push_back(10);
    myVector.push_back(20);
    myVector.push_back(30);

    // Access elements by index
    int element = myVector.at(1); // element = 20

    // Get the number of elements and capacity
    size_t size = myVector.size(); // size = 3
    size_t capacity = myVector.capacity(); // capacity = 4 (initial capacity is 2)

    // Remove the last element
    myVector.pop_back(); // Vector contains [10, 20] after this operation

    // Check if the vector is empty
    bool isEmpty = myVector.empty(); // isEmpty = false

    // Clear the vector and free memory
    myVector.clear();

    return 0;
}
```
## Linked List

The `LinkedList` class is a singly linked list with methods for manipulation:

```cpp
#include "LinkedList.h"

int main() {
    // Create a linked list of integers
    LinkedList<int> myList;

    // Add elements to the linked list
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);

    // Access elements by index
    int element = myList.at(1); // element = 20

    // Get the number of elements
    size_t count = myList.count(); // count = 3

    // Remove the last element
    myList.pop_back(); // Linked list contains [10, 20] after this operation

    // Check if the linked list is empty
    bool isEmpty = myList.empty(); // isEmpty = false

    // Clear the linked list and free memory
    myList.clear();

    return 0;
}
```
