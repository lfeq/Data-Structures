#include <iostream>

/**
 * 
 */
template <class T>
class Stack{
  private:
    class Node{
      private:
        T m_data;
        Node* m_pNext;
      friend class LinkedList;
    };
    Node* m_pRoot;
    Node* m_pLast;
    Node* generateNode(T t_data);
    size_t m_size;
  public:
    // Constructors
    Stack();
    Stack(T t_data);
    Stack(T tdata[], size_t t_arraySize);
    // Modifiers
    void push_back(T t_data);
    void pop_back();
    void push_front(T t_data);
    void pop_front();
    void insert(T t_data, size_t t_index);
    void erase(size_t t_index);
    void eraseAll(T t_data);
    void clear();
    // Accesors
    bool empty();
    size_t count();
    T at(size_t t_index);
};

/**
 * 
 */
template <class T>
Stack<T>::Stack(){
  m_pRoot = nullptr;
  m_size = 0;
}

/**
 * 
 */
template <class T>
Stack<T>::Stack(T t_data){
  m_pRoot = generateNode(t_data);
  m_pLast = m_pRoot;
  m_size = 1;
}

/**
 * 
 */
template <class T>
Stack<T>::Stack(T t_data[], size_t t_arraySize){
  m_pRoot = nullptr;
  m_size = 0;
  for(int i = 0; i < t_arraySize; i++){
    push_back(t_data[i]);
  }
}

/**
 * 
 */
template <class T>
typename Stack<T>::Node* Stack<T>::generateNode(T t_data){
  Node* pNewNode = new Node();
  pNewNode->m_data = t_data;
  pNewNode->m_pNext = nullptr;
  return pNewNode;
}

/**
 * 
 */
template <class T>
void Stack<T>::push_back(T t_data){
  if(!m_pRoot){
    m_pRoot = generateNode(t_data);
    m_pLast = m_pRoot;
    m_size++;
    return;
  }
  m_pLast->m_pNext = generateNode(t_data);
  m_pLast = m_pLast->m_pNext;
  m_size++;
}

/**
 * 
 */
template <class T>
bool Stack<T>::empty(){
  return !m_pRoot;
}

/**
 * 
 */
template <class T>
void Stack<T>::push_front(T t_data){
  m_size++;
  if(!m_pRoot){
    m_pRoot = generateNode(t_data);
    return;
  }
  Node* pTmp = generateNode(t_data);
  pTmp->m_pNext = m_pRoot;
  m_pRoot = pTmp;
}

/**
 *
 */
template <class T>
void Stack<T>::pop_front(){
  if(!m_pRoot){
    return;
  }
  Node* pTmp = m_pRoot;
  m_pRoot = m_pRoot->m_pNext;
  delete[] pTmp;
  m_size--;
}

/**
 * 
 */
template <class T>
void Stack<T>::pop_back(){
  if(!m_pRoot){
    return;
  }
  if(!m_pRoot->m_pNext){
    delete[] m_pRoot;
    m_pRoot = nullptr;
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
 * 
 */
template <class T>
void Stack<T>::insert(T t_data, size_t t_index){
  if(m_size < t_index){
    throw std::out_of_range("Index out of bounds");
  }
  if(t_index == 0){
    push_front(t_data);
    return;
  }
  size_t counter = 0;
  Node* node = m_pRoot;
  while(counter < t_index - 1){
    node = node->m_pNext;
    counter++;
  }
  Node* newNode = generateNode(t_data);
  newNode->m_pNext = node->m_pNext;
  node->m_pNext = newNode;
  m_size++;
}

/**
 * 
 */
template <class T>
void Stack<T>::erase(size_t t_index){
  if(m_size < t_index){
    throw std::out_of_range("Index out of bounds");
  }
  if(t_index == 0){
    pop_front();
    return;
  }
  size_t counter = 0;
  Node* node = m_pRoot;
  while(counter < t_index - 1){
    node = node->m_pNext;
    counter++;
  }
  Node* nodeToDelete = node->m_pNext;
  node->m_pNext = nodeToDelete->m_pNext;
  delete[] nodeToDelete;
  nodeToDelete = nullptr;
  m_size--;
}

/**
 * 
 */
template <class T>
void Stack<T>::eraseAll(T t_data){
  while (m_pRoot->m_data == t_data) {
    Node* pTmp = m_pRoot;
    m_pRoot = m_pRoot->m_pNext;
    delete[] pTmp;
    pTmp = nullptr;
    m_size--;
  }
  Node* pIt = m_pRoot;
  while(pIt->m_pNext){
    if(pIt->m_pNext->m_data == t_data){
      Node* pTmp = pIt->m_pNext;
      pIt->m_pNext = pTmp->m_pNext;
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
 * 
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
 * 
 */
template <class T>
size_t Stack<T>::count(){
  return m_size;
}

/**
 * 
 */
template <class T>
T Stack<T>::at(size_t t_index){
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