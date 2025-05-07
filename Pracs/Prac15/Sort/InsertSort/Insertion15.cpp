#include "Insertion15.h"

void Insertion15::sort(std::span<int>& arr)
{
    size_t size = arr.size();
    if (size < 2)
    {
        return;
    }

    for (size_t i = 1; i < size; ++i)
    {
        int pivotItem = arr[i];
        size_t j = i;
        while (j > 0 && pivotItem < arr[j - 1])
        {
            arr[j]=arr[j-1];
            --j;
        }
        
        arr[j] = pivotItem;
    }
}
