#include "Quick11.h"

#include <list>

void Quick11::sort(int* arr, int size)
{
    quickSortL(arr, 0, size - 1);
    // quickSortH(arr, 0, size - 1);
}

void Quick11::quickSortL(int* arr, int left, int right)
{
    if (left < right)
    {
        int pivot = partitionL(arr, left, right);
        quickSortL(arr, left, pivot - 1);
        quickSortL(arr, pivot + 1, right);
    }
}

void Quick11::quickSortH(int* arr, int left, int right)
{
    if (left < right)
    {
        int pivot = partitionH(arr, left, right);
        quickSortH(arr, left, pivot);
        quickSortH(arr, pivot + 1, right);
    }
}

int Quick11::partitionL(int* arr, int left, int right)
{
    int pivotIndex = left;
    int pivotItem = arr[pivotIndex];

    for (int i = left + 1; i <= right; ++i)
    {
        if (pivotItem > arr[i])
        {
            ++pivotIndex;
            std::swap(arr[pivotIndex], arr[i]);
        }
    }
    std::swap(arr[pivotIndex], arr[left]);

    return pivotIndex;
}

int Quick11::partitionH(int* arr, int left, int right)
{
    while (true)
    {
        int pivotItem = arr[left + (right - left) / 2];
        int l = left - 1;
        int r = right + 1;

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
