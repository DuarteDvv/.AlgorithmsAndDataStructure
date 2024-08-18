#ifndef SHELL
#define SHELL

template <typename T>
void DivideByTwoShellSort(T arr[], int n)
{ // Not stable with the sequence n/(2^i)
   T aux;
   int j;

   for (int right = n / 2; right > 0; right /= 2)
   { // for each term of sequence

      for (int i = right; i < n; i++)
      { // do insertion with interval right

         aux = arr[i];

         for (j = i; j >= right && arr[j - right] > aux; j -= right)
            arr[j] = arr[j - right];

         arr[j] = aux;
      }
   }
}

// O(n²)

#endif