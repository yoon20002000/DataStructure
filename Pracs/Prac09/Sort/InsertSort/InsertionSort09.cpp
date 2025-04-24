#include "InsertionSort09.h"

void InsertionSort09::sort(int* arr, size_t size)
{
    if (arr == nullptr || size < 2)
    {
        return;
    }

    for (size_t i = 1; i < size; ++i)
    {
        int item = arr[i];
        size_t j = i;
        while (j != 0 && arr[j - 1] > item)
        {
            arr[j] = arr[j - 1];
            j--;
        }

        arr[j] = item;
    }
}
