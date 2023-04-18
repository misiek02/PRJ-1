#pragma once
#include "adjacencyList.h"

template <typename T> class AdjacencyListWeighted : public AdjacencyList<T> {
  std::unordered_map<T, std::vector<T>> adjacencyList;

public:
  void edgeListToAdj(std::vector<std::pair<T, T>> edges,
                     std::vector<int> weights);
  void printAdjList();
};

template <typename T>
void AdjacencyListWeighted<T>::edgeListToAdj(std::vector<std::pair<T, T>> edges,
                                             std::vector<int> weights) {
  for (int i = 0; i < weights.size(); i++) {
    auto &e = edges[i];
    auto w = weights[i];
    adjacencyList[e.first].push_back(e.second);
    adjacencyList[e.first].push_back(w);
    adjacencyList[e.second].push_back(e.first);
    adjacencyList[e.second].push_back(w);
  }
}

template <typename T> void AdjacencyListWeighted<T>::printAdjList() {
  std::cout << "-- ADJACENCY LIST (VETTEX, WEIGHT) --" << std::endl;

  for (auto it = adjacencyList.begin(); it != adjacencyList.end(); it++) {
    std::cout << "Vertex " << it->first << ": ";
    for (int i = 0; i < it->second.size(); i += 2) {
      std::cout << "(" << it->second[i] << ", " << it->second[i + 1] << ")";
    }
    std::cout << "\n";
  }
}
