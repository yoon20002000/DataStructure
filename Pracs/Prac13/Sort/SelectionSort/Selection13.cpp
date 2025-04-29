#include "Selection13.h"

void Selection13::sort(std::span<int> arr)
{
    if (arr.size() < 2)
    {
        return;
    }
    for (size_t i = 0 ; i < arr.size() - 1; ++i)
    {
        size_t minIndex = i;
        for (size_t j = i + 1; j < arr.size(); ++j)
        {
            if (arr[minIndex] > arr[j])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            std::swap(arr[minIndex], arr[i]);    
        }
    }
}
