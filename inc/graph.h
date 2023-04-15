#pragma once
#include <vector>

template <typename T> class Graph {

  std::vector<std::vector<T>> adj;

public:
  // Graph() { adj = new std::vector<std::vector<T>>; }
  void addEdge(int u, int v);
  void printGraph();
};

// template <typename T> void addEdge(std::vector<T> adj[], int u, int v) {
//   adj[u].push_back(v);
//   adj[v].push_back(u);
// }

// template <typename T> void printGraph(std::vector<T> adj[], int size) {
//   for (int i = 0; i < size; i++) {
//     std::cout << "\n Adjacency list of vertex " << i << "\n head ";
//     for (auto x : adj[i]) {
//       std::cout << "->" << x;
//     }
//     std::cout << '\n';
//   }
// }

template <typename T> void Graph<T>::addEdge(int u, int v) {
  std::vector<int> x;
  x.push_back(u);
  x.push_back(v);
  adj.push_back(x);
}

template <typename T> void Graph<T>::printGraph() {
  for (int i = 0; i < adj.size(); i++) {

    std::cout << adj[i][0] << "->" << adj[i][1];

    std::cout << '\n';
  }
}
