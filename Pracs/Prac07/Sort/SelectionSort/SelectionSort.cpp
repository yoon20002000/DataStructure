#include "SelectionSort.h"

void SelectionSort::sort(int* arr, int size)
{
    if (arr ==nullptr || size < 2)
    {
        return;
    }

    for (int i = 0 ; i < size ; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j)
        {
            if (arr[minIndex]> arr[j])
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}
