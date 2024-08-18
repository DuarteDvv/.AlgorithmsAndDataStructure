#ifndef DET_CICLOS
#define DET_CICLOS

#include <vector>
#include "treeDSU.hpp"
#include "iostream"

bool DeteccaodeCiclos(int V, const std::vector<std::pair<int, int>> &E)
{
   Tree_DSU<int> DSU(V);

   // Inicialização dos conjuntos disjuntos
   for (int v = 0; v < V; ++v)
   {
      DSU.Make(v);
   }

   // Processar cada aresta
   for (const auto &edge : E)
   {
      int u = edge.first;
      int v = edge.second;
      if (DSU.Find(u) != DSU.Find(v))
      {
         DSU.Union(u, v);
      }
      else
      {
         return true; // Ciclo detectado
      }
   }

   return false; // Nenhum ciclo detectado
}

#endif