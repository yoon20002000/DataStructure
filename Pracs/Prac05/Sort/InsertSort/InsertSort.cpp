#include "InsertSort.h"

void InsertSort::sort(int* arr, int size)
{
    if (arr == nullptr || size < 2)
    {
        return;
    }
    
    for (int i = 1 ; i < size; i++)
    {
        int key = arr[i];
        int j = i ;
        while (j > 0 && key< arr[j - 1])
        {
            arr[j]=arr[j-1];
            --j;
        }
        arr[j]=key;
    }
}
