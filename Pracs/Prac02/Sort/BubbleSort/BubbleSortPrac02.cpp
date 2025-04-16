#include "BubbleSortPrac02.h"

#include <list>

void BubbleSortPrac02::sort(int* arr, int size)
{
    for (int i = 0 ; i < size - 1; ++i)
    {
        bool swapped = false;
        for (int j = 0 ; j < size - 1 - i; ++j)
        {
            if (arr[j + 1] < arr[j])
            {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
        {
            break;
        }
    }
}
