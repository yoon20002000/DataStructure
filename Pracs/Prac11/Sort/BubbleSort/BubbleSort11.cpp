#include "BubbleSort11.h"

#include <memory>

void BubbleSort11::sort(int* arr, size_t size)
{
    if (arr == nullptr || size < 2)
    {
        return;
    }
    for (size_t i = 0; i < size - 1; ++i)
    {
        bool isSwapped = false;
        for (size_t j = 0; j < size - 1 - i; ++j )
        {
            if (arr[j]> arr[j+1])
            {
                std::swap(arr[j], arr[j + 1]);
                isSwapped = true;
            }
        }
        if (!isSwapped)
        {
            break;
        }
    }
}
