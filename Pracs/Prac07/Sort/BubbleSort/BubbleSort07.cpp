#include "BubbleSort07.h"

void BubbleSort07::sort(int* arr, int size)
{
    if (arr == nullptr || size < 2)
    {
        return;
    }
    for (int i = 0 ; i < size - 1 ; ++i)
    {
        bool isSwapped = false;
        for (int j = 0 ; j < size - 1 - i;++j)
        {
            if (arr[j]> arr[j+1])
            {
                int temp = arr[j];
                arr[j]= arr[j+1];
                arr[j+1] = temp;
                isSwapped = true;
            }
        }
        if (isSwapped == false)
        {
            break;
        }
    }
}
