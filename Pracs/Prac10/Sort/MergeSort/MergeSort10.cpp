#include "MergeSort10.h"

void MergeSort10::sort(int* arr, size_t size)
{
    tempVector.resize(size);
    mergeSort(arr,0,size - 1);
}

void MergeSort10::mergeSort(int* arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr,left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void MergeSort10::merge(int* arr, int left, int mid, int right)
{
    for (size_t lIndex = left; lIndex < mid + 1; ++lIndex)
    {
        tempVector[lIndex] = arr[lIndex];
    }

    for (size_t rIndex = mid + 1; rIndex < right + 1; ++rIndex)
    {
        tempVector[rIndex] = arr[rIndex];
    }
    int l = left;
    int r = mid + 1;
    int newIndex = left;
    while (l < mid + 1 && r < right + 1)
    {
        if (tempVector[l] <= tempVector[r])
        {
            arr[newIndex++] = tempVector[l++];
        }
        else
        {
            arr[newIndex++] = tempVector[r++];
        }
    }
    while (l < mid + 1)
    {
        arr[newIndex++] = tempVector[l++];
    }
    while (r < right + 1)
    {
        arr[newIndex++] = tempVector[r++];
    }
}
