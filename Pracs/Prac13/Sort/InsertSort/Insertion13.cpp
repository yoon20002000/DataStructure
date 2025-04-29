#include "Insertion13.h"

void Insertion13::sort(std::span<int> arr)
{
    if (arr.size() < 2)
    {
        return;
    }
    for (size_t i = 1; i < arr.size(); ++i)
    {
        int key = arr[i];
        size_t j = i;
        while (j > 0 && arr[j - 1] > key)
        {
            arr[j] = arr[j - 1];
            --j;
        }
        arr[j] = key;
    }
}
