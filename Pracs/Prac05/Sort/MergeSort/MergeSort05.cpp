#include "MergeSort05.h"

#include <memory>

void MergeSort05::mergeSort(int* arr, int left, int right)
{
    if (arr== nullptr)
    {
        return;
    }
    
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void MergeSort05::merge(int* arr, int left, int mid, int right)
{
    int lSize = mid - left + 1;
    int rSize = right - mid;

    int* l = new int[lSize];
    int* r = new int[rSize];
    std::copy(arr + left, arr + mid + 1, l);
    std::copy(arr + mid + 1, arr + right + 1, r);
    
    int newIndex = left;
    int lIndex = 0;
    int rIndex = 0;
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
    while (lIndex < lSize )
    {
        arr[newIndex++] = l[lIndex++];
    }
    while (rIndex < rSize)
    {
        arr[newIndex++] = r[rIndex++];
    }

    delete[] l;
    delete[] r;
}
