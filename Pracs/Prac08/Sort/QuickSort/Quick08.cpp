#include "Quick08.h"
#include <memory>

void Quick08::quickSort(int* arr, int left, int right)
{
    if (left < right)
    {
        int pivot = partitionL(arr, left, right);
        quickSort(arr, left, pivot - 1);
        quickSort(arr, pivot + 1, right);

        // int pivot = partitionH(arr, left, right);
        // quickSort(arr, left, pivot);
        // quickSort(arr, pivot + 1, right);
    }
}

int Quick08::partitionL(int* arr, int left, int right)
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
                std::swap(arr[i], arr[pivot]);
            }
        }

        std::swap(arr[left], arr[pivot]);
    }

    return pivot;
}

int Quick08::partitionH(int* arr, int left, int right)
{
    int l = left - 1;
    int r = right + 1;
    int pivot = left + (right - left) / 2;
    int pivotItem = arr[pivot];
    while (true)
    {
        do
        {
            l++;
        }
        while (arr[l] < pivotItem);
        do
        {
            r--;
        }
        while (arr[r] > pivotItem);

        if (l < r)
        {
            std::swap(arr[l], arr[r]);
        }
        else
        {
            break;
        }
    }
    return r;
}
