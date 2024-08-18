#ifndef HEAPSORT
#define HEAPSORT

#include "tools.hpp"

template <typename T>
void verifySubTree(T array[], int n, int root) // O(log n)
{
   int i = root;

   while (true)
   {
      int biggest_son = 2 * i + 1;
      if (biggest_son >= n)
         break; // No children

      if (biggest_son + 1 < n && array[biggest_son] < array[biggest_son + 1])
      {
         biggest_son++;
      }

      if (array[i] >= array[biggest_son])
         break;

      swapp(array[i], array[biggest_son]);
      i = biggest_son;
   }
}

template <typename T>
void make_heap(T array[], int n) // O(nlogn)
{
   for (int i = n / 2 - 1; i >= 0; i--)
   {
      verifySubTree(array, n, i);
   }
}

template <typename T>
void Heapsort(T array[], int n) // O(nlogn)
{
   make_heap(array, n);

   for (int t = n - 1; t > 0; t--)
   {
      swapp(array[0], array[t]);
      verifySubTree(array, t, 0);
   }
}

// não estável

#endif
