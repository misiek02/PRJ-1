#pragma once
#include "EdgeList.h"
#include <algorithm>
#include <iostream>

// Disjoint set union
template <typename T> class DSU {
  T *parent;
  T *rank;

public:
  // Constructor
  DSU(int n) {
    parent = new T[n];
    rank = new T[n];

    for (int i = 0; i < n; i++) {
      parent[i] = -1;
      rank[i] = 1;
    }
  }

  // find function
  T find(int i) {
    if (i == -1)
      return i;

    return parent[i] = find(parent[i]);
  }

  // union function
  void unite(T x, T y) {
    T s1 = find(x);
    T s2 = find(y);

    if (s1 != s2) {
      if (rank[s1] < rank[s2]) {
        parent[s1] = s2;
      } else if (rank[s1] > rank[s2]) {
        parent[s2] = s1;
      } else {
        parent[s2] = s1;
        rank[s1] += 1;
      }
    }
  }
};

template <typename T> void kruskal(EdgeList<T> &edgeL) {

  int n = edgeL.getWeights().size();

  // edges vector with weight as 1 vector
  std::vector<std::vector<T>> ee(n);

  for (int i = 0; i < n; i++) {
    ee[i].push_back(edgeL.getWeights()[i]);
    ee[i].push_back(edgeL.getEdges()[i].first);
    ee[i].push_back(edgeL.getEdges()[i].second);
  }

  sort(ee.begin(), ee.end());

  for (int i = 0; i < n; i++) {
    std::cout << ee[i][0] << " ";
    std::cout << ee[i][1] << " ";
    std::cout << ee[i][2] << std::endl;
  }
}