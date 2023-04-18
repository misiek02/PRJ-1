//
// Created by ADMIN on 4/18/2023.
//

#ifndef PRJ_1_EDGELIST_H
#define PRJ_1_EDGELIST_H

#include <utility>
#include <vector>

template <typename T> class EdgeList {
public:
  // Typ reprezentujący krawędź w grafie
  using Edge = std::pair<T, T>;

  // Typ reprezentujący wagę krawędzi
  using Weight = T;

  // Konstruktor
  EdgeList();

  // Dodaj krawędź do listy
  void addEdge(const Edge &edge, const Weight &weight);

  // Pobierz listę krawędzi
  const std::vector<Edge> &getEdges() const;

  // Pobierz listę wag krawędzi
  const std::vector<Weight> &getWeights() const;

  // Wypisz listę krawędzi
  void printEdges();

private:
  std::vector<Edge> m_edges;     // Wektor do przechowywania krawędzi
  std::vector<Weight> m_weights; // Wektor do przechowywania wag krawędzi
};

// Implementacja konstruktora
template <typename T> EdgeList<T>::EdgeList() {}

// Implementacja metody addEdge()
template <typename T>
void EdgeList<T>::addEdge(const Edge &edge, const Weight &weight) {
  m_edges.push_back(edge);
  m_weights.push_back(weight);
}

// Implementacja metody getEdges()
template <typename T>
const std::vector<typename EdgeList<T>::Edge> &EdgeList<T>::getEdges() const {
  return m_edges;
}

// Implementacja metody getWeights()
template <typename T> const std::vector<T> &EdgeList<T>::getWeights() const {
  return m_weights;
}

template <typename T> void EdgeList<T>::printEdges() {
  std::cout << "---EDGES---" << std::endl;
  for (int i = 0; i < m_edges.size(); i++) {
    std::cout << m_edges[i].first << "-" << m_edges[i].second
              << " Weight: " << m_weights[i] << std::endl;
  }
}

#endif // PRJ_1_EDGELIST_H
