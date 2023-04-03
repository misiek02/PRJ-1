// https :  www.geeksforgeeks.org/binary-heap/
#pragma once
#include <climits>

template <typename T> void ourswap(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}
// swaps 2 pointers
template <typename T> void swap(T *a, T *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

template <typename T> class MinHeap {
  T *harr;
  int capacity;
  int heap_size;

public:
  // cap >0
  MinHeap(int cap);

  T parent(int i) { return (i - 1) / 2; }

  T left(int i) { return (2 * i + 1); }

  T right(int i) { return (2 * i + 2); }

  void insertKey(T key);
  void MinHeapify(int);          // heapify from i-th node
  T getMin() { return harr[0]; } // Returns the min key
  T extractMin();                // removes and returns min key
};

template <typename T> MinHeap<T>::MinHeap(int cap) {

  heap_size = 0;
  capacity = cap;
  harr = new int[cap];
}

template <typename T> void MinHeap<T>::insertKey(T k) {

  if (heap_size == capacity) {
    std::cout << "\nOverflow: Could not insertKey\n";
    return;
  }

  // First insert the new key at the end
  heap_size++;
  int i = heap_size - 1;
  harr[i] = k;

  // Fix the min heap property if it is violated
  while (i != 0 && harr[parent(i)] > harr[i]) {
    swap(&harr[i], &harr[parent(i)]);
    i = parent(i);
  }
}

// heapify from i-th node
template <typename T> void MinHeap<T>::MinHeapify(int i) {
  int l = left(i);
  int r = right(i);
  int smallest = i;
  if (l < heap_size && harr[l] < harr[i])
    smallest = l;
  if (r < heap_size && harr[r] < harr[smallest])
    smallest = r;
  if (smallest != i) {
    swap(&harr[i], &harr[smallest]);
    MinHeapify(smallest);
  }
}

template <typename T> T MinHeap<T>::extractMin() {
  if (heap_size <= 0)
    return INT_MAX;
  if (heap_size == 1) {
    heap_size--;
    return harr[0];
  }

  // Store the minimum value, and remove it from heap
  int root = harr[0];
  harr[0] = harr[heap_size - 1];
  heap_size--;
  MinHeapify(0);

  return root;
}