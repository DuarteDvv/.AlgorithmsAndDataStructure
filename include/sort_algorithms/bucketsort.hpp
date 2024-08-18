#ifndef BUCKET
#define BUCKET

template <typename T>
void BucketSort(T arr[], int n, const T &max)
{

   if (n <= 0)
      return;

   double scale_factor = 1.0 / max.key;

   int number_of_buckets = n; // buckets
   int index_of_bucket;

   SortedLinkedList<T> buckets[number_of_buckets]; // array of buckets

   // put the elements on the bucket
   for (int i = 0; i < n; i++)
   {
      index_of_bucket = min((int)(arr[i].key * scale_factor * n), n - 1);

      buckets[index_of_bucket].insert(arr[i]);
   }

   int k = 0;
   // join the buckets
   for (int i = 0; i < number_of_buckets; i++)
   {
      for (int j = 0; j < buckets[i].getSize(); j++)
      {
         arr[k++] = buckets[i].getObject(j);
      }
   }
}

#endif