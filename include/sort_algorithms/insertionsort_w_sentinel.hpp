#ifndef INS_SENT
#define INS_SENT

template <typename T>
void UpgradedInsertionSort(T arr[], int n)
{ // stable

   T aux;
   int j;

   // find the minimum element for sentinel
   int min = 0;
   for (int i = 1; i < n; i++)
   { // O(n)
      if (arr[i] < arr[min])
         min = i;
   }

   aux = arr[0];
   arr[0] = arr[min];
   arr[min] = aux;

   for (int i = 1; i < n; i++)
   { // for each O(n)

      aux = arr[i];
      j = i - 1;

      while (aux < arr[j])
      { // less one index comparations
         arr[j + 1] = arr[j];
         j--;
      }

      arr[j + 1] = aux;
   }
}

// Worst case: Moviments(O(n²)) Comparations(O(n²))
// Best case: Moviments(O(n)) Comparations(O(n))
// adaptable in moviments and in comparations

#endif