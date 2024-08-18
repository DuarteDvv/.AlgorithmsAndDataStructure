#ifndef MERGE
#define MERGE

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
void RecursiveMergeSort(T arr[], int left, int right)
{ // stable and not adaptable
   if (left >= right)
      return;

   int mid = left + (right - left) / 2;

   RecursiveMergeSort(arr, left, mid);
   RecursiveMergeSort(arr, mid + 1, right);
   merge(arr, left, mid, right);
}

// O(nlogn) in all cases

#endif