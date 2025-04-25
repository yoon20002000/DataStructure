#include "QuickSort10.h"

#include <memory>

void QuickSort10::sortByL(int* arr, int left, int right)
{
    if (left < right)
    {
        int pivot = partitionL(arr, left, right);
        sortByL(arr, left, pivot - 1);
        sortByL(arr, pivot + 1, right);
    }
}

void QuickSort10::sortByH(int* arr, int left, int right)
{
    if (left < right)
    {
        int pivot = partitionH(arr, left, right);
        sortByH(arr, left, pivot);
        sortByH(arr, pivot + 1, right);
    }
}

int QuickSort10::partitionL(int* arr, int left, int right)
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

int QuickSort10::partitionH(int* arr, int left, int right)
{
    int l = left - 1;
    int r = right + 1;
    int pivotItem = arr[left + (right - left) / 2];
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

        if (l >= r)
        {
            break;
        }
        else
        {
            std::swap(arr[l], arr[r]);
        }
    }
    return r;
}
