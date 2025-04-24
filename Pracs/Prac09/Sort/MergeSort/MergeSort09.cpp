#include "MergeSort09.h"

#include <vector>

void MergeSort09::mergeSort(int* arr, size_t left, size_t right)
{
    if (left < right)
    {
        size_t mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void MergeSort09::merge(int* arr, size_t left, size_t mid, size_t right)
{
    size_t lSize = mid - left + 1;
    size_t rSize = right - mid;

    std::vector<int> l(lSize), r(rSize);
    for (size_t i = 0; i < lSize; i++)
    {
        l[i] = arr[left + i];
    }
    for (size_t i = 0; i < rSize; i++)
    {
        r[i] = arr[mid + 1+ i];
    }

    size_t lIndex = 0, rIndex = 0;
    size_t newIndex = left;
    while (lIndex < lSize && rIndex < rSize)
    {
        if (l[lIndex] <= r[rIndex])
        {
            arr[newIndex++] = l[lIndex++];
        }
        else
        {
            arr[newIndex++] = r[rIndex++];
        }
    }

    while (lIndex < lSize)
    {
        arr[newIndex++] = l[lIndex++];
    }
    while (rIndex < rSize)
    {
        arr[newIndex++] = r[rIndex++];
    }
}
