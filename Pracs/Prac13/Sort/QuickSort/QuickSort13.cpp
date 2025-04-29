#include "QuickSort13.h"

void QuickSort13::sort(std::span<int> arr)
{
    if (arr.size() < 2)
    {
        return;
    }
    quickSortL(arr, 0, arr.size() - 1);
}

void QuickSort13::sortMOT(std::span<int> arr)
{
    if (arr.size() < 2)
    {
        return;
    }
    quickSortMOT(arr, 0, arr.size() - 1);
}

int QuickSort13::partitionL(std::span<int> arr, int left, int right)
{
    int pivotIndex = left;
    int pivotItem = arr[pivotIndex];

    for (size_t i = left + 1; i <= right; ++i)
    {
        if (pivotItem > arr[i])
        {
            ++pivotIndex;
            std::swap(arr[pivotIndex], arr[i]);
        }
    }

    std::swap(arr[left], arr[pivotIndex]);
    return pivotIndex;
}

void QuickSort13::quickSortL(std::span<int> arr, int left, int right)
{
    if (left < right)
    {
        int pivot = partitionL(arr, left, right);
        quickSortL(arr, left, pivot - 1);
        quickSortL(arr, pivot + 1, right);
    }
}

int QuickSort13::partitionH(std::span<int> arr, int left, int right)
{
    while (true)
    {
        int l = left - 1;
        int r = right + 1;
        int pivotItem = arr[left + (right - left) / 2];

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

void QuickSort13::quickSortH(std::span<int> arr, int left, int right)
{
    if (left < right)
    {
        int pivot = partitionH(arr, left, right);
        quickSortH(arr, left, pivot);
        quickSortH(arr, pivot + 1, right);
    }
}

void QuickSort13::quickSortMOT(std::span<int> arr, int left, int right)
{
    if (left < right)
    {
        int pivotIndex = medianOfThree(arr, left, right);
        int pivotValue = arr[pivotIndex];

        std::swap(arr[pivotIndex], arr[right]);

        int partitionIndex = partition(arr, left, right - 1, pivotValue);

        std::swap(arr[partitionIndex], arr[right]);

        quickSortMOT(arr, left, partitionIndex - 1);
        quickSortMOT(arr, partitionIndex + 1, right);
    }
}

int QuickSort13::partition(std::span<int> arr, int left, int right, int pivot)
{
    while (true)
    {
        while (left <= right && arr[left] < pivot)
        {
            ++left;
        }
        while (left <= right && arr[right] > pivot)
        {
            --right;
        }

        if (left >= right)
        {
            break;
        }
        else
        {
            std::swap(arr[left], arr[right]);
            ++left;
            --right;
        }
    }
    return left;
}

int QuickSort13::medianOfThree(std::span<int> arr, int left, int right)
{
    int mid = left + (right - left) / 2;
    if (arr[left] > arr[mid])
    {
        std::swap(arr[left], arr[mid]);
    }
    if (arr[left] > arr[right])
    {
        std::swap(arr[left], arr[right]);
    }
    if (arr[mid] > arr[right])
    {
        std::swap(arr[mid], arr[right]);
    }

    return mid;
}
