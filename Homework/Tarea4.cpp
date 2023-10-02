#include "Tarea4.h"
#include "../DoubleLinkedList.hpp"
#include "../CircularLinkedList.hpp"
#include "../DoubleCircularLinkedList.hpp"

void tarea4(){
  int arr[] = {10, 20, 30, 0, 0, 0, 40, 50, 60};
  int arraySize = sizeof(arr) / sizeof(arr[0]);
  DoubleLinkedList<int> doubleList(arr, arraySize);
  std::cout << "Double Linked list is empty? " << doubleList.empty() << "\n";
  std::cout << "Double Linked list data:" << "\n";
  for (int i = 0; i < doubleList.count(); i++) {
    std::cout << doubleList.at(i) << "\n";
  }
  doubleList.push_front(0);
  std::cout << "Double Linked list data after push front:" << "\n";
  for (int i = 0; i < doubleList.count(); i++) {
    std::cout << doubleList.at(i) << "\n";
  }
  doubleList.pop_front();
  std::cout << "Double Linked list data after pop front:" << "\n";
  for (int i = 0; i < doubleList.count(); i++) {
    std::cout << doubleList.at(i) << "\n";
  }
  doubleList.pop_back(); 
  std::cout << "Double Linked list data after pop back:" << "\n";
  for (int i = 0; i < doubleList.count(); i++) {
    std::cout << doubleList.at(i) << "\n";
  }
  doubleList.insert(100, 3);
  std::cout << "Double Linked list data after insert:" << "\n";
  for (int i = 0; i < doubleList.count(); i++) {
    std::cout << doubleList.at(i) << "\n";
  }
  doubleList.erase(3);
  std::cout << "Double Linked list data after erase:" << "\n";
  for (int i = 0; i < doubleList.count(); i++) {
    std::cout << doubleList.at(i) << "\n";
  }
  doubleList.eraseAll(0);  
  std::cout << "Double Linked list data after erase all:" << "\n";
  for (int i = 0; i < doubleList.count(); i++) {
    std::cout << doubleList.at(i) << "\n";
  }
  doubleList.clear();
  doubleList.insertOrdered(0);
  doubleList.insertOrdered(5);
  doubleList.insertOrdered(-5);
  doubleList.insertOrdered(3);
  doubleList.insertOrdered(-2);
  doubleList.insertOrdered(-1);
  doubleList.insertOrdered(4);
  std::cout << "Double Linked list data after insert Ordered:" << "\n";
  for (int i = 0; i < doubleList.count(); i++) {
    std::cout << doubleList.at(i) << "\n";
  }
  CircularLinkedList<int> circularList(arr, arraySize);
  std::cout << "Circular Linked list is empty? " << circularList.empty() << "\n";
  std::cout << "Circular Linked list data:" << "\n";
  for (int i = 0; i < circularList.count(); i++) {
    std::cout << circularList.at(i) << "\n";
  }
  circularList.push_front(89);
  std::cout << "Circular Linked list data after push front:" << "\n";
  for (int i = 0; i < circularList.count(); i++) {
    std::cout << circularList.at(i) << "\n";
  }
  circularList.pop_front();
  std::cout << "Circular Linked list data after pop front:" << "\n";
  for (int i = 0; i < circularList.count(); i++) {
    std::cout << circularList.at(i) << "\n";
  }
  circularList.pop_back();
  std::cout << "Circular Linked list data after pop back:" << "\n";
  for (int i = 0; i < circularList.count(); i++) {
    std::cout << circularList.at(i) << "\n";
  }
  circularList.insert(666, 3);
  std::cout << "Circular Linked list data after insert:" << "\n";
  for (int i = 0; i < circularList.count(); i++) {
    std::cout << circularList.at(i) << "\n";
  }
  circularList.erase(3);
  std::cout << "Circular Linked list data after erase:" << "\n";
  for (int i = 0; i < circularList.count(); i++) {
    std::cout << circularList.at(i) << "\n";
  }
  circularList.eraseAll(0);
  std::cout << "Circular Linked list data after erase all:" << "\n";
  for (int i = 0; i < circularList.count(); i++) {
    std::cout << circularList.at(i) << "\n";
  }
  DoubleCircularLinkedList<int> doubleCircularList(arr, arraySize);
  std::cout << "Double Circular Linked list is empty? " << doubleCircularList.empty() << "\n";
  std::cout << "Double Circular Linked list data:" << "\n";
  for (int i = 0; i < doubleCircularList.count(); i++) {
    std::cout << doubleCircularList.at(i) << "\n";
  }
  doubleCircularList.push_front(69);
  std::cout << "Double Circular Linked list data after push front:" << "\n";
  for (int i = 0; i < doubleCircularList.count(); i++) {
    std::cout << doubleCircularList.at(i) << "\n";
  }
  doubleCircularList.pop_front();
  std::cout << "Double Circular Linked list data after pop front:" << "\n";
  for (int i = 0; i < doubleCircularList.count(); i++) {
    std::cout << doubleCircularList.at(i) << "\n";
  }
  doubleCircularList.pop_back();
  std::cout << "Double Circular Linked list data after pop back:" << "\n";
  for (int i = 0; i < doubleCircularList.count(); i++) {
    std::cout << doubleCircularList.at(i) << "\n";
  }
  doubleCircularList.insert(666, 3);
  std::cout << "Double Linked list data after insert:" << "\n";
  for (int i = 0; i < doubleCircularList.count(); i++) {
    std::cout << doubleCircularList.at(i) << "\n";
  }
  doubleCircularList.erase(3);
  std::cout << "Double Linked list data after erase:" << "\n";
  for (int i = 0; i < doubleCircularList.count(); i++) {
    std::cout << doubleCircularList.at(i) << "\n";
  }
  doubleCircularList.eraseAll(0);
  std::cout << "Double Linked list data after erase all:" << "\n";
  for (int i = 0; i < doubleCircularList.count(); i++) {
    std::cout << doubleCircularList.at(i) << "\n";
  }
}