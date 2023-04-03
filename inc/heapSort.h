#pragma once
#include "min_heap.h"

#include <vector>

template <typename T>
void heapSort(typename std::vector<T>::iterator start,
              typename std::vector<T>::iterator end) {
  int cap = std::distance(start, end);
  MinHeap<int> heap(cap);
  typename std::vector<T>::iterator curr = start;
  while (curr != end) {
    heap.insertKey(*curr);
    curr++;
  }
  curr = start;
  while (curr != end) {
    *curr = heap.extractMin();
    curr++;
  }
}
