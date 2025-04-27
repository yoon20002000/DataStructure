#include "Selection11.h"
#include <memory>
void Selection11::sort(int* arr, size_t size)
{
    if (arr == nullptr || size < 2)
    {
        return;
    }
    for (size_t i = 0; i < size -1; i++)
    {
        size_t minIndex = i;
        for (size_t j = i + 1 ; j < size; j++)
        {
            if (arr[minIndex] > arr[j])
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
