#ifndef RADIX
#define RADIX

int digit(int num, int w)
{ // shift
   return (num >> w) & 1;
}

template <typename T>
void quicksortBits(T arr[], int l, int r, int w)
{
   if (r <= l || w < 0)
      return;

   int i = l, j = r;
   while (j > i)
   {
      while (digit(arr[i].key, w) == 0 && (i < j))
         i++;
      while (digit(arr[j].key, w) == 1 && (j > i))
         j--;
      swapp(arr[i], arr[j]);
   }
   if (digit(arr[r].key, w) == 0)
      j++;

   quicksortBits(arr, l, j - 1, w - 1);
   quicksortBits(arr, j, r, w - 1);
}

template <typename T>
void RadixSort(T arr[], int l, int r)
{
   quicksortBits(arr, l, r, numbits - 1);
}

#endif