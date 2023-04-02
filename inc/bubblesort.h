#pragma once
#include "min_heap.h"
#include <vector>
template <typename T> void ourswap(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}

template <typename T>
void bubbleSort(typename std::vector<T>::iterator start,
                typename std::vector<T>::iterator end) {

  while (start != end) {
    typename std::vector<T>::iterator curr = start;
    while (curr != end - 1) {
      if (*curr > *(curr + 1))
        ourswap(*curr, *(std::next(curr)));

      curr++;
    }
    end--;
  }
}