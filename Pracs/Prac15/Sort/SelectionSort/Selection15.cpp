#include "Selection15.h"

void Selection15::sort(std::span<int>& arr)
{
    if (arr.size() < 2)
    {
        return;
    }
    
    const size_t size = arr.size();
    for (size_t i = 0; i < size - 1; ++i)
    {
        size_t minIndex = i;
        for (size_t j = i + 1; j < size; ++j)
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
