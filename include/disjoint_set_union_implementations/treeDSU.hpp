#ifndef TREE_DSU
#define TREE_DSU

template <typename T>
class Tree_DSU
{
private:
   int tamanho;
   T *parents;
   int *rank;

public:
   Tree_DSU(int quantidade_parents);
   ~Tree_DSU();
   void Make(T x);       // O(1)
   T Find(T x);          // O(α(n))
   void Union(T x, T y); // O(α(n))
};

template <typename T>
Tree_DSU<T>::Tree_DSU(int Q_sets)
{
   parents = new T[Q_sets];
   rank = new int[Q_sets];
   tamanho = Q_sets;
   for (int i = 0; i < Q_sets; ++i)
   {
      Make(i);
   }
}

template <typename T>
Tree_DSU<T>::~Tree_DSU()
{
   delete[] parents;
   delete[] rank;
}

template <typename T>
void Tree_DSU<T>::Make(T set)
{
   parents[set] = set;
   rank[set] = 0;
}

template <typename T>
T Tree_DSU<T>::Find(T set)
{
   if (parents[set] != set)
   {
      parents[set] = Find(parents[set]); // compressão de caminho
   }
   return parents[set];
}

template <typename T>
void Tree_DSU<T>::Union(T x, T y)
{
   T raiz_x = Find(x);
   T raiz_y = Find(y);
   if (raiz_x != raiz_y)
   {
      if (rank[raiz_x] < rank[raiz_y])
      {
         parents[raiz_x] = raiz_y;
      }
      else if (rank[raiz_x] > rank[raiz_y])
      {
         parents[raiz_y] = raiz_x;
      }
      else
      {
         parents[raiz_y] = raiz_x;
         rank[raiz_x]++;
      }
   }
}

#endif // TREE_DSU
