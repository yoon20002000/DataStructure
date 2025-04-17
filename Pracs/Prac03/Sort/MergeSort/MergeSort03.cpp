#include "MergeSort03.h"

#include <vector>

void MergeSort03::sort(int* arr, int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int mid = left + (right - left) / 2;
    sort(arr,left, mid);
    sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void MergeSort03::merge(int* arr, int left, int mid, int right)
{
    int lSize = mid - left + 1;
    int rSize = right - mid;
    int lIndex = 0;
    int rIndex = 0;

    std::vector<int> lArr(lSize);
    std::vector<int> rArr(rSize);

    for (int i = 0 ; i < lSize; i++)
    {
        lArr[i] = arr[left + i];
    }

    for (int i = 0 ; i < rSize; i++)
    {
        rArr[i] = arr[mid + 1 + i];
    }
        
    int newIndex = left;
    while (lIndex < lSize && rIndex < rSize)
    {
        if (lArr[lIndex] <= rArr[rIndex])
        {
            arr[newIndex] = lArr[lIndex];
            lIndex++;
            newIndex++;
        }
        else
        {
            arr[newIndex] = rArr[rIndex];
            rIndex++;
            newIndex++;
        }
    }

    while (lIndex< lSize)
    {
        arr[newIndex] = lArr[lIndex];
        lIndex++;
        newIndex++;
    }
    while (rIndex < rSize)
    {
        arr[newIndex] = rArr[rIndex];
        rIndex++;
        newIndex++;
    }
}
