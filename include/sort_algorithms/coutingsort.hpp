#ifndef COUNTING
#define COUNTING

template <typename T>
void CountingSort(T arr[], int size, const T &max)
{
   CountingPair<T> *count = new CountingPair<T>[max.key + 1];

   for (int i = 0; i < size; ++i)
   {
      count[arr[i].key].first = arr[i];
      count[arr[i].key].second++;
   }

   int k = 0;
   for (int i = 0; i <= max.key; i++)
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