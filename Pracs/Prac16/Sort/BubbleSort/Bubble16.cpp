#include "Bubble16.h"

#include <concepts>

void Bubble16::sort(int* arr, int size)
{
    if (size < 2)
    {
        return;
    }

    for (int i = 0 ; i < size - 1; i++)
    {
        bool isSwapped = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
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
