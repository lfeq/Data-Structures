#include <iostream>
#pragma once

/**
 * @brief A template class for a double linked list.
 */
template <class T>
class DoubleLinkedList{
  private:
    class Node{
      private:
        T m_data;
        Node* m_pNext;
        Node* m_pPrev;
      friend class DoubleLinkedList;
    };
    Node* m_pRoot;
    Node* m_pLast;
    Node* generateNode(T t_data);
    size_t m_size;
  public:
    // Constructors
    DoubleLinkedList();
    DoubleLinkedList(T t_data);
    DoubleLinkedList(T tdata[], size_t t_arraySize);
    // Modifiers
    void push_back(T t_data);
    void pop_back();
    void push_front(T t_data);
    void pop_front();
    void insert(T t_data, size_t t_index);
    void erase(size_t t_index);
    void eraseAll(T t_data);
    void clear();
    void insertOrdered(T t_data);
    // Accesors
    bool empty();
    size_t count();
    T at(size_t t_index);
};

/**
 * @brief Default constructor for the DoubleLinkedList class.
 * This constructor initializes an empty double linked list with no elements. It sets
 * the root node pointer to nullptr and the size of the list to zero.
 */
template <class T>
DoubleLinkedList<T>::DoubleLinkedList(){
  m_pRoot = nullptr;
  m_size = 0;
}

/**
 * @brief Constructor for the DoubleLinkedList class to create a list with a single element.
 * @param t_data The value of the single element to be added to the double linked list.
 */
template <class T>
DoubleLinkedList<T>::DoubleLinkedList(T t_data){
  m_pRoot = generateNode(t_data);
  m_pLast = m_pRoot;
  m_size = 1;
}

/**
 * @brief Constructor for the DoubleLinkedList class to create a list from an array of elements.
 * @param t_data An array of elements to populate the double linked list.
 * @param t_arraySize The number of elements in the array.
 */
template <class T>
DoubleLinkedList<T>::DoubleLinkedList(T t_data[], size_t t_arraySize){
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
typename DoubleLinkedList<T>::Node* DoubleLinkedList<T>::generateNode(T t_data){
  Node* pNewNode = new Node();
  pNewNode->m_data = t_data;
  pNewNode->m_pNext = nullptr;
  pNewNode->m_pPrev = nullptr;
  return pNewNode;
}

/**
 * @brief Adds an element to the end of the double linked list.
 * @param t_data The data value of the element to be added.
 */
template <class T>
void DoubleLinkedList<T>::push_back(T t_data){
  if(!m_pRoot){
    m_pRoot = generateNode(t_data);
    m_pLast = m_pRoot;
    m_size++;
    return;
  }
  m_pLast->m_pNext = generateNode(t_data);
  m_pLast->m_pNext->m_pPrev = m_pLast;
  m_pLast = m_pLast->m_pNext;
  m_size++;
}

/**
 * @brief Checks if the double linked list is empty.
 * @return `true` if the double linked list is empty, `false` if it contains elements.
 */
template <class T>
bool DoubleLinkedList<T>::empty(){
  return !m_pRoot;
}

/**
 * @brief Adds an element to the beginning of the double linked list.
 * @param t_data The data value of the element to be added.
 */
template <class T>
void DoubleLinkedList<T>::push_front(T t_data){
  m_size++;
  if(!m_pRoot){
    m_pRoot = generateNode(t_data);
    m_pLast = m_pRoot;
    return;
  }
  Node* pTmp = generateNode(t_data);
  m_pRoot->m_pPrev = pTmp;
  pTmp->m_pNext = m_pRoot;
  m_pRoot = pTmp;
}

/**
 * @brief Removes the first element from the double linked list.
 */
template <class T>
void DoubleLinkedList<T>::pop_front(){
  if(!m_pRoot){
    return;
  }
  Node* pTmp = m_pRoot;
  m_pRoot = m_pRoot->m_pNext;
  m_pRoot->m_pPrev = nullptr;
  delete[] pTmp;
  m_size--;
}

/**
 * @brief Removes the last element from the double linked list.
 */
template <class T>
void DoubleLinkedList<T>::pop_back(){
  if(!m_pRoot){
    return;
  }
  if(!m_pRoot->m_pNext){
    delete[] m_pRoot;
    m_pRoot = nullptr;
    m_size = 0;
    return;
  }
  Node* pIt = m_pRoot;
  while(pIt->m_pNext->m_pNext){
    pIt = pIt->m_pNext;
  }
  delete[] m_pLast;
  m_pLast = nullptr;
  m_pLast = pIt;
  m_pLast->m_pNext = nullptr;
  m_size--;
}

/**
 * @brief Inserts an element at the specified index in the double linked list.
 * @param t_data The data value of the element to be inserted.
 * @param t_index The index at which to insert the new element.
 */
template <class T>
void DoubleLinkedList<T>::insert(T t_data, size_t t_index){
  if(m_size < t_index){
    throw std::out_of_range("Index out of bounds");
  }
  if(t_index == 0){
    push_front(t_data);
    return;
  }
  if(t_index == m_size){
    push_back(t_data);
    return;
  }
  Node* tmpNode;
  if(t_index <= m_size / 2){  
    tmpNode = m_pRoot;
    for (size_t i = 0; i < t_index - 1; i++) {
      tmpNode = tmpNode->m_pNext;
    }
  }else{
    tmpNode = m_pLast;
    for (size_t i = m_size; i > t_index; i--) {
      tmpNode = tmpNode->m_pPrev;
    }
  }
  Node* newNode = generateNode(t_data);
  newNode->m_pNext = tmpNode->m_pNext;
  newNode->m_pPrev = tmpNode;
  tmpNode->m_pNext->m_pPrev = newNode;
  tmpNode->m_pNext = newNode;
  m_size++;
}

/**
 * @brief Removes an element from the double linked list at the specified index.
 * @param t_index The index of the element to be removed.
 */
template <class T>
void DoubleLinkedList<T>::erase(size_t t_index){
  if(m_size < t_index){
    throw std::out_of_range("Index out of bounds");
  }
  if(t_index == 0){
    pop_front();
    return;
  }
  if(t_index == m_size){
    pop_back();
    return;
  }
  Node* tmpNode;
  if(t_index <= m_size / 2){  
    tmpNode = m_pRoot;
    for (size_t i = 0; i < t_index - 1; i++) {
      tmpNode = tmpNode->m_pNext;
    }
  }else{
    tmpNode = m_pLast;
    for (size_t i = m_size; i > t_index; i--) {
      tmpNode = tmpNode->m_pPrev;
    }
  }
  Node* nodeToDelete = tmpNode->m_pNext;
  tmpNode->m_pNext = nodeToDelete->m_pNext;
  nodeToDelete->m_pNext->m_pPrev = tmpNode;
  delete[] nodeToDelete;
  nodeToDelete = nullptr;
  m_size--;
}

/**
 * @brief Removes all occurrences of a specific value from the double linked list.
 * @param t_data The data value to be removed from the double linked list.
 */
template <class T>
void DoubleLinkedList<T>::eraseAll(T t_data){
  while (m_pRoot->m_data == t_data) {
    Node* pTmp = m_pRoot;
    m_pRoot = m_pRoot->m_pNext;
    m_pRoot->m_pPrev = nullptr;
    delete[] pTmp;
    pTmp = nullptr;
    m_size--;
  }
  Node* pIt = m_pRoot;
  while(pIt->m_pNext){
    if(pIt->m_pNext->m_data == t_data){
      Node* pTmp = pIt->m_pNext;
      pIt->m_pNext = pTmp->m_pNext;
      pIt->m_pNext->m_pPrev = pIt;
      delete[] pTmp;
      pTmp = nullptr;
      m_size--;
    }
    else{      
      pIt = pIt->m_pNext;  
    }
  }
}

/**
 * @brief Clears the double linked list, deallocating all memory occupied by elements.
 */
template <class T>
void DoubleLinkedList<T>::clear(){
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
 * @brief Returns the number of elements in the double linked list.
 * @return The total number of elements in the double linked list.
 */
template <class T>
size_t DoubleLinkedList<T>::count(){
  return m_size;
}

/**
 * @brief Accesses the element at a specified index in the double linked list.
 * @param t_index The index of the element to retrieve.
 * @return The data value of the element at the specified index.
 */
template <class T>
T DoubleLinkedList<T>::at(size_t t_index){
  if(t_index >= m_size || t_index < 0){
    throw std::out_of_range("Index out of bounds");
  }
  size_t i = 0;
  Node* node = m_pRoot;
  while(i < t_index){
    node = node->m_pNext;
    i++;
  }
  return node->m_data;
}

/**
 * Fuentes: https://www.geeksforgeeks.org/given-a-linked-list-which-is-sorted-how-will-you-insert-in-sorted-way/ No funciona porque #O(n)
 * https://www.geeksforgeeks.org/binary-search/
 * @brief Inserts an element in a sorted manner into the double linked list.
 * @param t_data The data element to be inserted.
 */
template <class T>
void DoubleLinkedList<T>::insertOrdered(T t_data){
  if(m_size == 0){
    push_back(t_data);
    return;
  }
  if(t_data <= m_pRoot->m_data){
    push_front(t_data);
    return;
  }
  if(t_data >= m_pLast->m_data){
    push_back(t_data);
    return;
  }
  size_t leftSide = 0;
  size_t rightSide = m_size;
  while(leftSide <= rightSide){
    size_t middle = leftSide + (rightSide - 1) / 2;
    if(at(middle) <= t_data && at(middle + 1) >= t_data){
      insert(t_data, middle + 1);
      return;
    }
    if(at(middle) < t_data){
      leftSide = middle + 1;
    }
    else{
      rightSide = middle - 1;
    }
    if(rightSide == 0){
      insert(t_data, rightSide + 1);
      return;
    }
  }
}