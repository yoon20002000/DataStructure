#include "MergeSort04.h"

#include <vector>

void MergeSort04::sort(int* arr, int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int mid = (left + right)/2;
    sort(arr,left, mid);
    sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void MergeSort04::merge(int* arr, int left, int mid, int right)
{
    int lSize = mid - left + 1;
    int rSize = right - mid;
    std::vector<int> l(lSize), r(rSize);
    std::copy(arr + left, arr + mid + 1, l.begin());
    std::copy(arr + mid + 1, arr + right + 1, r.begin());

    int lIndex = 0, rIndex = 0;
    int arrIndex= left;
    while (lIndex < lSize && rIndex < rSize)
    {
        if (l[lIndex] < r[rIndex])
        {
            arr[arrIndex] = l[lIndex];
            lIndex++;
            arrIndex++;
        }
        else
        {
            arr[arrIndex] = r[rIndex];
            rIndex++;
            arrIndex++;
        }
    }

    while (lIndex < lSize)
    {
        arr[arrIndex] = l[lIndex];
        lIndex++;
        arrIndex++;
    }
    
    while (rIndex < rSize)
    {
        arr[arrIndex] = r[rIndex];
        rIndex++;
        arrIndex++;
    }
}
