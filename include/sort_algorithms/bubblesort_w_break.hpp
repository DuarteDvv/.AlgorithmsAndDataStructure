#ifndef BUBBLESORT_W_BREAK
#define BUBBLESORT_W_BREAK

template <typename T>
void UpgradedBubbleSort(T arr[], int n)
{ // stable
   if (n <= 1)
      return;

   bool swapped;

   for (int i = 0; i < n; i++)
   { // For each element O(n)
      swapped = false;

      for (int j = 0; j < n - i - 1; j++)
      { // Find the max and put on the n - i position O(n)

         if (arr[j] > arr[j + 1])
         { // Compare 2 by 2
            T aux = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = aux;

            swapped = true;
         }
      }

      if (!swapped)
         break;
      ; // upgrade that reduce the comparations if ordered
   }
}

// Worst case: Moviments(O(n²) + aux*O(1) = O(n²)) Comparations(O(n²))
// Best case: Moviments(O(1)) Comparations(O(n²))
// Not adaptable in comp but it is in mov

#endif