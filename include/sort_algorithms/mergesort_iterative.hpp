#ifndef MERGE_ITE
#define MERGE_ITE

template <typename T>
void merge(T arr[], int left, int mid, int right)
{
   int i = left;
   int j = mid + 1;
   int k = 0;

   T *aux = new T[right - left + 1]; // aux where we do the merge
   while ((i <= mid) && (j <= right))
   {
      if (arr[i] < arr[j])
         aux[k++] = arr[i++];

      else
         aux[k++] = arr[j++];
   }
   while (j <= right)
      aux[k++] = arr[j++];

   while (i <= mid)
      aux[k++] = arr[i++];

   for (i = left, k = 0; i <= right; i++, k++)
      arr[i] = aux[k]; // put the elements in the real array

   delete[] aux;
}

template <typename T>
void IterativeMergeSort(T arr[], int n)
{ // stable and not adaptable
   int left;
   int right;
   int mid;
   int interval;

   for (interval = 2; interval <= n; interval *= 2)
   { // start merging two by two
      for (int i = 0; i + interval - 1 < n; i += interval)
      {
         left = i;
         right = i + interval - 1;
         mid = (left + right) / 2;

         merge(arr, left, mid, right);
      }
   }

   if (interval / 2 < n)
      merge(arr, 0, (interval / 2) - 1, n - 1); // if some element
}

#endif