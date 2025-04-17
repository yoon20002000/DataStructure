#include "QuickSort03.h"
#include <memory>

void QuickSort03::sort(int* arr, int left, int right)
{
    if (left < right)
    {
        int pivot = partitionL(arr, left, right);
        sort(arr, left, pivot - 1);
        sort(arr, pivot + 1, right);
    }
}

int QuickSort03::partitionL(int* arr, int left, int right)
{
    int pivotIndex = left;

    int pivotItem = arr[pivotIndex];

    for (int i = left + 1; i <= right; i++)
    {
        if (pivotItem > arr[i])
        {
            pivotIndex++;
            std::swap(arr[pivotIndex], arr[i]);
        }
    }

    if (pivotIndex != left)
    {
        std::swap(arr[pivotIndex], arr[left]);
    }

    return pivotIndex;
}

int QuickSort03::partitionH(int* arr, int left, int right)
{
    int pivotItem = arr[left];

    int i = left - 1;
    int j = right + 1;
    while (true)
    {
        do
        {
            left++;
        }
        while (arr[i] < pivotItem);
        do
        {
            right--;
        }
        while (arr[j] > pivotItem);
        if (i >= j)
        {
            return j;
        }
        std::swap(arr[i], arr[j]);
    }
}
