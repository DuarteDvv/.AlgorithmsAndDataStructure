#ifndef BUBBLESORT
#define BUBBLESORT

template <typename T>
void BubbleSort(T arr[], int n)
{
   // stable
   if (n <= 1)
      return;

   for (int i = 0; i < n; i++)
   { // For each element O(n)
      for (int j = 0; j < n - i - 1; j++)
      { // Find the max and put on the n - i position O(n)

         if (arr[j] > arr[j + 1])
         { // Compare 2 by 2
            T aux = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = aux;
         }
      }
   }
}

// Worst case: Moviments(O(n²) + aux*O(1) = O(n²)) Comparations(O(n²))
// Best case: Moviments(O(1)) Comparations(O(n²))
// Not adaptable in comp but it is in mov

#endif