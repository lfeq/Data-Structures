#include "ProyectoFinal.h"
#include "Tree.hpp"
#include "Graph.hpp"

void proyectoFinal() {
  int arr[] = {10, 20, 30, 0, 0, 0, 40, 50, 60};
  int arraySize = sizeof(arr) / sizeof(arr[0]);
  Tree<int> tree(1, arr, arraySize);
  std::cout << "Tree is empty? " << tree.empty() << "\n";
  tree.traverse();
  std::cout << "Tree has " << 1 <<  "? " << tree.bool_DFS(1) << "\n";
  tree.add(2, 1);
  tree.add(69, 0);
  tree.add(10, 0);
  tree.add(11, 0);
  tree.add(12, 0);
  tree.add(420, 69);
  tree.traverse();
  tree.erase(0);
  tree.traverse();
  tree.clear();
  std::cout << "Tree is empty? " << tree.empty() << "\n";
  std::cout << "------------ G R A F O ------------"<< "\n";
  Graph<int> graph(1, arr, arraySize);
  std::cout << "Graph is empty? " << graph.empty() << "\n";
  graph.traverse();
  graph.bool_DFS(1);
  graph.add(5, 1);
  graph.add(1, 5);
  graph.traverse();
}