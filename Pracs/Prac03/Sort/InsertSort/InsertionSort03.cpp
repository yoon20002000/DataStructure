﻿#include "InsertionSort03.h"

void InsertionSort03::sort(int* arr, int size)
{
    for (int i = 1; i < size; ++i)
    {
        int key = arr[i];
        int j = i ;
        while (j > 0 && arr[j-1] > key)
        {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = key;
    }
}
