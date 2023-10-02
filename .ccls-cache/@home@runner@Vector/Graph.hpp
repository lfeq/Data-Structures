#include <iostream>
#include "Queue.hpp"
#include "Stack.hpp"
#include "LinkedList.hpp"
#pragma once

// Voy a implementar la estrategia vista en clase para evitar ciclos infinitos.
/**
 * @brief A template class for a graph.
 */
template <class T>
class Graph{
  private:
    class Node{
      private: 
        T m_data;
        bool m_visited;
        LinkedList<Node*> m_pAdyacentNodes;
      friend class Graph;
    };
    Node* m_pRoot;
    Node* generateNode(T t_data);
    Node* node_BFS(T t_data);
    Node* node_DFS(T t_data);
  public:
    // Constructors
    Graph();
    Graph(T t_data);
    Graph(T t_data, T t_children[], size_t t_arraySize);
    // Modifiers
    void add(T t_data, T t_parent);
    void clear();
    // Accesors
    bool bool_DFS(T t_data);
    bool bool_BFS(T t_data);
    bool empty();
    void traverse();
};

/**
 * @brief Default constructor for the Graph class.
 */
template <class T>
Graph<T>::Graph(){
  m_pRoot = nullptr;
}

/**
 * @brief Constructor for initializing a Graph with a root node.
 * @param t_data The data value for the root node.
 */
template <class T>
Graph<T>::Graph(T t_data){
  m_pRoot = generateNode(t_data);
}

/**
 * @brief Constructs a Graph with a root node and its child nodes.
 * @param t_data The data for the root node.
 * @param t_children An array of child nodes to be added to the root node.
 * @param t_arraySize The size of the 't_children' array.
 */
template <class T>
Graph<T>::Graph(T t_data, T t_children[], size_t t_arraySize){
  m_pRoot = generateNode(t_data);
  for(int i = 0; i < t_arraySize; i++){
    add(t_children[i], t_data);
  }
}

/**
 * @brief Creates and initializes a new graph node.
 * @param t_data The data to be stored in the new node.
 * @return A pointer to the newly created node.
 */
template <class T>
typename Graph<T>::Node* Graph<T>::generateNode(T t_data){
  Node* pNewNode = new Node();
  pNewNode->m_data = t_data;
  pNewNode->m_visited = false;
  return pNewNode;
}

/**
 * @brief Checks if the graph is empty.
 * @return True if the graph is empty; otherwise, false.
 */
template <class T>
bool Graph<T>::empty(){
  return !m_pRoot;
}

/**
 * @brief Check if a node with the specified data exists in the graph using Depth-First Search (DFS).
 * @param t_data The data to search for in the graph.
 * @return true if the node with the specified data exists, false otherwise.
 * @throws std::out_of_range If the graph is empty.
 */
template <class T>
bool Graph<T>::bool_DFS(T t_data){
  if(!m_pRoot){
    throw std::out_of_range("Graph is empty");
  }
  Node* pTmp = m_pRoot;
  Stack<Node*> stack;
  Stack<Node*> visitedStack;
  stack.push_front(pTmp);
  while(!stack.empty()){
    pTmp = stack.pop_front();
    if(pTmp->m_data == t_data){
      while(!visitedStack.empty()){
        pTmp = visitedStack.pop_front();
        pTmp->m_visited = false;
      }
      return true;
    }
    if(!pTmp->m_visited){      
      visitedStack.push_front(pTmp);
      pTmp->m_visited = true;
      for(int i = 0; i < pTmp->m_pAdyacentNodes.count(); i++){
          stack.push_front(pTmp->m_pAdyacentNodes.at(i));
      }
    }
  }
  while(!visitedStack.empty()){
    pTmp = visitedStack.pop_front();
    pTmp->m_visited = false;
  }
  return false;
}

/**
 * @brief Perform a Depth-First Search (DFS) in the graph to find a node with the given data.
 * @param t_data The data to search for within the graph nodes.
 * @return A pointer to the node containing the specified data if found; otherwise, nullptr.
 * @throws std::out_of_range If the graph is empty.
 */
template <class T>
typename Graph<T>::Node* Graph<T>::node_DFS(T t_data){
  if(!m_pRoot){
    throw std::out_of_range("Graph is empty");
  }
  Node* pTmp = m_pRoot;
  Stack<Node*> stack;
  Stack<Node*> visitedStack;
  stack.push_front(pTmp);
  while(!stack.empty()){
    pTmp = stack.pop_front();
    if(pTmp->m_data == t_data){
      while(!visitedStack.empty()){
        Node* visitedNode = visitedStack.pop_front();
        visitedNode->m_visited = false;
      }
      return pTmp;
    }
    if(!pTmp->m_visited){      
      visitedStack.push_front(pTmp);
      pTmp->m_visited = true;
      for(int i = 0; i < pTmp->m_pAdyacentNodes.count(); i++){
        stack.push_front(pTmp->m_pAdyacentNodes.at(i));
      }
    }
  }
}

/**
 * @brief Perform a Breadth-First Search (BFS) on the graph to find a node with the specified data.
 * @param t_data The data to search for within the graph.
 * @return A pointer to the node with the matching data if found, nullptr otherwise.
 * @throws std::out_of_range if the graph is empty.
 */
template <class T>
typename Graph<T>::Node* Graph<T>::node_BFS(T t_data){
  if(!m_pRoot){
    throw std::out_of_range("Graph is empty");
  }
  Node* pTmp = m_pRoot;
  Queue<Node*> queue;
  Queue<Node*> visitedQueue;
  queue.push_back(pTmp);
  while(!queue.empty()){
    pTmp = queue.pop_front();
    if(pTmp->m_data == t_data){
      while(!visitedQueue.empty()){
        Node* visitedNode =visitedQueue.pop_front();
        visitedNode->m_visited = false;
      }
      return pTmp;
    }
    if(!pTmp->m_visited){
      pTmp->m_visited = true;
      visitedQueue.push_back(pTmp);
      for(int i = 0; i < pTmp->m_pAdyacentNodes.count(); i++){
        queue.push_back(pTmp->m_pAdyacentNodes.at(i));
      }
    }
  }
  while(!visitedQueue.empty()){
    pTmp = visitedQueue.pop_front();
    pTmp->m_visited = false;
  }
}

/**
 * @brief Perform a Breadth-First Search (BFS) to find a node with the specified data.
 * @param t_data The data of the node to find.
 * @return A pointer to the found node or nullptr if not found.
 * @throws std::out_of_range If the graph is empty.
 */
template <class T>
bool Graph<T>::bool_BFS(T t_data){
  if(!m_pRoot){
    throw std::out_of_range("Graph is empty");
  }
  Node* pTmp = m_pRoot;
  Queue<Node*> queue;
  Queue<Node*> visitedQueue;
  queue.push_back(pTmp);
  while(!queue.empty()){
    pTmp = queue.pop_front();
    if(pTmp->m_data == t_data){
      while(!visitedQueue.empty()){
        pTmp = visitedQueue.pop_front();
        pTmp->m_visited = false;
      }
      return true;
    }
    if(!pTmp->m_visited){
      pTmp->m_visited = true;
      visitedQueue.push_back(pTmp);
      for(int i = 0; i < pTmp->m_pAdyacentNodes.count(); i++){
        queue.push_back(pTmp->m_pAdyacentNodes.at(i));
      }
    }
  }
  while(!visitedQueue.empty()){
    pTmp = visitedQueue.pop_front();
    pTmp->m_visited = false;
  }
  return false;
}

/**
 * @brief Adds a new node to the graph.
 * @param t_data   The data for the new node to be added.
 * @param t_parent The data of an existing node to which the new node will be connected.
 * @throws std::invalid_argument if t_data is equal to t_parent.
 * @throws std::out_of_range    if the specified parent node doesn't exist in the graph.
 */
template <class T>
void Graph<T>::add(T t_data, T t_parent){
  if(t_data == t_parent){
    throw std::invalid_argument("t_data can't be equal to t_parent.");
  }
  if(!bool_DFS(t_parent)){
    throw std::out_of_range("Parent doesn't exist.");
  }
  if(bool_BFS(t_data)){
    Node* parentNode = node_BFS(t_parent);
    Node* dataNode = node_BFS(t_data);
    parentNode->m_pAdyacentNodes.push_back(dataNode);
    return;
  }
  Node* parentNode = node_BFS(t_parent);
  Node* newNode = generateNode(t_data);
  parentNode->m_pAdyacentNodes.push_back(newNode);
}

/**
 * @brief Clear the graph, removing all nodes and their connections.
 */
template <class T>
void Graph<T>::clear(){
  Node* pTmp = m_pRoot;
  Queue<Node*> queue;
  queue.push_back(pTmp);
  while(!queue.empty()){
    pTmp = queue.pop_front();
    for(int i = 0; i < pTmp->m_pAdyacentNodes.count(); i++){
      queue.push_back(pTmp->m_pAdyacentNodes.at(i));
    }
    delete[] pTmp;
    pTmp = nullptr;
  }
}

/**
 * @brief Traverse and print the nodes of the graph in breadth-first order.
 */
template <class T>
void Graph<T>::traverse(){
  Node* pTmp = m_pRoot;
  Queue<Node*> queue;
  Queue<Node*> visitedQueue;
  queue.push_back(pTmp);
  while(!queue.empty()){
    pTmp = queue.pop_front();
    if(!pTmp->m_visited){
      pTmp->m_visited = true;
      visitedQueue.push_back(pTmp);
      std::cout << pTmp->m_data << " {";
      for(int i = 0; i < pTmp->m_pAdyacentNodes.count(); i++){
        std::cout << pTmp->m_pAdyacentNodes.at(i)->m_data << ", ";
        queue.push_back(pTmp->m_pAdyacentNodes.at(i));
      }
      std::cout << "}\n";
    }
  }
  std::cout << std::endl;
  while(!visitedQueue.empty()){
    pTmp = visitedQueue.pop_front();
    pTmp->m_visited = false;
  }
}