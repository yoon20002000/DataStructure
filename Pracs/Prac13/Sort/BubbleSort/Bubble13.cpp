#include "Bubble13.h"

#include <memory>

void Bubble13::sort(std::span<int> arr)
{
    if (arr.size() < 2)
    {
        return;
    }

    for (size_t i = 0 ; i < arr.size() - 1; ++i)
    {
        bool isSwapped = false;
        for (size_t j = 0 ; j < arr.size() - 1 -i;++j)
        {
            if (arr[j] > arr[j+1])
            {
                std::swap(arr[j], arr[j+1]);
                isSwapped = true;
            }
        }
        if (!isSwapped)
        {
            break;
        }
    }
}

void Bubble13::advancedSort(std::span<int> arr)
{
    if (arr.size() < 2)
    {
        return;
    }
    size_t n = arr.size();
    while (n > 0)
    {
        size_t newN = 0;
        for (size_t i = 1; i < n; ++i)
        {
            if (arr[i] < arr[i-1])
            {
                std::swap(arr[i], arr[i - 1]);
                newN = i;
            }
        }
        n = newN;
    }
}
