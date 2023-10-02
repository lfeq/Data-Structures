#include <iostream>
#include "Queue.hpp"
#include "Stack.hpp"
#include "LinkedList.hpp"
#pragma once

/**
 * @brief A template class for a tree.
 */
template <class T>
class Tree{
  private:
    class Node{
      private: 
        T m_data;
        LinkedList<Node*> m_pAdyacentNodes;
      friend class Tree;
    };
    Node* m_pRoot;
    Node* generateNode(T t_data);
    Node* node_BFS(T t_data);
    Node* node_DFS(T t_data);
  public:
    // Constructors
    Tree();
    Tree(T t_data);
    Tree(T t_data, T t_children[], size_t t_arraySize);
    // Modifiers
    void add(T t_data, T t_parent);
    void clear();
    // Accesors
    bool bool_DFS(T t_data);
    bool bool_BFS(T t_data);
    bool empty();
    void traverse();
    void erase(T t_data);
};

/**
 * @brief Default constructor for the Tree class.
 */
template <class T>
Tree<T>::Tree(){
  m_pRoot = nullptr;
}

/**
 * @brief Constructor for initializing a Tree with a root node.
 * @param t_data The data value for the root node.
 */
template <class T>
Tree<T>::Tree(T t_data){
  m_pRoot = generateNode(t_data);
}

/**
 * @brief Constructs a Tree with a root node and its child nodes.
 * @param t_data The data for the root node.
 * @param t_children An array of child nodes to be added to the root node.
 * @param t_arraySize The size of the 't_children' array.
 */
template <class T>
Tree<T>::Tree(T t_data, T t_children[], size_t t_arraySize){
  m_pRoot = generateNode(t_data);
  for(int i = 0; i < t_arraySize; i++){
    add(t_children[i], t_data);
  }
}

/**
 * @brief Creates and initializes a new tree node.
 * @param t_data The data to be stored in the new node.
 * @return A pointer to the newly created node.
 */
template <class T>
typename Tree<T>::Node* Tree<T>::generateNode(T t_data){
  Node* pNewNode = new Node();
  pNewNode->m_data = t_data;
  return pNewNode;
}

/**
 * @brief Checks if the tree is empty.
 * @return True if the tree is empty; otherwise, false.
 */
template <class T>
bool Tree<T>::empty(){
  return !m_pRoot;
}

/**
 * @brief Check if a node with the specified data exists in the tree using Depth-First Search (DFS).
 * @param t_data The data to search for in the tree.
 * @return true if the node with the specified data exists, false otherwise.
 * @throws std::out_of_range If the tree is empty.
 */
template <class T>
bool Tree<T>::bool_DFS(T t_data){
  if(!m_pRoot){
    throw std::out_of_range("Tree is empty");
  }
  Node* pTmp = m_pRoot;
  Stack<Node*> stack;
  stack.push_front(pTmp);
  while(!stack.empty()){
    pTmp = stack.pop_front();
    if(pTmp->m_data == t_data){
      return true;
    }
    for(int i = 0; i < pTmp->m_pAdyacentNodes.count(); i++){
      stack.push_front(pTmp->m_pAdyacentNodes.at(i));
    }
  }
  return false;
}

/**
 * @brief Perform a Depth-First Search (DFS) in the tree to find a node with the given data.
 * @param t_data The data to search for within the tree nodes.
 * @return A pointer to the node containing the specified data if found; otherwise, nullptr.
 * @throws std::out_of_range If the tree is empty.
 */
template <class T>
typename Tree<T>::Node* Tree<T>::node_DFS(T t_data){
  if(!m_pRoot){
    throw std::out_of_range("Tree is empty");
  }
  Node* pTmp = m_pRoot;
  Stack<Node*> stack;
  stack.push_front(pTmp);
  while(!stack.empty()){
    pTmp = stack.pop_front();
    if(pTmp->m_data == t_data){
      return pTmp;
    }
    for(int i = 0; i < pTmp->m_pAdyacentNodes.count(); i++){
      stack.push_front(pTmp->m_pAdyacentNodes.at(i));
    }
  }
}

/**
 * @brief Perform a Breadth-First Search (BFS) on the tree to find a node with the specified data.
 * @param t_data The data to search for within the tree.
 * @return A pointer to the node with the matching data if found, nullptr otherwise.
 * @throws std::out_of_range if the tree is empty.
 */
template <class T>
typename Tree<T>::Node* Tree<T>::node_BFS(T t_data){
  if(!m_pRoot){
    throw std::out_of_range("Tree is empty");
  }
  Node* pTmp = m_pRoot;
  Queue<Node*> queue;
  queue.push_back(pTmp);
  while(!queue.empty()){
    pTmp = queue.pop_front();
    if(pTmp->m_data == t_data){
      return pTmp;
    }
    for(int i = 0; i < pTmp->m_pAdyacentNodes.count(); i++){
      queue.push_back(pTmp->m_pAdyacentNodes.at(i));
    }
  }
}

/**
 * @brief Perform a Breadth-First Search (BFS) to find a node with the specified data.
 * @param t_data The data of the node to find.
 * @return A pointer to the found node or nullptr if not found.
 * @throws std::out_of_range If the graph is empty.
 */
template <class T>
bool Tree<T>::bool_BFS(T t_data){
  if(!m_pRoot){
    throw std::out_of_range("Tree is empty");
  }
  Node* pTmp = m_pRoot;
  Queue<Node*> queue;
  queue.push_back(pTmp);
  while(!queue.empty()){
    pTmp = queue.pop_front();
    if(pTmp->m_data == t_data){
      return true;
    }
    for(int i = 0; i < pTmp->m_pAdyacentNodes.count(); i++){
      queue.push_back(pTmp->m_pAdyacentNodes.at(i));
    }
  }
  return false;
}

/**
 * @brief Adds a new node to the tree.
 * @param t_data   The data for the new node to be added.
 * @param t_parent The data of an existing node to which the new node will be connected.
 * @throws std::invalid_argument if t_data is equal to t_parent.
 * @throws std::out_of_range    if the specified parent node doesn't exist in the tree.
 */
template <class T>
void Tree<T>::add(T t_data, T t_parent){
  if(bool_DFS(t_data)){
    return;
  }
  if(!bool_BFS(t_parent)){
    throw std::out_of_range("Parent doesn't exist.");
  }
  Node* parentNode = node_BFS(t_parent);
  Node* newNode = generateNode(t_data);
  parentNode->m_pAdyacentNodes.push_back(newNode);
}

/**
 * @brief Clear the tree, removing all nodes and their connections.
 */
template <class T>
void Tree<T>::clear(){
  Node* pTmp = m_pRoot;
  Queue<Node*> queue;
  Stack<Node*> stack;
  queue.push_back(pTmp);
  while(!queue.empty()){
    pTmp = queue.pop_front();
    for(int i = 0; i < pTmp->m_pAdyacentNodes.count(); i++){
      queue.push_back(pTmp->m_pAdyacentNodes.at(i));
      stack.push_front(pTmp->m_pAdyacentNodes.at(i));
    }
  }
  while(!stack.empty()){
    pTmp = stack.pop_front();
    delete[] pTmp;
  }
  delete[] m_pRoot;
  m_pRoot = nullptr;
}

/**
 * @brief Traverse and print the nodes of the graph in breadth-first order.
 */
template <class T>
void Tree<T>::traverse(){
  std::cout << "Tree:\n";
  Node* pTmp = m_pRoot;
  Queue<Node*> queue;
  queue.push_back(pTmp);
  while(!queue.empty()){
    pTmp = queue.pop_front();
    std::cout << pTmp->m_data << " {";
    for(int i = 0; i < pTmp->m_pAdyacentNodes.count(); i++){
      std::cout << pTmp->m_pAdyacentNodes.at(i)->m_data << ", ";
      queue.push_back(pTmp->m_pAdyacentNodes.at(i));
    }
    std::cout << "}\n";
  }
  std::cout << std::endl;
}

/**
 * @brief Remove a node with the specified data from the tree.
 * @param t_data The data of the node to be removed.
 */
template <class T>
void Tree<T>::erase(T t_data){
  Node* pTmp = m_pRoot;
  Node* nodeToDelete;
  Queue<Node*> queue;
  queue.push_back(pTmp);
  bool isSearching = true;
  while(!queue.empty() && isSearching){
    pTmp = queue.pop_front();
    for(int i = 0; i < pTmp->m_pAdyacentNodes.count(); i++){
      if(pTmp->m_pAdyacentNodes.at(i)->m_data == t_data){
         isSearching = false;
      }
      queue.push_back(pTmp->m_pAdyacentNodes.at(i));
    }
  }
  for(int i = 0; i < pTmp->m_pAdyacentNodes.count(); i++){
    if(pTmp->m_pAdyacentNodes.at(i)->m_data == t_data){
      nodeToDelete = pTmp->m_pAdyacentNodes.at(i);
      for(int j = 0; j < nodeToDelete->m_pAdyacentNodes.count(); j++){
        pTmp->m_pAdyacentNodes.push_back(nodeToDelete->m_pAdyacentNodes.at(j));
      }
      pTmp->m_pAdyacentNodes.erase(i);
    }
  }
  nodeToDelete->m_pAdyacentNodes.clear();
  delete[] nodeToDelete;
  nodeToDelete = nullptr;
}