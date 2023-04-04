#pragma once
template <typename Iterator>
Iterator our_partition(Iterator start, Iterator end) {
  auto pivot = end - 1;
  auto i = start;

  for (auto j = start; j < pivot; ++j) {
    if (*j <= *pivot) {
      auto tmp = *i;
      *i = *j;
      *j = tmp;
      ++i;
    }
  }

  auto tmp = *i;
  *i = *pivot;
  *pivot = tmp;

  return i;
}

template <typename Iterator> void quickSort(Iterator start, Iterator end) {
  if (std::distance(start, end) <= 1)
    return;

  Iterator pivot = our_partition(start, end);
  quickSort(start, pivot);
  quickSort(pivot + 1, end);
}