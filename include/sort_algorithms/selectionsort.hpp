#ifndef SELECTION
#define SELECTION

template <typename T>
void SelectionSort(T arr[], int n)
{ // not stable

   int min; // Position of the minimum element

   for (int i = 0; i < n - 1; i++)
   { // For each positon O(n)

      min = i;

      for (int j = i + 1; j < n; j++)
      { // find the minimum O(n)
         if (arr[j] < arr[min])
            min = j;
      }

      T aux = arr[i];
      arr[i] = arr[min]; // swapp
      arr[min] = aux;
   }
}

// Worst case: Moviments(O(n)) Comparations(O(n²))
// Best case: Moviments(O(n)) Comparations(O(n²))
// not adaptable in moviments and not in comparations

#endif