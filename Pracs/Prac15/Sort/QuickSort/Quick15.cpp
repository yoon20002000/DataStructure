#include "Quick15.h"

#include <valarray>

void Quick15::sort(std::span<int>& arr)
{
    if (arr.size() < 2)
    {
        return;
    }

    quickSortL(arr, 0, arr.size() - 1);
}

void Quick15::quickSortL(std::span<int>& arr, int left, int right)
{
    if (left<right)
    {
        int pivot = partitionL(arr,left,right);
        quickSortL(arr, left, pivot - 1);
        quickSortL(arr, pivot + 1, right);
    }
}

int Quick15::partitionL(std::span<int>& arr, int left, int right)
{
    int pivotIndex = left;
    int pivotItem = arr[pivotIndex];
    if (left < right)
    {
        for (int i = left + 1; i <= right; ++i)
        {
            if (arr[i] < pivotItem)
            {
                pivotIndex++;
                std::swap(arr[i], arr[pivotIndex]);
            }
        }

        std::swap(arr[left], arr[pivotIndex]);
    }
    return pivotIndex;
}

void Quick15::quickSortH(std::span<int>& arr, int left, int right)
{
    if (left<right)
    {
        int pivot = partitionH(arr, left, right);
        quickSortH(arr, left, pivot);
        quickSortH(arr, pivot + 1, right);
    }
}

int Quick15::partitionH(std::span<int>& arr, int left, int right)
{
    int pivotItem = arr[left + (right - left) / 2];
    
    while (true)
    {
        int l = left - 1;
        int r = right + 1;
        
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
