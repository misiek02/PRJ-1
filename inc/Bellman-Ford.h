//
// Created by ADMIN on 5/24/2023.
//

#ifndef PRJ_1_BELLMAN_FORD_H
#define PRJ_1_BELLMAN_FORD_H

#include <iostream>
#include <vector>
#include <limits>

template<typename T>
struct VerteX {
    T id;
    T distance;

    VerteX(T _id) : id(_id), distance(std::numeric_limits<T>::max()) {}
};

template<typename T>
struct EdgE {
    T source;
    T destination;
    int weight;

    EdgE(T _source, T _destination, int _weight) : source(_source), destination(_destination), weight(_weight) {}
};

template<typename T>
class Graphhh {
public:
    void AddVertex(T id) {
        vertices.push_back(VerteX<T>(id));
    }

    void AddEdge(T source, T destination, int weight) {
        edges.push_back(EdgE<T>(source, destination, weight));
    }

    void BellmanFord(T source) {
        VerteX<T>& sourceVertex = GetVertex(source);
        sourceVertex.distance = 0;

        // Relaksacja krawędzi (V-1) razy
        for (int i = 0; i < vertices.size() - 1; ++i) {
            for (const EdgE<T>& edge : edges) {
                VerteX<T>& u = GetVertex(edge.source);
                VerteX<T>& v = GetVertex(edge.destination);

                if (u.distance != std::numeric_limits<T>::max() && u.distance + edge.weight < v.distance) {
                    v.distance = u.distance + edge.weight;
                }
            }
        }

        // Sprawdzenie istnienia cykli o ujemnej sumie wag
        for (const EdgE<T>& edge : edges) {
            VerteX<T>& u = GetVertex(edge.source);
            VerteX<T>& v = GetVertex(edge.destination);

            if (u.distance != std::numeric_limits<T>::max() && u.distance + edge.weight < v.distance) {
                std::cout << "Graf zawiera cykl o ujemnej sumie wag" << std::endl;
                return;
            }
        }
    }

    void PrintShortestDistances() {
        for (const VerteX<T>& vertex : vertices) {
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
    std::vector<VerteX<T>> vertices;
    std::vector<EdgE<T>> edges;

    VerteX<T>& GetVertex(T id) {
        for (auto& vertex : vertices) {
            if (vertex.id == id) {
                return vertex;
            }
        }
        throw std::runtime_error("Vertex not found");
    }
};
#endif //PRJ_1_BELLMAN_FORD_H
