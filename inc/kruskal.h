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
  T find(T i) {
    if (parent[i] == -1)
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

template <typename T> class Graph {
  vector<vector<T>> edgelist;
  int V;

public:
  Graph(int V) { this->V = V; }

  // Function to add edge in a graph
  void addEdge(T x, int y, T w) { edgelist.push_back({w, x, y}); }

  // KRUSKAL KRUSKAL
  void kruskal() {

    sort(edgelist.begin(), edgelist.end());

    DSU<T> s(V);
    int cost = 0;

    std::cout << "Edges of minimum spanning tree: " << std::endl;
    for (auto edge : edgelist) {
      int w = edge[0];
      int x = edge[1];
      int y = edge[2];

      // Take edge if doesnt form circuit
      if (s.find(x) != s.find(y)) {
        s.unite(x, y);
        cost += w;
        std::cout << x << " - " << y << " cost: " << w << std::endl;
      }
    }

    std::cout << "Total cost of minimum spanning tree: " << cost << std::endl;
  }
};