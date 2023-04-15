#define CATCH_CONFIG_MAIN
#include "Array.h"
#include "bubblesort.h"
#include "catch2/catch.hpp"
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
#include <SFML/Graphics.hpp>
#include <iostream>
#include <quicksort.h>

TEST_CASE("Stack based on list tests") {
  StackList<int> y;
  REQUIRE(y.empty() == 1);
  y.push(2);
  REQUIRE(y.top() == 2);
  y.push(4);
  REQUIRE(y.top() == 4);
  y.push(6);
  REQUIRE(y.top() == 6);
  y.push(7);
  REQUIRE(y.top() == 7);
  y.pop();
  REQUIRE(y.top() == 6);
  y.pop();
  REQUIRE(y.top() == 4);
  REQUIRE(y.empty() == 0);
  REQUIRE(y.pop() == 4);
  REQUIRE(y.pop() == 2);
  REQUIRE(y.empty() == 1);
}

TEST_CASE("Stack based on list tests II") {
  StackList<int> stack;

  stack.push(10);
  stack.push(20);
  stack.push(30);

  REQUIRE(stack.pop() == 30);
  REQUIRE(stack.pop() == 20);
  REQUIRE(stack.pop() == 10);
  REQUIRE(stack.empty() == true);
  stack.push(10);
  stack.push(20);
  REQUIRE(stack.empty() == false);
  stack.pop();
  REQUIRE(stack.empty() == false);
  stack.pop();
  REQUIRE(stack.empty() == true);
  stack.push(10);
  stack.push(20);
  REQUIRE(stack.top() == 20);
  stack.pop();
  REQUIRE(stack.top() == 10);
}

TEST_CASE("SinglyLinkedList I") {
  SinglyLinkedList<int> list;
  list.addFront(10);
  REQUIRE(list.front() == 10);
  list.addFront(20);
  REQUIRE(list.front() == 20);

  REQUIRE(list.size() == 2);
}

TEST_CASE("SinglyLinkedList/isEmpty") {
  SinglyLinkedList<int> list;
  REQUIRE(list.empty() == true);
  list.addFront(10);
  REQUIRE(list.empty() == false);
  list.removeFront();
  REQUIRE(list.empty() == true);
}

TEST_CASE("SinglyLinkedList/remove") {
  SinglyLinkedList<int> list;
  list.addBack(10);
  list.addBack(20);
  list.addBack(10);
  REQUIRE(list.size() == 3);
}

TEST_CASE("PRIORITY_QUEUE 1") {
  PriorityQueue<int> pque;
  REQUIRE(pque.empty() == true);
  pque.insert(87, 9);
  REQUIRE(pque.empty() == false);
  pque.insert(82, 82);

  REQUIRE(pque.removeFront() == 87);
  pque.insert(94, 3);
  REQUIRE(pque.removeFront() == 94);
  pque.insert(9, 8);

  pque.insert(5129, 7);
  pque.insert(239, 1);
  pque.insert(4219, 3);

  REQUIRE(pque.removeFront() == 239);
}
TEST_CASE("HEAP 1") {
  MinHeap<int> heap(10);
  heap.insertKey(21);
  heap.insertKey(2121);
  heap.insertKey(1);
  heap.insertKey(35);
  heap.insertKey(52);
  heap.insertKey(64);
  heap.insertKey(-77);
  REQUIRE(heap.extractMin() == -77);
  REQUIRE(heap.extractMin() == 1);
  REQUIRE(heap.extractMin() == 21);
  REQUIRE(heap.extractMin() == 35);
  heap.insertKey(-52000000);
  heap.insertKey(1);
  heap.insertKey(4242);
  REQUIRE(heap.extractMin() == -52000000);
  REQUIRE(heap.extractMin() == 1);
}

TEST_CASE("BUUBLE_SORT 1") {
  std::vector<int> vec;

  for (int i = 0; i < 100; ++i) {
    int randomNumber = std::rand() % 100;
    vec.push_back(randomNumber);
  }
  std::vector<int> v2 = vec;

  bubbleSort<int>(vec.begin(), vec.end());
  sort(v2.begin(), v2.end());
  REQUIRE(vec == v2);
}

TEST_CASE("BUUBLE_SORT 2") {
  std::vector<float> vec;

  for (int i = 0; i < 100; ++i) {
    float randomNumber = std::rand() % 500;
    vec.push_back(randomNumber);
  }
  std::vector<float> v2 = vec;

  bubbleSort<float>(vec.begin(), vec.end());
  sort(v2.begin(), v2.end());
  REQUIRE(vec == v2);
}

TEST_CASE("Insert_SORT 1") {
  std::vector<int> vec;

  for (int i = 0; i < 124; ++i) {
    int randomNumber = std::rand() % 100;
    vec.push_back(randomNumber);
  }
  std::vector<int> v2 = vec;

  insertSort<int>(vec.begin(), vec.end());
  sort(v2.begin(), v2.end());
  REQUIRE(vec == v2);
}

TEST_CASE("INSERT_SORT 2") {
  std::vector<float> vec;

  for (int i = 0; i < 34; ++i) {
    float randomNumber = std::rand() % 500;
    vec.push_back(randomNumber);
  }
  std::vector<float> v2 = vec;

  insertSort<float>(vec.begin(), vec.end());
  sort(v2.begin(), v2.end());
  REQUIRE(vec == v2);
}

TEST_CASE("HEAP_SORT 1") {
  std::vector<int> vec;

  for (int i = 0; i < 124; ++i) {
    int randomNumber = std::rand() % 100;
    vec.push_back(randomNumber);
  }
  std::vector<int> v2 = vec;

  heapSort<int>(vec.begin(), vec.end());
  sort(v2.begin(), v2.end());
  REQUIRE(vec == v2);
}

TEST_CASE("HEAP_SORT 2") {
  std::vector<float> vec;

  for (int i = 0; i < 30; ++i) {
    float randomNumber = std::rand() % 500;
    vec.push_back(randomNumber);
  }
  std::vector<float> v2 = vec;

  heapSort<float>(vec.begin(), vec.end());
  sort(v2.begin(), v2.end());
  REQUIRE(vec == v2);
}

TEST_CASE("QUICK_SORT 1") {
  std::vector<int> vec;

  for (int i = 0; i < 232; ++i) {
    int randomNumber = std::rand() % 100;
    vec.push_back(randomNumber);
  }
  std::vector<int> v2 = vec;

  quickSort(vec.begin(), vec.end());
  sort(v2.begin(), v2.end());
  REQUIRE(vec == v2);
}

TEST_CASE("QUICK_SORT 2") {
  std::vector<float> vec;

  for (int i = 0; i < 332; ++i) {
    float randomNumber = std::rand() % 500;
    vec.push_back(randomNumber);
  }
  std::vector<float> v2 = vec;

  quickSort(vec.begin(), vec.end());
  sort(v2.begin(), v2.end());
  REQUIRE(vec == v2);
}
