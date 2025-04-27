#include "Merge11.h"

void Merge11::sort(int* arr, int size)
{
    std::vector<int> temp(size);
    
    mergeSort(arr, 0, size - 1, temp);
}

void Merge11::mergeSort(int* arr, int left, int right, std::vector<int>& temp)
{
    if (left < right)
    {
        int pivot = left + (right - left) / 2;
        mergeSort(arr, left, pivot, temp);
        mergeSort(arr, pivot + 1, right, temp);
        merge(arr, left, pivot, right, temp);
    }
}

void Merge11::merge(int* arr, int left, int mid, int right, std::vector<int>& temp)
{
    for (int i = left; i <= right; ++i)
    {
        temp[i] = arr[i];
    }

    int l = left;
    int r = mid + 1;
    int mergeIndex = left;
    while (l <= mid && r <= right)
    {
        if (temp[l] <= temp[r])
        {
            arr[mergeIndex++] = temp[l++];
        }
        else
        {
            arr[mergeIndex++] = temp[r++];
        }
    }

    while (l <= mid)
    {
        arr[mergeIndex++] = temp[l++];
    }
    while (r <= right)
    {
        arr[mergeIndex++] = temp[r++];
    }
}
