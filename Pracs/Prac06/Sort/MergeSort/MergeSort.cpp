#include "MergeSort.h"

#include <vector>

void MergeSort::mergeSort(int* arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void MergeSort::merge(int* arr, int left, int mid, int right)
{
    int lSize = mid - left + 1;
    int rSize = right - mid;

    std::vector<int> l(lSize), r(rSize);
    std::copy(arr + left, arr + mid + 1, l.begin());
    std::copy(arr + mid + 1, arr + right + 1, r.begin());

    int newIndex = left;
    int lIndex = 0;
    int rIndex = 0;
    while (lIndex < l.size() && rIndex < r.size())
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

    while (lIndex < l.size())
    {
        arr[newIndex++] = l[lIndex++];
    }

    while (rIndex < r.size())
    {
        arr[newIndex++] = r[rIndex++];
    }
}
