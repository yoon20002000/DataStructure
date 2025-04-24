#include "Quick09.h"

#include <memory>

void Quick09::sort(int* arr, int size)
{
    if (arr == nullptr || size < 2)
    {
        return;
    }
    quickSort(arr, 0, size - 1);
}

void Quick09::quickSort(int* arr, int left, int right)
{
    if (left < right)
    {
        //lomuto(arr, left, right);
        hoare(arr,left,right);
    }
}

int Quick09::partitionL(int* arr, int left, int right)
{
    int pivotIdx = left;
    int pivotItem = arr[pivotIdx];
    if (left < right)
    {
        for (int i = left + 1; i <= right; ++i)
        {
            if (arr[i] < pivotItem)
            {
                ++pivotIdx;
                std::swap(arr[i], arr[pivotIdx]);
            }
        }

        std::swap(arr[left], arr[pivotIdx]);
    }
    return pivotIdx;
}

int Quick09::partitionH(int* arr, int left, int right)
{
    int l = left - 1;
    int r = right + 1;
    int pivotItem = arr[l + (r - l) / 2];
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
            return r;
        }
    }
}

void Quick09::lomuto(int* arr, int left, int right)
{
    int pivot = partitionL(arr, left, right);
    quickSort(arr, left, pivot - 1);
    quickSort(arr, pivot + 1, right);
}

void Quick09::hoare(int* arr, int left, int right)
{
    int pivot = partitionH(arr, left, right);
    quickSort(arr, left, pivot);
    quickSort(arr, pivot + 1, right);
}
