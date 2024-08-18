#ifndef MIN_TREE_GEN
#define MIN_TREE_GEN

#include <vector>
#include "treeDSU.hpp"
#include "iostream"

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include "MinPriorityQueueHeap.hpp"

// Supondo que as classes MinHeap e Array_DSU já estejam definidas anteriormente

struct Edge
{
   int u, v, weight;
   bool operator>(const Edge &other) const
   {
      return weight > other.weight;
   }

   bool operator<(const Edge &other) const
   {
      return weight < other.weight;
   }
};

int MinTreeGenerator(int V, std::vector<Edge> &edges)
{
   MinPriorityQueueHeap<Edge> minHeap(V);

   // Colocar todas as arestas no heap
   for (int i = 0; i < edges.size(); i++)
   {
      minHeap.enqueue(edges[i]);
   }

   Tree_DSU<int> DSU(V);
   for (int v = 0; v < V; ++v)
   {
      DSU.Make(v);
   }

   int contadorUnioes = 0;
   int custoTotal = 0;

   // Achando a árvore mínima
   while (!minHeap.isEmpty() && contadorUnioes < V - 1)
   {
      Edge e = minHeap.getMin_without_remove();
      minHeap.dequeue();

      int uRep = DSU.Find(e.u);
      int vRep = DSU.Find(e.v);

      if (uRep != vRep)
      {
         DSU.Union(uRep, vRep);
         contadorUnioes++;
         custoTotal += e.weight;
      }
   }

   return custoTotal;
}

#endif