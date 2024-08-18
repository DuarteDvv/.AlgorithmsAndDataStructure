#ifndef DSU_ARRAY
#define DSU_ARRAY

template <typename T>
class Array_DSU
{
private:
   int tamanho;
   T *representantes;

public:
   Array_DSU(int quantidade_conjuntos);
   ~Array_DSU();
   void Make(T x);       // O(1)
   T Find(T x);          // O(1)
   void Union(T x, T y); // O(n)
};

template <typename T>
Array_DSU<T>::Array_DSU(int Q_sets)
{
   representantes = new T[Q_sets];
   tamanho = Q_sets;
   for (int i = 0; i < Q_sets; ++i)
   {
      Make(i);
   }
}

template <typename T>
Array_DSU<T>::~Array_DSU()
{
   delete[] representantes;
}

template <typename T>
void Array_DSU<T>::Make(T set)
{
   representantes[set] = set;
}

template <typename T>
T Array_DSU<T>::Find(T set)
{
   return representantes[set];
}

template <typename T>
void Array_DSU<T>::Union(T set1, T set2)
{
   T x = Find(set1);
   T y = Find(set2);

   if (x != y)
   {
      for (int i = 0; i < tamanho; ++i)
      {
         if (representantes[i] == y)
         {
            representantes[i] = x;
         }
      }
   }
}

#endif // DSU_ARRAY
