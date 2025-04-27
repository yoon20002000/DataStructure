#include "InsertionSort11.h"

void InsertionSort11::sort(int* arr, size_t size)
{
    if (arr == nullptr || size <2)
    {
        return;
    }

    for (size_t i = 1; i < size; ++i)
    {
        int key = arr[i];
        size_t j = i;
        while (j > 0 && arr[j-1] > key)
        {
            arr[j] = arr[j-1];
            --j;
        }
        arr[j] = key;
    }
}
