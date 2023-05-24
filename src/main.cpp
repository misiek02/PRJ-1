#include "Array.h"
#include "adjacencyList.h"
#include "binary_tree.h"
#include "bubblesort.h"
#include "heapSort.h"
#include "insertsort.h"
#include "list.h"
#include "min_heap.h"
#include "priority_queue.h"
#include "queueTab.h"
#include "singly_linked_list.h"
#include "stackList.h"
#include "stackTab.h"
#include "Dijkstry.h"
#include "Bellman-Ford.h"
//#include <SFML/Graphics.hpp>
#include "EdgeList.h"
#include "adjacencyListWeighted.h"
#include "kruskal.h"
#include "weight.h"
#include <ctime>
#include <iostream>
#include <prim.h>
#include <quicksort.h>

int main() {
  // int V[] = {10, 100, 5000, 10000, 20000, 100000};
  // int n = sizeof(V) / sizeof(V[0]);

  // double times[n];

  // for (int i = 0; i < n; i++) {
  //   Graph<int> g(V[i]);

  //   // Add random edges to the graph
  //   srand(time(nullptr));
  //   for (int j = 0; j < V[i] * 5; j++) {
  //     int u = rand() % V[i];
  //     int v = rand() % V[i];
  //     int w = rand() % 100 + 1;
  //     g.addEdge(u, v, w);
  //   }

  //   clock_t start = clock();
  //   g.kruskal();
  //   clock_t end = clock();

  //   double duration = (double)(end - start) / CLOCKS_PER_SEC * 1000;
  //   times[i] = duration;
  // }

  // for (int i = 0; i < n; i++) {
  //   std::cout << "Time taken for " << V[i] << " vertices: " << times[i] <<
  //   "ms"
  //             << std::endl;
  // }

//  int graph[V][V] = {{0, 2, 0, 6, 0},
//                     {2, 0, 3, 8, 5},
//                     {0, 3, 0, 0, 7},
//                     {6, 8, 0, 0, 9},
//                     {0, 5, 7, 9, 0}};
//
//  // Print the solution
//  primMST(graph);
//
//  return 0;



    Graphhh<int> graph;
    graph.AddVertex(1);
    graph.AddVertex(2);
    graph.AddVertex(3);
    graph.AddVertex(4);
    graph.AddVertex(5);

    graph.AddEdge(1, 2, 10);
    graph.AddEdge(1, 3, 5);
    graph.AddEdge(2, 3, 2);
    graph.AddEdge(2, 4, 1);
    graph.AddEdge(3, 2, 3);
    graph.AddEdge(3, 4, 9);
    graph.AddEdge(3, 5, 2);
    graph.AddEdge(4, 5, 4);

    graph.BellmanFord(1);
    graph.PrintShortestDistances();
    return 0;
}
