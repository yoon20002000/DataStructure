#include "SelectionSort04.h"
#include <memory>

void SelectionSort04::sort(int* arr, int size)
{
    if (size < 2)
    {
        return;
    }
    for (int i = 0 ; i < size; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j)
        {
            if (arr[minIndex] > arr[j])
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            std::swap(arr[i], arr[minIndex]);
        }
    }
}
