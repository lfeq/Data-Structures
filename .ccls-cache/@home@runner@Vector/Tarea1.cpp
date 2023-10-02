#include "Tarea1.h"
#include "Vector.hpp"

template <class T, class R> 
inline void compare(const T& a, const R& b) {
  return a > b;
}

void example(int* a){
  a++;
  std::cout << a << "\n";
}

void test(){
  std::cout << "Hello World!\n";
  /*int i = 6;
  int* ptr;
  //std::cout << compare<int, int>(2, 5) << "\n";
  std::cout << i << "\n";
  std::cout << &i << "\n";
  std::cout << ptr << "\n";
  ptr = &i;
  std::cout << ptr << "\n";
  std::cout << *ptr << "\n";
  ptr = new int(9);
  std::cout << *ptr << "\n";
  ptr = new int[3];
  std::cout << *ptr << "\n";
  int arr[3] = {5, 10, 7};
  std::cout << arr << "\n";
  std::cout << arr[0] << "\n";
  std::cout << *(arr + 1) << "\n";*/
  int pepito = 5;
  std::cout << pepito << "\n";
  int* ptr = nullptr;
  std::cout << ptr << "\n";
  example(ptr);
  std::cout << pepito << "\n";
}

void tarea1(){
  int arr[] = {10,20,30,40,50,60};
  int arraySize = sizeof(arr) / sizeof(arr[0]);
  Vector<int> v1(arr, arraySize);
  std::cout << "Vector data:" << "\n";
  v1.push_back(23);
  for(size_t i = 0; i < v1.size(); i++){
    std::cout << v1.at(i) << "\n";
  }
  std::cout << "Vector is empty? " << v1.empty() << "\n";
  std::cout << "Capacity size: " << v1.capacity() << "\n";
  v1.reserve(16);
  std::cout << "New capacity size after reserve: " << v1.capacity() << "\n";
  v1.shrink_to_fit();
  std::cout << "New new capacity size after shrink_to_fit: " << v1.capacity() << "\n";
  std::cout << "First value in vector: " << v1.front() << "\n";
  std::cout << "Last value in vector: " << v1.back() << "\n";
  int* arrayCopy = v1.data();
  std::cout << "Array copy data:" << "\n";
  for(size_t i = 0; i < v1.size(); i++){
    std::cout << *(arrayCopy + i) << "\n";
  }
  v1.pop_back();
  std::cout << "Vector data after pop_back:" << "\n";
  for(size_t i = 0; i < v1.size(); i++){
    std::cout << v1.at(i) << "\n";
  }
  v1.clear();
  std::cout << "Vector data after clear:" << "\n";
  for(size_t i = 0; i < v1.size(); i++){
    std::cout << v1.at(i) << "\n";
  }
}

void test2(){
  Vector<int> v1;
  try{
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(6);
    v1.shrink_to_fit();
    v1.pop_back();
    std::cout << "capacity " << v1.capacity() << "\n";
    for(size_t i = 0; i < v1.size(); i++){
      std::cout << v1.at(i) << "\n";
    }
  }catch(std::out_of_range e){
    std::cout << e.what() << "\n";
  }
  catch(...){
    
  }
}