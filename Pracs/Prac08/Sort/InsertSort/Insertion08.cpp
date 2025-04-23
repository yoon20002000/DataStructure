#include "Insertion08.h"

void Insertion08::sort(int* arr, int size)
{
    if (arr == nullptr || size < 2)
    {
        return;
    }

    for (int i = 1; i < size; ++i)
    {
        int item = arr[i];
        int j = i;
        while (j > 0 && arr[j - 1] > item)
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = item;
    }
}
