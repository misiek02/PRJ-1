#pragma once
#include "EdgeList.h"
#include <unordered_map>

template <typename T> class AdjacencyList {

  std::unordered_map<T, std::vector<T>> adjacencyList;

public:
  // Modiifies edge list ot adjacency list
  virtual void edgeListToAdj(std::vector<std::pair<T, T>> edges);
  virtual void printAdjList();
};

template <typename T>
void AdjacencyList<T>::edgeListToAdj(std::vector<std::pair<T, T>> edges) {

  for (auto &e : edges) {
    adjacencyList[e.first].push_back(e.second);
    adjacencyList[e.second].push_back(e.first);
  }
}

template <typename T> void AdjacencyList<T>::printAdjList() {
  std::cout << "-- ADJACENCY LIST --" << std::endl;

  for (auto it = adjacencyList.begin(); it != adjacencyList.end(); it++) {
    std::cout << "Vertex " << it->first << ": ";
    for (auto v : it->second) {
      std::cout << v << " ";
    }
    std::cout << "\n";
  }
}
