#ifndef SELECTION_MINMAX
#define SELECTION_MINMAX

template <typename T>
void UpgradedSelectionSort(T arr[], int n)
{

   for (int i = 0; i < n / 2; i++)
   {

      int min = i; // max
      int max = i; // min

      for (int j = i + 1; j < n - i; j++)
      { // finds max and min
         if (arr[j] < arr[min])
            min = j;
         else if (arr[j] > arr[max])
            max = j;
      }

      // swapp min with the first
      if (min != i)
      {
         T aux = arr[i];
         arr[i] = arr[min];
         arr[min] = aux;
      }

      if (max == i)
         max = min;

      // Swapp max with final element
      if (max != n - i - 1)
      {
         T aux = arr[n - i - 1];
         arr[n - i - 1] = arr[max];
         arr[max] = aux;
      }
   }
}

#endif