#include "Array.h"
#include "binary_tree.h"
#include "bubblesort.h"
#include "graph.h"
#include "heapSort.h"
#include "insertsort.h"
#include "list.h"
#include "min_heap.h"
#include "priority_queue.h"
#include "queueTab.h"
#include "singly_linked_list.h"
#include "stackList.h"
#include "stackTab.h"
//#include <SFML/Graphics.hpp>
#include <iostream>
#include <quicksort.h>

int main() {
  //     QueueTab<int> y(4);
  //     y.enqueue(2.011);
  //     y.enqueue(4.99);
  //     y.enqueue(4.99);
  //     y.enqueue(4.99);
  //     float g = y.size();
  //     std::cout<<g<<std::endl;

  //     Linkedlist<int> list;

  //     //Stack
  //     StackTab<int> s;

  //     // Push the elements of stack
  //     s.push(11);
  //     s.push(22);
  //     s.push(33);
  //     s.push(44);
  // /*
  //     // Display stack elements
  //     s.display();

  //     // Print top element of stack
  //     cout << "\nTop element is " << s.peek() << endl;

  //     // Delete top elements of stack
  //     s.pop();
  //     s.pop();

  //     // Display stack elements
  //     s.display();

  //     // Print top element of stack
  //     cout << "\nTop element is " << s.peek() << endl;
  //     */

  //     //List

  //     list.instertCell(1);
  //     list.instertCell(2);
  //     list.instertCell(3);
  //     list.instertCell(6);

  //     cout << "Elements of the list are: ";

  //     // Print the list
  //     list.printList();
  //     cout << endl;

  //     // Delete node at position 2.
  //     list.deleteCell(2);

  //     cout << "Elements of the list are: ";
  //     list.printList();
  //     cout << endl;

  //     //Stack
  //     StackList<int> ss;
  //     ss.push(2);
  //     ss.top();

  //     Array<int> arr(5);

  //     arr.add(1);
  //     arr.add(2);
  //     arr.add(3);

  //     //Tab

  //     std::cout << arr[0] << std::endl; // prints "1"
  //     std::cout << arr[1] << std::endl; // prints "2"
  //     std::cout << arr[2] << std::endl; // prints "3"

  //     arr.remove(1);

  //     std::cout << arr[0] << std::endl; // prints "1"
  //     std::cout << arr[1] << std::endl; // prints "3"

  //     std::cout << arr.find(1) << std::endl; // prints "0"
  //     std::cout << arr.find(2) << std::endl; // prints "-1"

  // SinglyLinkedList<int> list;
  // list.insert(999, 3);

  // PriorityQueue<int> pque;
  // int x;
  // x = pque.empty();
  // pque.insert(87, 9);
  // pque.insert(87, 4);
  // pque.insert(94, 3);
  // pque.insert(9, 8);

  // pque.insert(5129, 1);
  // pque.insert(239, 1);
  // pque.insert(4219, 1);

  // BinaryTree<int> tree;

  // tree.addNode(50);
  // tree.addNode(25);
  // tree.addNode(75);
  // tree.addNode(12);
  // tree.addNode(37);
  // tree.addNode(43);
  // tree.addNode(30);
  // tree.addNode(300);

  // tree.preOrderTraversal(tree.root);
  // std::cout << '\n';
  // tree.inOrderTraversal(tree.root);
  // std::cout << '\n';
  // tree.postOrderTraversal(tree.root);
  // std::cout << '\n';

  // std::cout << tree.height(tree.root) << " - Tree height" << '\n';

  // // std::vector<int> vec;
  // // for (int i = 0; i < 100; ++i) {
  // //   int randomNumber = std::rand() % 100;
  // //   vec.push_back(randomNumber);
  // // }
  // // heapSort<int>(vec.begin(), vec.end());

  // // for (auto v : vec) {
  // // std:
  // //   cout << v << std::endl;
  // // }

  // MinHeap<int> heap(10);
  // heap.insertKey(21);
  // heap.insertKey(2121);
  // heap.insertKey(1);
  // heap.insertKey(35);
  // heap.insertKey(52);
  // heap.insertKey(64);
  // heap.insertKey(-77);
  // std::cout << "safdsafsf" << std::endl;
  // std::cout << heap.extractMin() << std::endl;
  // std::cout << heap.extractMin() << std::endl;
  // std::cout << heap.extractMin() << std::endl;
  // std::cout << heap.extractMin() << std::endl;

  Graph<int> g;

  g.addEdge(0, 4);
  g.addEdge(230, 11);
  g.addEdge(55, 432);
  g.addEdge(21, 43);
  g.addEdge(21, 76);
  g.addEdge(98, 22);
  g.addEdge(222, 69);
  g.addEdge(21, 33);
  g.printGraph();

  return 0;
}