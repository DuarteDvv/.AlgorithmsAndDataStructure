
#ifndef NEGATIVE_COUNTING
#define NEGATIVE_COUNTING

template <typename T>
void NegativeCountingSort(T arr[], int size, const T &max, const T &min)
{
   int range = max.key - min.key + 1;

   // Count
   CountingPair<T> *count = new CountingPair<T>[range];

   // Initialize count array
   for (int i = 0; i < range; ++i)
   {
      count[i].second = 0;
   }

   for (int i = 0; i < size; ++i)
   {
      int index = arr[i].key - min.key;
      count[index].first = arr[i];
      count[index].second++;
   }

   int k = 0;
   for (int i = 0; i < range; ++i)
   {
      while (count[i].second > 0)
      {
         arr[k++] = count[i].first;
         count[i].second--;
      }
   }

   delete[] count;
}

#endif