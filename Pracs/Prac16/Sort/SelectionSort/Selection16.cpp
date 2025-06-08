#include "Selection16.h"

#include <list>

void Selection16::sort(int* arr, int size)
{
    if (size < 2)
    {
        return;
    }
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex= i;
        for (int j = i + 1; j < size; ++j)
        {
            if (arr[j] > arr[minIndex])
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
