#ifndef BEST_SHELL
#define BEST_SHELL

// sequence:  4^{k} + 3 * 2^{k-1} +1, prefixed with 1

template <typename T>
void SedgewickShellSort(T arr[], int n)
{
   int *gaps = new int[n];
   int k = 1;
   int gap = 1;
   int index = 0;

   while (gap < n)
   { // Calculate the nth term
      gaps[index++] = gap;
      k++;
      gap = pow(4, k) + 3 * pow(2, k - 1) + 1;
   }

   T aux;
   for (int i = index - 1; i >= 0; i--)
   { // Do insertion with interval gap
      gap = gaps[i];

      for (int j = gap; j < n; j++)
      {
         aux = arr[j];
         int k = j;
         while (k >= gap && arr[k - gap] > aux)
         {
            arr[k] = arr[k - gap];
            k -= gap;
         }
         arr[k] = aux;
      }
   }

   delete[] gaps;
}

// O(n^(4/3))

#endif