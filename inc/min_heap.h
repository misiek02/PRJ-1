#pragma once
template <typename T> class MinHeap {
  T *harr;
  int capacity;
  int heap_size;

public:
  // cap >0
  MinHeap(int cap) : capacity(cap), heap_size(0), harr(new int[cap]) {}

  T parent(int i) { return (i - 1) / 2; }
  T left(int i) { return (2 * i + 1); }
  T right(int i) { return (2 * i + 2); }

  void insertKey(T key);
  void minHeapify(int i);        // heapify from i-th node
  T getMin() { return harr[0]; } // Returns the min key
  T removeMin();                 // removes and returns min key
};

// swaps 2 pointers
template <typename T> void swap(T *a, T *b) {
  T *temp = a;
  a = b;
  b = temp;
}

template <typename T> void MinHeap<T>::insertKey(T key) {
  if (heap_size == capacity) {
    std::cout << "Overflow. Didn't insert key.\n";
    return;
  }

  heap_size++;
  int i = heap_size - 1;
  harr[i] = key;

  while (i != 0 && harr[parent(i)] > harr[i]) {
    swap(&harr[parent(i)], &harr[i]);
    i = parent(i);
  }
}
// heapify from i-th node
template <typename T> void MinHeap<T>::minHeapify(int i) {
  int l = left(i);
  int r = right(i);
  int smallest = i;

  if (l < heap_size && harr[i] > harr[l])
    smallest = l;
  if (l < heap_size && harr[smallest] > harr[right])
    smallest = l;
  if (i != 1) {
    swap(&harr[i], &harr[smallest]);
    minHeapify(smallest);
  }
}

template <typename T> T MinHeap<T>::removeMin() {

  if (heap_size == 1) {
    heap_size--;
    return harr[0];
  }

  T temp = harr[0];
  harr[0] = harr[heap_size - 1];
  minHeapify(0);
  heap_size--;

  return temp;
}
