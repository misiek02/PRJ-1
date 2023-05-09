#pragma once
#define V 5

int minKey(int key[], bool mstSet[]) {

  int min = INT_MAX, min_index;

  for (int v = 0; v < V; v++)
    if (mstSet[v] == false && key[v] < min)
      min = key[v], min_index = v;

  return min_index;
}

void printMST(int parent[], int graph[V][V]) {
  // int c{};
  std::cout << "Edges of minimum spanning tree: " << std::endl;
  for (int i = 1; i < V; i++) {

    std::cout << parent[i] << " - " << i << " cost: " << graph[i][parent[i]]
              << std::endl;
  }

  //   for (int i = 1; i < V; i++) {
  //     c += graph[i][parent[i]];
  //   }
  //   std::cout << "Total cost of minimum spanning tree: " << c << std::endl;
}

void primMST(int graph[V][V]) {
  int parent[V];
  int key[V];
  bool mstSet[V];

  for (int i = 0; i < V; i++) {
    key[i] = INT_MAX;
  }

  key[0] = 0;
  parent[0] = -1;

  for (int i = 0; i < V - 1; i++) {
    int u = minKey(key, mstSet);

    mstSet[u] = true;

    for (int i = 0; i < V; i++) {
      if (graph[u][i] && mstSet[i] == false && graph[u][i] < key[i]) {
        parent[i] = u;
        key[i] = graph[u][i];
      }
    }
  }

  printMST(parent, graph);
}