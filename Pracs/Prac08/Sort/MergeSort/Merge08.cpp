#include "Merge08.h"

#include <vector>

void Merge08::mergeSort(int* arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr,left,mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

void Merge08::merge(int* arr, int left, int mid, int right)
{
    int lSize = mid - left + 1;
    int rSize = right - mid;

    std::vector<int> l(lSize), r(rSize);
    for (int i = 0; i < lSize; i++)
    {
        l[i]= arr[left + i];
    }

    for (int i = 0 ; i < rSize; i++)
    {
        r[i]= arr[mid + 1 + i];
    }

    int lIndex = 0, rIndex = 0;
    int newIndex = left;
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
