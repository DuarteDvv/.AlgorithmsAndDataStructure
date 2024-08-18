#ifndef INSERTION
#define INSERTION

template <typename T>
void InsertionSort(T arr[], int n)
{ // stable

   T aux;
   int j;

   for (int i = 1; i < n; i++)
   { // For each positon O(n)

      aux = arr[i];
      j = i - 1;
      while (j >= 0 && aux < arr[j])
      {
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