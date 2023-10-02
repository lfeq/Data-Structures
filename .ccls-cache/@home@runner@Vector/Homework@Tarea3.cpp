#include "Tarea3.h"
#include "../Queue.hpp"
#include "../Stack.hpp"

void tarea3(){
  int arr[] = {50, 20, 60, 10, 60, 70, 40, 80, 30};
  int arraySize = sizeof(arr) / sizeof(arr[0]);
  Queue<int> fila(arr, arraySize);
  std::cout << "Queue is empty? " << fila.empty() << "\n";
  std::cout << "Queue data:" << "\n";
  for (int i = 0; i < fila.count(); i++) {
    int data = fila.pop_front();
    std::cout << data << "\n";
    fila.push_back(data);
  }
  fila.push_back(90);
  std::cout << "Queue data after push back:" << "\n";
  for (int i = 0; i < fila.count(); i++) {
    int data = fila.pop_front();
    std::cout << data << "\n";
    fila.push_back(data);
  }
  LinkedList<int> list = fila.sort();
  std::cout << "Sorted queue data:" << "\n";
  for (int i = 0; i < list.count(); i++) {
    std::cout << list.at(i) << "\n";
  }
  Stack<int> stack(arr, arraySize);
  std::cout << "Stack is empty? " << stack.empty() << "\n";
  std::cout << "Stack data: " << "\n";
  int stackSize = stack.count();
  int resetArray[stackSize];
  for (int i = stackSize - 1; i >= 0; i--) {
    int data = stack.pop_front();
    std::cout << data << "\n";
    resetArray[i] = data;
  }
  for(int i = 0; i < arraySize; i++){
    stack.push_front(resetArray[i]);
  }
  stack.push_front(56);
  std::cout << "Stack data after push back: " << "\n";
  stackSize = stack.count();
  int resetArray2[stackSize];
  for (int i = stackSize - 1; i >= 0; i--) {
    int data = stack.pop_front();
    std::cout << data << "\n";
    resetArray2[i] = data;
  }
  for(int i = 0; i <= arraySize; i++){
    stack.push_front(resetArray2[i]);
  }  
  LinkedList<int> sortedStack = stack.sort();
  std::cout << "Sorted stack data:" << "\n";
  for (int i = 0; i < sortedStack.count(); i++) {
    std::cout << sortedStack.at(i) << "\n";
  }
}