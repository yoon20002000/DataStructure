#include "SelectionSort03.h"

#include <memory>
void SelectionSort03::sort(int* arr, int size)
{
    for (int i = 0 ; i < size ; ++i)
    {
        int minIndex = i;
        for (int j = i +1; j < size; ++j)
        {
            if (arr[j] < arr[minIndex])
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
