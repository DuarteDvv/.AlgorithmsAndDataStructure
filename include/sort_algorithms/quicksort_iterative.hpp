#ifndef QUICK_ITE
#define QUICK_ITE

template <typename T>
int partition_iterative(T arr[], int left, int right)
{

   int mid = left + (right - left) / 2;

   T pivotValue = median(arr[left], arr[mid], arr[right]);

   int pivotIndex;
   if (pivotValue == arr[left])
      pivotIndex = left;

   else if (pivotValue == arr[mid])
      pivotIndex = mid;
   else
      pivotIndex = right;

   swapp(arr[pivotIndex], arr[right]);

   int i = left - 1;
   for (int j = left; j <= right - 1; j++)
   {
      if (arr[j] <= pivotValue)
      {
         i++;
         swapp(arr[i], arr[j]);
      }
   }
   swapp(arr[i + 1], arr[right]);
   return (i + 1);
}

template <typename T>
void IterativeQuickSort(T arr[], int left, int right)
{
   if (left >= right)
      return;

   ArrayStack<int> stack;

   stack.stack(left);
   stack.stack(right);

   while (!stack.isEmpty())
   {
      right = stack.unstack();
      left = stack.unstack();

      int p = partition_iterative(arr, left, right);

      if (p - 1 > left)
      {
         stack.stack(left);
         stack.stack(p - 1);
      }

      if (p + 1 < right)
      {
         stack.stack(p + 1);
         stack.stack(right);
      }
   }
}

#endif