#include "MergeSort16.h"

#include <vector>

void MergeSort16::merge(int* arr, int left, int mid, int right)
{
    std::vector<int> l;
    std::vector<int> r;
    for (int i = left; i < mid + 1; ++i)
    {
        l.push_back(arr[i]);
    }
    for (int i = mid + 1; i <= right; ++i)
    {
        r.push_back(arr[i]);
    }

    int lIndex = 0;
    int lSize = mid - left + 1;
    int rIndex = 0;
    int rSize = right - mid;
    int newIndex = left;
    while (lIndex<lSize && rIndex<rSize)
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
    while (lIndex<lSize)
    {
        arr[newIndex++] = l[lIndex++];
    }
    while (rIndex<rSize)
    {
        arr[newIndex++] = r[rIndex++];
    }
}

void MergeSort16::mergeSort(int* arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
