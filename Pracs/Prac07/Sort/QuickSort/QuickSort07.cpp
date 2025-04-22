#include "QuickSort07.h"

void QuickSort07::quickSort(int* arr, int left, int right)
{
    if (left < right)
    {
        int pivot = partitionH(arr, left, right);
        quickSort(arr, left, pivot - 1);
        quickSort(arr, pivot + 1, right);
    }
}

int QuickSort07::partitionL(int* arr, int left, int right)
{
    int pivot = left;
    int pivotItem = arr[pivot];

    if (left < right)
    {
        for (int i = left + 1; i <= right; ++i)
        {
            if (arr[i] < pivotItem)
            {
                ++pivot;
                int temp = arr[i];
                arr[i] = arr[pivot];
                arr[pivot] = temp;
            }
        }
        int temp = arr[left];
        arr[left] = arr[pivot];
        arr[pivot] = temp;
    }

    return pivot;
}

int QuickSort07::partitionH(int* arr, int left, int right)
{
    int pivotIndex = left + (right - left) / 2;
    int pivotItem = arr[pivotIndex];

    int l = left - 1;
    int r = right + 1;
    while (true)
    {
        do { l++; }
        while (arr[l] < pivotItem);

        do { r--; }
        while (arr[r] > pivotItem);

        if (l < r)
        {
            int temp = arr[l];
            arr[l] = arr[r];
            arr[r] = temp;
        }
        else
        {
            return r;
        }
    }
}
