#include <iostream>
#include "LinkedList.hpp"
#pragma once

/*
* Fuentes
* https://www.softwaretestinghelp.com/stack-in-cpp/
* https://www.programiz.com/dsa/stack
* https://cplusplus.com/reference/stack/stack/
*/

/**
 * @brief A template class for a Stack.
 */
template <class T>
class Stack{
  private:
    class Node{
      private:
        T m_data;
        Node* m_pNext;
      friend class Stack;
    };
    Node* m_pRoot;
    Node* m_pLast;
    Node* generateNode(T t_data);
    size_t m_size;
    int findSmallest(LinkedList<T> t_array);
  public:
    // Constructors
    Stack();
    Stack(T t_data);
    Stack(T tdata[], size_t t_arraySize);
    // Modifiers
    void push_front(T t_data);
    T pop_front();
    void clear();
    // Accesors
    bool empty();
    size_t count();
    T peek();
    LinkedList<int> sort();
};

/**
 * @brief Default constructor for the Stack class.
 * This constructor initializes an empty Stack with no elements. It sets
 * the root node pointer to nullptr and the size of the list to zero.
 */
template <class T>
Stack<T>::Stack(){
  m_pRoot = nullptr;
  m_size = 0;
}

/**
 * @brief Constructor for the Stack class to create a stack with a single element.
 * @param t_data The value of the single element to be added to the stack. 
 */
template <class T>
Stack<T>::Stack(T t_data){
  m_pRoot = generateNode(t_data);
  m_pLast = m_pRoot;
  m_size = 1;
}

/**
 * @brief Constructor for the Stack class to create a stack from an array of elements.
 * @param t_data An array of elements to populate the stack.
 * @param t_arraySize The number of elements in the array. 
 */
template <class T>
Stack<T>::Stack(T t_data[], size_t t_arraySize){
  m_pRoot = nullptr;
  m_size = 0;
  for(int i = 0; i < t_arraySize; i++){
    push_front(t_data[i]);
  }
}

/**
 * @brief Function to create a new node.
 * @param t_data The data value to be stored in the new node.
 * @return A pointer to the created node. 
 */
template <class T>
typename Stack<T>::Node* Stack<T>::generateNode(T t_data){
  Node* pNewNode = new Node();
  pNewNode->m_data = t_data;
  pNewNode->m_pNext = nullptr;
  return pNewNode;
}

/**
 * @brief Adds an element to the beginning of the stack.
 * @param t_data The data value of the element to be added. 
 */
template <class T>
void Stack<T>::push_front(T t_data){
  m_size++;
  if(!m_pRoot){
    m_pRoot = generateNode(t_data);
    m_pLast = m_pRoot;
    return;
  }
  Node* pTmp = generateNode(t_data);
  pTmp->m_pNext = m_pRoot;
  m_pRoot = pTmp;
}

/**
 * @brief Checks if the stack is empty.
 * @return `true` if the linked list is empty, `false` if it contains elements. 
 */
template <class T>
bool Stack<T>::empty(){
  return !m_pRoot;
}

/**
 * @brief Removes the first element from the stack.
 * @return The first element from the stack.
 */
template <class T>
T Stack<T>::pop_front(){
  if(!m_pRoot){
    throw std::length_error("Stack is empty");
  }
  if(!m_pRoot->m_pNext){
    Node* pTmp = m_pRoot;
    T data = pTmp->m_data;
    delete[] m_pRoot;
    m_pRoot = nullptr;
    m_pLast = nullptr;
    //delete[] pTmp;
    m_size--;
    return data;
  }
  Node* pTmp = m_pRoot;
  T data = pTmp->m_data;
  m_pRoot = m_pRoot->m_pNext;
  delete[] pTmp;
  m_size--;
  return data;
}

/**
 * @brief Clears the linked list, deallocating all memory occupied by elements. 
 */
template <class T>
void Stack<T>::clear(){
  Node* pTmp = m_pRoot;
  while(!pTmp->m_pNext){
    Node* nextNode = pTmp->m_pNext;
    delete[] pTmp;
    pTmp = nullptr;
    pTmp = nextNode;
  }
  m_size = 0;
  m_pLast = nullptr;
  m_pRoot = nullptr;
}

/**
 * @brief Returns the number of elements in the stack.
 * @return The total number of elements in the stack. 
 */
template <class T>
size_t Stack<T>::count(){
  return m_size;
}

/**
 * @brief Returns the element at the front of the stack without removing it.
 * @return the element at the front of the stack. 
 */
template <class T>
T Stack<T>::peek(){
  if(!m_pRoot){
    throw std::length_error("Stack is empty");
  }
  if(!m_pRoot->m_pNext){
    return m_pRoot->m_data;
  }
  return m_pLast->m_data;
}

/**
 * Fuente
 * Grokking Algorithms
 * An illustrated guide for programmers and other curious people, pag 35.
 * @brief Creates and returns a LinkedList containing the element of the queue 
 * sorted in ascending order.
 * @return A new LinkedList with element sorted in ascending order.
 */
template <class T>
LinkedList<int> Stack<T>::sort(){
  Node* pTmp = m_pRoot;
  int arr[m_size];
  int newArr[m_size];
  int counter = 0;
  while(pTmp){
    arr[counter] = pTmp->m_data;
    Node* nextNode = pTmp->m_pNext;
    pTmp = nextNode;
    counter++;
  }
  int arraySize = sizeof(arr) / sizeof(arr[0]);
  LinkedList<int> list(arr, arraySize);
  for(int i = 0; i < arraySize; i++){
    int smallest = findSmallest(list);
    newArr[i] = list.at(smallest);
    list.erase(smallest);
  }
  LinkedList<int> finalList(newArr, arraySize);
  return finalList;
}

/**
 * @brief Finds and returns the index of the smallest element in t_array.
 * @param t_array The LinkedList to be searched.
 * @return The index of the smallest element in t_array.
 */
template <class T>
int Stack<T>::findSmallest(LinkedList<T> t_array){
  int smallest = t_array.at(0);
  int smallest_index = 0;
  for (int i = 1; i < t_array.count(); i++) {
    if(t_array.at(i) < smallest){
      smallest = t_array.at(i);
      smallest_index = i;
    }
  }
  return smallest_index;
}