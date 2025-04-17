#include "BubblePrac03.h"

#include <fstream>
#include <memory>

void BubblePrac03::sort(int* arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        bool isSwapped = false;
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j+1] < arr[j])
            {
                std::swap(arr[j], arr[j+1]);
                isSwapped = true;
            }
        }
        if (isSwapped == false)
        {
            break;
        }
    }
}
