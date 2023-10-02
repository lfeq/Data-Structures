#include "Program.h"
#include <iostream>
#include "Tree.hpp"
#include "Graph.hpp"

void run() {
  bool isRunning = true;
  while (isRunning) {
    std::string command = "";

    std::cout << "Enter a command to continue: \n";
    std::cout << "> Type 1 to create a new tree. \n";
    std::cout << "> Type 2 create a new graph. \n";
    std::cout << "> Type EXIT to end program. \n";

    std::cin >> command;

    if (command == "1") {
      createTree();
    }else if (command == "2"){
      createGraph();
    }else if (command == "EXIT" || command == "exit") {
      isRunning = false;
    }else{
      std::cout << "Invalid command. Please try again...\n";      
    }
  }
}

void createTree(){
  int number;
  std::cout << "> Type in a number that will be the root of the tree:\n";
  std::cin >> number;
  Tree<int> tree(number);
  bool isRunning = true;
  while (isRunning) {
    std::string command = "";

    std::cout << "Enter a command to continue: \n";
    std::cout << "> Type add to add a node to the tree. \n";
    std::cout << "> Type print to see the tree. \n";
    std::cout << "> Type dfs to check if a specific value exist in the tree. \n";
    std::cout << "> Type bfs to check if a specific value exist in the tree. \n";
    std::cout << "> Type clear to clear the tree from memory. \n";
    std::cout << "> Type EXIT to end program. \n";

    std::cin >> command;

    if (command == "add" || command == "ADD") {
      int data;
      int parent;
      std::cout << "Current tree: \n";
      tree.traverse();
      std::cout << "Enter a number to add to the tree: \n";
      std::cin >> data;
      std::cout << "Enter a number to be the parent of the new number (number should already exist in the tree): \n";
      std::cin >> parent;
      try{
        tree.add(data, parent);
        std::cout << "Tree after add: \n";
        tree.traverse();
      }catch(...){
        std::cout << "The number you want to use as parent doesn't exist in the current tree :( \n";
      }
    }else if (command == "print" || command == "PRINT"){
      tree.traverse();
    }else if (command == "dfs" || command == "DFS"){
      int data;
      std::cout << "Enter the number you want to know if its in the tree: \n";
      std::cin >> data;
      std::cout << "Tree has " << data <<  "? " << tree.bool_DFS(data) << "\n";
    }else if (command == "bfs" || command == "BFS"){
      int data;
      std::cout << "Enter the number you want to know if its in the tree: \n";
      std::cin >> data;
      std::cout << "Tree has " << data <<  "? " << tree.bool_DFS(data) << "\n";
    }else if (command == "clear" || command == "CLEAR") {
      tree.clear();
      isRunning = false;
    }else if (command == "EXIT" || command == "exit") {
      isRunning = false;
    }else{
      std::cout << "Invalid command. Please try again...\n";      
    }
  }
}

void createGraph(){
  int number;
  std::cout << "> Type in a number that will be the root of the graph:\n";
  std::cin >> number;
  Graph<int> graph(number);
  bool isRunning = true;
  while (isRunning) {
    std::string command = "";

    std::cout << "Enter a command to continue: \n";
    std::cout << "> Type add to add a node to the graph. \n";
    std::cout << "> Type print to see the graph. \n";
    std::cout << "> Type dfs to check if a specific value exist in the graph. \n";
    std::cout << "> Type bfs to check if a specific value exist in the graph. \n";
    std::cout << "> Type clear to clear the graph from memory. \n";
    std::cout << "> Type EXIT to end program. \n";

    std::cin >> command;

    if (command == "add" || command == "ADD") {
      int data;
      int parent;
      std::cout << "Current graph: \n";
      graph.traverse();
      std::cout << "Enter a number to add to the graph: \n";
      std::cin >> data;
      std::cout << "Enter a number to be the parent of the new number (number should already exist in the graph): \n";
      std::cin >> parent;
      try{
        graph.add(data, parent);
        std::cout << "Graph after add: \n";
        graph.traverse();
      }catch(...){
        std::cout << "The number you want to use as parent doesn't exist in the current graph :( \n";
      }
    }else if (command == "print" || command == "PRINT"){
      graph.traverse();
    }else if (command == "dfs" || command == "DFS"){
      int data;
      std::cout << "Enter the number you want to know if its in the graph: \n";
      std::cin >> data;
      std::cout << "Tree has " << data <<  "? " << graph.bool_DFS(data) << "\n";
    }else if (command == "bfs" || command == "BFS"){
      int data;
      std::cout << "Enter the number you want to know if its in the graph: \n";
      std::cin >> data;
      std::cout << "Tree has " << data <<  "? " << graph.bool_DFS(data) << "\n";
    }else if (command == "clear" || command == "CLEAR") {
      graph.clear();
      isRunning = false;
    }else if (command == "EXIT" || command == "exit") {
      isRunning = false;
    }else{
      std::cout << "Invalid command. Please try again...\n";      
    }
  }
}