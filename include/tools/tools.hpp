#ifndef TOOL
#define TOOL

#include <mutex>

// thread safe swapp
template <typename T>
void swapp(T &a, T &b)
{
    static std::mutex mutex;
    std::lock_guard<std::mutex> lock(mutex);

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

template <typename T>
T max2(const T &a, const T &b)
{
    return (a > b) ? a : b;
}

// min of two numbers
template <typename T>
T min(const T &a, const T &b)
{
    return (a < b) ? a : b;
}

template <typename T>
void copy_array(const T *source, T *destination, int size)
{
    for (int i = 0; i < size; ++i)
    {
        destination[i] = source[i];
    }
}

template <typename T>
T findmax(T arr[], int n)
{
    T max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

template <typename T>
T findmin(T arr[], int n)
{
    T min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

template <typename T>
void MaxMin(T arr[], int n, T *Max, T *Min, int *max_index = nullptr, int *min_index = nullptr)
{
    int i, end_loop;

    if ((n % 2) > 0)
    {
        arr[n] = arr[n - 1];
        end_loop = n;
    }
    else
    {
        end_loop = n - 1;
    }

    if (arr[0] > arr[1])
    {
        *Max = arr[0];
        *Min = arr[1];
        if (max_index)
            *max_index = 0;
        if (min_index)
            *min_index = 1;
    }
    else
    {
        *Max = arr[1];
        *Min = arr[0];
        if (max_index)
            *max_index = 1;
        if (min_index)
            *min_index = 0;
    }

    i = 3;

    while (i <= end_loop)
    {
        if (arr[i - 1] > arr[i])
        {
            if (arr[i - 1] > *Max && max_index)
            {
                *Max = arr[i - 1];
                *max_index = i - 1;
            }
            if (arr[i] < *Min && min_index)
            {
                *Min = arr[i];
                *min_index = i;
            }
        }
        else
        {
            if (arr[i - 1] < *Min && min_index)
            {
                *Min = arr[i - 1];
                *min_index = i - 1;
            }
            if (arr[i] > *Max && max_index)
            {
                *Max = arr[i];
                *max_index = i;
            }
        }
        i += 2;
    }
}

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
T median(T a, T b, T c)
{
    if ((a > b) ^ (a > c))
        return a;
    else if ((b < a) ^ (b < c))
        return b;
    else
        return c;
}

template <typename T>
class Cell
{
private:
    T object;
    Cell<T> *next;

public:
    Cell() : object(T()), next(nullptr) {};

    template <typename U>
    friend class LinkedList;

    template <typename U>
    friend class SortedLinkedList;

    template <typename U>
    friend class LinkedStack;
};

#endif