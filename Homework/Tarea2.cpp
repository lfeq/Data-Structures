#include "Tarea2.h"
#include "../LinkedList.hpp"

void Tarea2() {
  int arr[] = {10, 20, 30, 0, 0, 0, 40, 50, 60};
  int arraySize = sizeof(arr) / sizeof(arr[0]);
  LinkedList<int> list(arr, arraySize);
  std::cout << "Linked list is empty? " << list.empty() << "\n";
  std::cout << "Linked list data:" << "\n";
  for (int i = 0; i < list.count(); i++) {
    std::cout << list.at(i) << "\n";
  }
  list.push_front(0);
  std::cout << "Linked list data after push front:" << "\n";
  for (int i = 0; i < list.count(); i++) {
    std::cout << list.at(i) << "\n";
  }
  list.pop_front();
  std::cout << "Linked list data after pop front:" << "\n";
  for (int i = 0; i < list.count(); i++) {
    std::cout << list.at(i) << "\n";
  }
  list.pop_back(); 
  std::cout << "Linked list data after pop back:" << "\n";
  for (int i = 0; i < list.count(); i++) {
    std::cout << list.at(i) << "\n";
  }
  list.insert(100, 3);
  std::cout << "Linked list data after insert:" << "\n";
  for (int i = 0; i < list.count(); i++) {
    std::cout << list.at(i) << "\n";
  }
  list.erase(3);
  std::cout << "Linked list data after erase:" << "\n";
  for (int i = 0; i < list.count(); i++) {
    std::cout << list.at(i) << "\n";
  }
  list.eraseAll(0);  
  std::cout << "Linked list data after erase all:" << "\n";
  for (int i = 0; i < list.count(); i++) {
    std::cout << list.at(i) << "\n";
  }
  list.clear();
  std::cout << "Linked list is empty? " << list.empty() << "\n";
}
