#ifndef QUICK_SORT
#define QUICK_SORT

template <typename T>
void partition(T arr[], int left, int right, int *i, int *j)
{
   T pivot = arr[(left + right) / 2];

   T aux;

   *i = left;
   *j = right;

   while (*i <= *j) // divide the array in smaller than pivot and bigger than pivot
   {
      while (arr[*i] < pivot)
         (*i)++;

      while (arr[*j] > pivot)
         (*j)--;

      if ((*i) <= (*j))
      {

         aux = arr[*i];
         arr[*i] = arr[*j];
         arr[*j] = aux;

         (*i)++;
         (*j)--;
      }
   }
}

template <typename T>
void QuickSort(T arr[], int left, int right)
{
   if (left >= right)
      return;

   int i, j;

   partition(arr, left, right, &i, &j);

   if (left < j)
      QuickSort(arr, left, j);
   if (i < right)
      QuickSort(arr, i, right);
}

// O(nlogn) or O(n²)

#endif