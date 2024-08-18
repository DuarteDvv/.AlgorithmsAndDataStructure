#ifndef CONEX_COMP
#define CONEX_COMP

#include <vector>
#include "treeDSU.hpp"
#include "iostream"

void ComponentesConexas(int V, const std::vector<std::pair<int, int>> &E) // O(E a(V))
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
   }

   // Identificar e imprimir os componentes conexos
   for (int v = 0; v < V; ++v)
   {
      if (DSU.Find(v) == v)
      {
         std::cout << v << " é componente" << std::endl;
      }
   }
}

#endif