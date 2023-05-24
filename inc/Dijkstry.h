//
// Created by ADMIN on 5/24/2023.
//

#ifndef PRJ_1_DIJKSTRY_H
#define PRJ_1_DIJKSTRY_H


#include <iostream>
#include <vector>
#include <queue>
#include <limits>

template<typename T>
struct Vertex {
    T id;
    T distance;
    bool visited;

    Vertex(T _id) : id(_id), distance(std::numeric_limits<T>::max()), visited(false) {}
};

template<typename T>
struct Edge {
    T source;
    T destination;
    int weight;

    Edge(T _source, T _destination, int _weight) : source(_source), destination(_destination), weight(_weight) {}
};

template<typename T>
class Graphh {
public:
    void AddVertex(T id) {
        vertices.push_back(Vertex<T>(id));
    }

    void AddEdge(T source, T destination, int weight) {
        edges.push_back(Edge<T>(source, destination, weight));
    }

    void Dijkstra(T source) {
        // Resetowanie wierzchołków
        for (auto& vertex : vertices) {
            vertex.distance = std::numeric_limits<T>::max();
            vertex.visited = false;
        }

        // Ustawienie wierzchołka źródłowego
        Vertex<T>& sourceVertex = GetVertex(source);
        sourceVertex.distance = 0;

        // Tworzenie kolejki priorytetowej
        std::priority_queue<std::pair<T, T>, std::vector<std::pair<T, T>>, std::greater<std::pair<T, T>>> pq;
        pq.push(std::make_pair(sourceVertex.distance, source));

        while (!pq.empty()) {
            // Pobieranie wierzchołka o najmniejszej odległości
            T currentVertex = pq.top().second;
            pq.pop();

            Vertex<T>& current = GetVertex(currentVertex);

            if (current.visited) {
                continue;
            }

            current.visited = true;

            // Aktualizacja odległości do sąsiednich wierzchołków
            for (const Edge<T>& edge : edges) {
                if (edge.source == current.id) {
                    Vertex<T>& destinationVertex = GetVertex(edge.destination);
                    int newDistance = current.distance + edge.weight;

                    if (newDistance < destinationVertex.distance) {
                        destinationVertex.distance = newDistance;
                        pq.push(std::make_pair(destinationVertex.distance, destinationVertex.id));
                    }
                }
            }
        }
    }

    void PrintShortestDistances() {
        for (const Vertex<T>& vertex : vertices) {
            std::cout << "Vertex " << vertex.id << ": ";
            if (vertex.distance == std::numeric_limits<T>::max()) {
                std::cout << "Unreachable";
            } else {
                std::cout << vertex.distance;
            }
            std::cout << std::endl;
        }
    }

private:
    std::vector<Vertex<T>> vertices;
    std::vector<Edge<T>> edges;

    Vertex<T>& GetVertex(T id) {
        for (auto& vertex : vertices) {
            if (vertex.id == id) {
                return vertex;
            }
        }
        throw std::runtime_error("Vertex not found");
    }
};
#endif //PRJ_1_DIJKSTRY_H
