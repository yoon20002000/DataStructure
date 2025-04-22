#include "InsertionSort07.h"

void InsertionSort07::sort(int* arr, int size)
{
    if (arr == nullptr || size < 2)
    {
        return;
    }

    for (int i = 1 ; i < size ; ++i)
    {
        int pivotItem = arr[i];
        int j = i;
        while (j > 0 && arr[j-1] > pivotItem)
        {
            arr[j] = arr[j-1];
            j--;
        }

        arr[j] = pivotItem;
    }
}
