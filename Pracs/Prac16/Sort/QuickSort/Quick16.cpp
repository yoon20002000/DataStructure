#include "Quick16.h"

#include <algorithm>
#include <filesystem>

int Quick16::partition(int* arr, int low, int high)
{
    int pivotIndex = low;
    int pivotValue = arr[low];
    for (int l = low + 1; l <= high; ++l)
    {
        if (arr[l] < pivotValue)
        {
            ++pivotIndex;
            std::swap(arr[l], arr[pivotIndex]);
        }
    }
    std::swap(arr[low], arr[pivotIndex]);
    return pivotIndex;
}

void Quick16::QuickSort(int* arr, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        QuickSort(arr, low, pivot - 1);
        QuickSort(arr, pivot + 1, high);
    }
}

int Quick16::partitionH(int* arr, int low, int high)
{
    while (true)
    {
        int l = low - 1;
        int r = high + 1;
        int pivotItem = arr[low + (high - low) / 2];
        do
        {
            ++l;
        }
        while (arr[l] < pivotItem);
        do
        {
            --r;
        }
        while (arr[r] > pivotItem);

        if (l >= r)
        {
            return r;
        }
        else
        {
            std::swap(arr[l], arr[r]);
        }
    }
}

void Quick16::QuickSortH(int* arr, int low, int high)
{
    if (low < high)
    {
        int pivot = partitionH(arr, low, high);
        QuickSortH(arr, low, pivot);
        QuickSortH(arr, pivot + 1, high);
    }
}
