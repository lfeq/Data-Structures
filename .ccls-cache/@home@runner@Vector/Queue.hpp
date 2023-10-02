#include <iostream>
#include "LinkedList.hpp"
#pragma once

/*
* Fuentes
* https://www.programiz.com/cpp-programming/queue
* https://www.softwaretestinghelp.com/queue-in-cpp/
* https://cplusplus.com/reference/queue/queue/
*/

/**
 * @brief A template class for a Queue.
 */
template <class T>
class Queue{
  private:
    class Node{
      private:
        T m_data;
        Node* m_pNext;
      friend class Queue;
    };
    Node* m_pRoot;
    Node* m_pLast;
    Node* generateNode(T t_data);
    size_t m_size;
    int findSmallest(LinkedList<T> t_array);
  public:
    // Constructors
    Queue();
    Queue(T t_data);
    Queue(T tdata[], size_t t_arraySize);
    // Modifiers
    void push_back(T t_data);
    T pop_front();
    void clear();
    // Accesors
    bool empty();
    size_t count();
    T peek();
    T back();
    LinkedList<int> sort();
};

/**
 * @brief Default constructor for the Queue class.
 * This constructor initializes an empty Queue with no elements. It sets
 * the root node pointer to nullptr and the size of the list to zero.
 */
template <class T>
Queue<T>::Queue(){
  m_pRoot = nullptr;
  m_size = 0;
}

/**
 * @brief Constructor for the Queue class to create a queue with a single element.
 * @param t_data The value of the single element to be added to the queue.
 */
template <class T>
Queue<T>::Queue(T t_data){
  m_pRoot = generateNode(t_data);
  m_pLast = m_pRoot;
  m_size = 1;
}

/**
 * @brief Constructor for the Queue class to create a queue from an array of elements.
 * @param t_data An array of elements to populate the queue.
 * @param t_arraySize The number of elements in the array.
 */
template <class T>
Queue<T>::Queue(T t_data[], size_t t_arraySize){
  m_pRoot = nullptr;
  m_size = 0;
  for(int i = 0; i < t_arraySize; i++){
    push_back(t_data[i]);
  }
}

/**
 * @brief Function to create a new node.
 * @param t_data The data value to be stored in the new node.
 * @return A pointer to the created node. 
 */
template <class T>
typename Queue<T>::Node* Queue<T>::generateNode(T t_data){
  Node* pNewNode = new Node();
  pNewNode->m_data = t_data;
  pNewNode->m_pNext = nullptr;
  return pNewNode;
}

/**
 * @brief Adds an element to the end of the queue.
 * @param t_data The data value of the element to be added. 
 */
template <class T>
void Queue<T>::push_back(T t_data){
  m_size++;
  if(!m_pRoot){
    m_pRoot = generateNode(t_data);
    m_pLast = m_pRoot;
    return;
  }
  m_pLast->m_pNext = generateNode(t_data);
  m_pLast = m_pLast->m_pNext;
}

/**
 * @brief Removes the first element from the queue.
 * @return the first element from the queue.
 */
template <class T>
T Queue<T>::pop_front(){
  if(!m_pRoot){
    throw std::length_error("Stack is empty");
  }
  if(!m_pRoot->m_pNext){
    Node* pTmp = m_pRoot;
    T data = pTmp->m_data;
    delete[] m_pRoot;
    m_pRoot = nullptr;
    m_pLast = nullptr;
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
 * @brief Returns the element at the front of the queue without removing it.
 * @return the element at the front of the queue.
 */
template <class T>
T Queue<T>::peek(){
  if(!m_pRoot){
    throw std::length_error("Queue is empty");
  }
  return m_pRoot->m_data;
}

/**
 * @brief Returns the element at the end of the queue without removing it.
 * @return the element at the end of the queue. 
 */
template <class T>
T Queue<T>::back(){
  if(!m_pRoot){
    throw std::length_error("Queue is empty");
  }
  if(!m_pRoot->m_pNext){
    return m_pRoot->m_data;
  }
  return m_pLast->m_data;
}

/**
 * @brief Returns the number of elements in the queue.
 * @return The total number of elements in the queue. 
 */
template <class T>
size_t Queue<T>::count(){
  return m_size;
}

/**
 * @brief Checks if the queue is empty.
 * @return `true` if the linked list is empty, `false` if it contains elements. 
 */
template <class T>
bool Queue<T>::empty(){
  return !m_pRoot;
}

/**
 * @brief Clears the queue, deallocating all memory occupied by elements.
 */
template <class T>
void Queue<T>::clear(){
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
 * Fuente
 * Grokking Algorithms
 * An illustrated guide for programmers and other curious people, pag 35.
 * @brief Creates and returns a LinkedList containing the element of the queue 
 * sorted in ascending order.
 * @return A new LinkedList with element sorted in ascending order.
 */
template <class T>
LinkedList<int> Queue<T>::sort(){
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
int Queue<T>::findSmallest(LinkedList<T> t_array){
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