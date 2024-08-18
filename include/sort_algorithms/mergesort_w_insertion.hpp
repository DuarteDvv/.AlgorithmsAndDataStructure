#ifndef MERGE_INS
#define MERGE_INS

template <typename T>
void insertionSortForHybrid(T arr[], int left, int right)
{
   for (int i = left + 1; i <= right; i++)
   {
      T key = arr[i];
      int j = i - 1;
      while (j >= left && arr[j] > key)
      {
         arr[j + 1] = arr[j];
         j--;
      }
      arr[j + 1] = key;
   }
}

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
void UpgradedRecursiveMergeSort(T arr[], int left, int right)
{ // stable and adaptable
   if (left >= right)
      return;

   const int THRESHOLD = 10;

   int mid = left + (right - left) / 2;

   if (right - left + 1 <= THRESHOLD)
   { // upgrade
      insertionSortForHybrid(arr, left, right);
   }
   else
   {
      UpgradedRecursiveMergeSort(arr, left, mid);
      UpgradedRecursiveMergeSort(arr, mid + 1, right);
   }

   if (arr[mid] > arr[mid + 1])
      merge(arr, left, mid, right); // upgrade
}

#endif