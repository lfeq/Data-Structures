#include <iostream>
#include "Queue.hpp"
#pragma once

/**
 * @brief A binary tree data structure.
*/
template <class T>
class BinaryTree{
  private:
    class Node{
      private:
        T m_data;
        Node* m_pLeft;
        Node* m_pRight;
      friend class BinaryTree;
    };
    Node* m_pRoot;
    Node* generateNode(T t_data);
    size_t m_size;
  public:
    // Constructors
    BinaryTree();
    BinaryTree(T t_data);
    BinaryTree(T t_data[], size_t t_arraySize);
    // Modifiers
    void add(T t_data);
    void clear();
    void erase(T t_data);
    void print_tree();
    // Accesor
    bool empty();
    bool find(T t_data);
};

/**
  * @brief Default constructor for BinaryTree.
 */
template <class T>
BinaryTree<T>::BinaryTree(){
  m_pRoot = nullptr;
  m_size = 0;
}

/**
  * @brief Constructor for BinaryTree with initial data.
  * @param t_data The data to initialize the tree with.
*/
template <class T>
BinaryTree<T>::BinaryTree(T t_data){
  m_pRoot = generateNode(t_data);
  m_size = 1;
}

/**
  * @brief Constructor for BinaryTree with an array of data.
  * @param t_data[] An array of data elements.
  * @param t_arraySize The size of the array.
*/
template <class T>
BinaryTree<T>::BinaryTree(T t_data[], size_t t_arraySize){
  m_pRoot = nullptr;
  m_size = 0;
  for(int i = 0; i < t_arraySize; i++){
    add(t_data[i]);
  }
}

/**
  * @brief Function to create a new node.
  * @param t_data The data value to be stored in the new node.
  * @return A pointer to the created node.
*/
template <class T>
typename BinaryTree<T>::Node* BinaryTree<T>::generateNode(T t_data){
  Node* pNewNode = new Node();
  pNewNode->m_data = t_data;
  pNewNode->m_pLeft = nullptr;
  pNewNode->m_pRight = nullptr;
  return pNewNode;
}

/**
  * @brief Add an element to the tree.
  * @param t_data The data to add to the tree.
*/
template <class T>
void BinaryTree<T>::add(T t_data){
  if(!m_pRoot){
    m_pRoot = generateNode(t_data);
    m_size++;
    return;
  }
  Node* tmpNode = m_pRoot;
  while(tmpNode){
    if(tmpNode->m_data == t_data){
      return;
    }
    if(tmpNode->m_data < t_data){
      if(!tmpNode->m_pRight){
        tmpNode->m_pRight = generateNode(t_data);
        return;
      } else{
        tmpNode = tmpNode->m_pRight;
      }
    } else{
      if(!tmpNode->m_pLeft){
        tmpNode->m_pLeft = generateNode(t_data);
        return;
      } else{
        tmpNode = tmpNode->m_pLeft;
      }
    }
  }
}

/**
  * @brief Find an element in the tree.
  * @param t_data The data to search for.
  * @return True if the data is found in the tree, false otherwise.
*/
template <class T>
bool BinaryTree<T>::find(T t_data){
  if(!m_pRoot){
    throw std::out_of_range("Tree is empty");
  }
  Node* tmpNode = m_pRoot;
  while(tmpNode){
    if(tmpNode->m_data == t_data){
      return true;
    }
    if(tmpNode->m_data < t_data){
      if(tmpNode->m_pRight){
        tmpNode = tmpNode->m_pRight;
      }
    }else{
      if(tmpNode->m_pLeft){
        tmpNode = tmpNode->m_pLeft;
      }
    }
  }
  return false;
}

/**
 * @brief Check if the tree is empty.
 * @return True if the tree is empty, false otherwise.
 */
template <class T>
bool BinaryTree<T>::empty(){
  return !m_pRoot;
}

/**
 * @brief Clear the tree.
 * Removes all nodes and data from the tree, leaving it empty.
 */
// https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
template <class T>
void BinaryTree<T>::clear(){
  Node* pTmp = m_pRoot;
  Queue<Node*> queue;
  queue.push_back(pTmp);
  while(!queue.empty()){
    pTmp = queue.pop_front();
    if(pTmp->m_pLeft){
      queue.push_back(pTmp->m_pLeft);
    }
    if(pTmp->m_pRight){
      queue.push_back(pTmp->m_pRight);
    }
    delete[] pTmp;
    pTmp = nullptr;
  }
}

/**
 * @brief Erase an element from the tree.
 * @param t_data The data to remove from the tree.
 */
template <class T>
void BinaryTree<T>::erase(T t_data){
  if(!m_pRoot){
    throw std::out_of_range("Tree is empty");
  }
  if(!find(t_data)){
    return;
  }
  Node* tmpNode = m_pRoot;
  Node* nodeToDelete = nullptr;
  Node* queueNode = nullptr;
  Queue<Node*> loopQueue;
  Queue<T> addQueue;
  while(!nodeToDelete){
    if(tmpNode->m_data < t_data){
      if(tmpNode->m_pRight->m_data == t_data){
        nodeToDelete = tmpNode;
      }else if(tmpNode->m_pRight){
        tmpNode = tmpNode->m_pRight;
      } 
    }else{
      if(tmpNode->m_pLeft->m_data == t_data){
        nodeToDelete = tmpNode;
      }else if(tmpNode->m_pLeft){
        tmpNode = tmpNode->m_pLeft;
      }
    }
  }
  if(nodeToDelete->m_pLeft->m_data == t_data){
    loopQueue.push_back(nodeToDelete->m_pLeft);
    nodeToDelete->m_pLeft = nullptr;
  }else if(nodeToDelete->m_pRight->m_data == t_data){
    loopQueue.push_back(nodeToDelete->m_pRight);
    nodeToDelete->m_pLeft = nullptr;
  }
  while(!loopQueue.empty()){
    tmpNode = loopQueue.pop_front();
    if(tmpNode->m_pLeft){
      loopQueue.push_back(tmpNode->m_pLeft);
      addQueue.push_back(tmpNode->m_pLeft->m_data);
    }else if(tmpNode->m_pRight){
      loopQueue.push_back(tmpNode->m_pRight);
      addQueue.push_back(tmpNode->m_pRight->m_data);
    }
    delete[] tmpNode;
    tmpNode = nullptr;
  }
  while(!addQueue.empty()){
    T queueData = addQueue.pop_front();
    add(queueData);
  }
}

/*
  */
template <class T>
void BinaryTree<T>::print_tree(){
  Node* pTmp = m_pRoot;
  Queue<Node*> queue;
  queue.push_back(pTmp);
  while(!queue.empty()){
    pTmp = queue.pop_front();
    std::cout << pTmp->m_data << " {";
    if(pTmp->m_pLeft){
      std::cout << pTmp->m_pLeft->m_data << ", ";  
      queue.push_back(pTmp->m_pLeft);
    }
    if(pTmp->m_pRight){
      std::cout << pTmp->m_pRight->m_data;  
      queue.push_back(pTmp->m_pRight);
    }
    std::cout << "}\n";
  }
  std::cout << std::endl;
}