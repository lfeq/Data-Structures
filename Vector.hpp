#pragma once
#include <iostream>
using std::size_t;

/**
  * @brief A template data structure that handles
  * a dynamic array.
*/
template <class T>
class Vector{
  private :
    T* m_data = nullptr;
    size_t m_size;
    size_t m_capacity;
    // Modifiers
    void resize();
  public:
    // Constructors
    Vector();
    Vector(size_t cappacity);
    Vector(T t_array[], int arraySize);
    // Modifiers
    void push_back(T t_data);
    void shrink_to_fit();
    void pop_back();
    void reserve(size_t t_capacity);
    void clear();
    // Accesors
    size_t size();
    size_t capacity();
    T at(size_t t_index);
    bool empty();
    T front();
    T back();
    T* data();
    // Accemod
    //T& opertator[] (size_t t_index);
};

// Constructors
/**
  * @brief Default constructor that creates
  * a vector with capacity = 2, and size = 0.
*/
template <class T>
Vector<T>::Vector(){
  m_capacity = 2;
  m_size = 0;
  m_data = new T[m_capacity];
}

/**
 * @brief Constructs a Vector with a specified initial capacity.
 * @param t_capacity The initial capacity of the Vector.
 */
template <class T>
Vector<T>::Vector(size_t t_capacity){
  m_capacity = t_capacity;
  m_size = 0;
  m_data = new T[m_capacity];
}

/**
 * @brief Constructs a Vector and initializes it with elements from an array.
 * @param t_array The array containing elements to initialize the Vector.
 * @param arraySize The number of elements in the array.
 */
// https://www.tutorialspoint.com/cplusplus/cpp_passing_arrays_to_functions.htm
template <class T>
Vector<T>::Vector(T t_array[], int arraySize){
  m_capacity = arraySize;
  m_size = 0;
  m_data = new T[m_capacity];
  for(int i = 0; i < arraySize; i++){
    m_data[i] = t_array[i];
    m_size++;
  }
}

// Modifiers

/**
 * @brief Resizes the Vector by doubling its capacity and copying the existing elements.
*/
template <class T>
void Vector<T>::resize(){
  reserve(m_capacity * 2);
}

/**
 * @brief Adds an element to the end of the Vector.
 * @param t_data The element to be added to the Vector.
 */
template <class T>
void Vector<T>::push_back(T t_data){
  if(m_capacity == m_size){
    resize();
  }
  m_data[m_size] = t_data;
  m_size++;
}

/**
 * @brief Shrinks the Vector capacity to match its current size.
 */
template <class T>
void Vector<T>::shrink_to_fit(){
  if(m_size == m_capacity){
    return;
  }
  reserve(m_size);
}

/**
 * @brief Removes the last element from the Vector.
*/
template <class T>
void Vector<T>::pop_back(){
  if(m_size <= 0){
    return;
  }
  m_size--;
}

/**
 * @brief Changes the capacity of the vector to the capacity passed in t_capacity.
 * @param t_capacity The desired capacity to reserve for the Vector.
 */
template<class T>
void Vector<T>::reserve(size_t t_capacity){
  if(t_capacity > m_capacity){
    throw std::invalid_argument("Received smaller value than current capacity. Data might get lost. uWu");
  }
  T* dataTmp = new T[m_size];
  for(size_t i = 0; i < m_size; i++){
    dataTmp[i] = m_data[i]; 
  }
  m_capacity = t_capacity;
  m_data = new T[m_capacity];
  for(size_t i = 0; i < m_size; i++){
      m_data[i] = dataTmp[i]; 
  }
}

/**
 * @brief Removes all elements from the Vector and clears memory.
 */
template<class T>
void Vector<T>::clear(){
  if(m_capacity <= 0 || m_data == nullptr){
    return;
  }
  delete[] m_data;
  m_data = nullptr;
  m_size = 0;
  m_capacity = 1;
}

// Accesors

/**
  * @brief Returns a copy of m_size.
*/
template <class T>
size_t Vector<T>::size(){
  return m_size;
}

/**
  * @brief Returns a copy of m_capacity.
*/
template <class T>
size_t Vector<T>::capacity(){
  return m_capacity;
}

/**
 * @brief Accesses the element at the specified index in the Vector.
 * @param t_index The index of the element to be accessed.
 * @return The element located at the specified index.
 */
template <class T>
T Vector<T>::at(size_t t_index){
  if(t_index >= m_size){
    throw std::out_of_range("Invalid index. Code:uWu");
  }
  return m_data[t_index];
}

/**
 * @brief Checks if the Vector is empty.
 * @return true if the Vector is empty, false otherwise.
 */
template<class T>
bool Vector<T>::empty(){
  return m_size <= 0;
}

/**
 * @brief Returns the first element in the Vector.
 * @return The first element in the Vector.
 */
template<class T>
T Vector<T>::front(){
  if(m_size <= 0){
    throw std::logic_error("");
  }
  return m_data[0];
}

/**
 * @brief Returns the last element in the Vector.
 * @return The last element in the Vector.
 */
template<class T>
T Vector<T>::back(){
  if(m_size == 0){
    return m_data[0];
  }
  return m_data[m_size - 1];
}

/**
 * @brief Returns a pointer to a copy of the data in the Vector.
 * @return A pointer to a copy of the Vector's data.
 */
// https://www.tutorialspoint.com/cplusplus/cpp_return_arrays_from_functions.htm
template<class T>
T* Vector<T>::data(){
  T* dataTmp = new T[m_size];
  for(size_t i = 0; i < m_size; i++){
    dataTmp[i] = m_data[i]; 
  }
  return dataTmp;
}

/**
 * @brief 
 */
/*
template <class T>
T& Vector<T>::operator [] (size_t t_index){
  if(t_index >= m_size){
    throw std::out_of_range("Invalid index. Code:uWu");
  }
  return m_data[t_index];
}
*/