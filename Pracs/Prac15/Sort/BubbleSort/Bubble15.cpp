#include "Bubble15.h"

#include <valarray>

void Bubble15::sort(std::span<int>& arr)
{
    size_t size = arr.size();
    for (size_t i = 0; i < size - 1; ++i)
    {
        bool bIsSwapped = false;
        for (size_t j = 0; j < size - i - 1; ++j)
        {
            if (arr[j] > arr[j+1])
            {
                bIsSwapped = true;
                std::swap(arr[j], arr[j+1]);
            }
        }
        if (!bIsSwapped)
        {
            break;
        }
    }
}
