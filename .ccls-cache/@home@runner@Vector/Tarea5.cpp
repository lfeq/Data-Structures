#include "BinaryTree.hpp"
#include "Tarea5.h"

void tarea5(){
  int arr[] = {10, 3, 2, 0, -6, 2, 1, 56, -14};
  int arraySize = sizeof(arr) / sizeof(arr[0]);
  BinaryTree<int> tree(arr, arraySize);
  tree.print_tree();
  tree.add(11);
  tree.print_tree();
  std::cout << "Tree is empty? " << tree.empty() << "\n";
  tree.add(0);
  tree.print_tree();
  tree.add(2);
  tree.print_tree();
  std::cout << "Tree has 2? " << tree.find(2) << "\n";
  tree.erase(2);
  tree.print_tree();
  
}