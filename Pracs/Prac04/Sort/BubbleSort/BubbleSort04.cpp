#include "BubbleSort04.h"
#include <memory>


void BubbleSort04::sort(int* arr, int size)
{
    if (size < 2)
    {
        return;
    }
    
    for (int i = 0 ; i < size -1; ++i)
    {
        bool isSwapped = false;
        for (int j = 0; j < size - 1 - i; ++j)
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
