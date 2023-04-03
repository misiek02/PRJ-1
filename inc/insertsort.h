#pragma once
#include "priority_queue.h"
#include <vector>

template <typename T>
void insertSort(typename std::vector<T>::iterator start,
                typename std::vector<T>::iterator end) {
  PriorityQueue<int> pque;
  typename std::vector<T>::iterator curr = start;
  while (curr != end) {
    pque.insert(*curr, *curr);
    curr++;
  }
  curr = start;
  while (curr != end) {
    *curr = pque.removeFront();
    curr++;
  }
}