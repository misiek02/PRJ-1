#define CATCH_CONFIG_MAIN
#include "Array.h"
#include "bubblesort.h"
#include "catch2/catch.hpp"
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

// TEST_CASE( "Stack based on list tests" ) {
//     StackList<int> y;
//     REQUIRE(y.empty() == 1);
//     y.push(2);
//     REQUIRE(y.top() == 2 );
//     y.push(4);
//     REQUIRE(y.top() == 4 );
//     y.push(6);
//     REQUIRE(y.top() == 6 );
//     y.push(7);
//     REQUIRE(y.top() == 7 );
//     y.pop();
//     REQUIRE(y.top() == 6 );
//     y.pop();
//     REQUIRE(y.top() == 4 );
//     REQUIRE(y.empty() == 0);
//     REQUIRE(y.pop() == 4);
//     REQUIRE(y.pop() == 2);
//     REQUIRE(y.empty() == 1);

// }

// TEST_CASE( "Stack based on list tests II" ) {
//     StackList<int> stack;

//     stack.push(10);
//     stack.push(20);
//     stack.push(30);

//     REQUIRE(stack.pop() == 30);
//     REQUIRE(stack.pop() == 20);
//     REQUIRE(stack.pop() == 10);
//     REQUIRE(stack.empty() == true);
//     stack.push(10);
//     stack.push(20);
//     REQUIRE(stack.empty() == false);
//     stack.pop();
//     REQUIRE(stack.empty() == false);
//     stack.pop();
//     REQUIRE(stack.empty() == true);
//     stack.push(10);
//     stack.push(20);
//     REQUIRE(stack.top() == 20);
//     stack.pop();
//     REQUIRE(stack.top() == 10);

// }

// TEST_CASE( "Stack based on tab" ) {
//     StackTab<int> stack;

//     stack.push(10);
//     REQUIRE(stack.size() == 1);

//     stack.push(20);
//     //REQUIRE(stack.size() == 2);

//     stack.push(30);
//     REQUIRE(stack.size() == 3);

//     stack.push(10);
//     stack.push(20);
//     stack.push(30);

//     REQUIRE(stack.pop() == 30);
//     REQUIRE(stack.pop() == 20);
//     REQUIRE(stack.pop() == 10);

//     REQUIRE(stack.empty() == true);

//     stack.push(10);
//     stack.push(20);
//     REQUIRE(stack.empty() == false);

//     stack.pop();
//     REQUIRE(stack.empty() == false);

//     stack.pop();
//     REQUIRE(stack.empty() == true);

//     stack.push(10);
//     stack.push(20);

//     REQUIRE(stack.top() == 20);
//     REQUIRE(stack.size() == 2);
//     stack.pop();

//     REQUIRE(stack.top() == 10);
//     REQUIRE(stack.size() == 1);

// }

// TEST_CASE( "Queue based on tab" ) {

//   QueueTab<int> queue(2);

//     queue.enqueue(10);
//     queue.enqueue(20);

//     //REQUIRE(queue.empty() == false);

//     REQUIRE(queue.front() == 10);
//     REQUIRE(queue.size() == 2);
//     //REQUIRE(queue.dequeue() == 10);
//     //REQUIRE(queue.size() == 1);
//     REQUIRE(queue.front() == 20);

//     // queue.enqueue(30);
//     // queue.enqueue(40);

//     // REQUIRE(queue.size() == 3);

//     // REQUIRE(queue.dequeue() == 20);
//     // REQUIRE(queue.dequeue() == 30);
//     // REQUIRE(queue.dequeue() == 40);

//     //REQUIRE(queue.empty() == true);
// }

TEST_CASE("SinglyLinkedList I") {
  SinglyLinkedList<int> list;
  list.addFront(10);
  REQUIRE(list.front() == 10);
  list.addFront(20);
  REQUIRE(list.front() == 20);

  REQUIRE(list.size() == 2);

  REQUIRE(list.back() == 10);
  list.addBack(30);
  REQUIRE(list.back() == 30);

  REQUIRE(list.size() == 3);
}

TEST_CASE("SinglyLinkedList/isEmpty") {
  SinglyLinkedList<int> list;
  REQUIRE(list.empty() == true);
  list.addFront(10);
  REQUIRE(list.empty() == false);
  list.removeFront();
  REQUIRE(list.empty() == true);
}

TEST_CASE("SinglyLinkedList/indexing") {
  SinglyLinkedList<int> list;
  list.addFront(10);
  list.addFront(20);
  list.addFront(30);
  list.addFront(40);
  REQUIRE(list[0] == 40);
  REQUIRE(list[1] == 30);
  REQUIRE(list[2] == 20);
  REQUIRE(list[3] == 10);
}

// TEST_CASE("SinglyLinkedList/insert")
// {
//     SinglyLinkedList<int> list;
//     list.addBack(0);
//     list.addBack(10);
//     list.addBack(20);
//     list.addBack(30);
//     list.addBack(40);
//     list.addBack(50);
//     list.addBack(60);
//     list.addBack(70);
//     REQUIRE(list[3] == 30);
//     REQUIRE(list[4] == 40);

//      list.insert(69, 4);
//      REQUIRE(list[4] == 69);
//      list.insert(2137, 5);
//      REQUIRE(list[5] == 2137);
//      REQUIRE(list[2] == 20);
//      list.insert(3, 6);
//      list.insert(14, 7);
//      REQUIRE(list[6] == 3);
//      REQUIRE(list[7] == 14);
// }

TEST_CASE("SinglyLinkedList/remove") {
  SinglyLinkedList<int> list;
  list.addBack(10);
  list.addBack(20);
  list.addBack(10);
  REQUIRE(list.size() == 3);
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

  for (int i = 0; i < 30; ++i) {
    float randomNumber = std::rand() % 500;
    vec.push_back(randomNumber);
  }
  std::vector<float> v2 = vec;

  quickSort(vec.begin(), vec.end());
  sort(v2.begin(), v2.end());
  REQUIRE(vec == v2);
}
