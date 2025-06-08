#include "Insert16.h"

void Insert16::sort(int* arr, int size)
{
    if (size < 2)
    {
        return;
    }

    for (int i = 1 ; i < size; ++i)
    {
        int key = arr[i];
        int j = i;
        while (j > 0 && arr[j - 1] > key)
        {
            arr[j] = arr[j - 1];
            --j;
        }
        arr[j] = key;
    }
}
