#include "MergeSortPrac02.h"

#include <vector>

void MergeSortPrac02::sort(int* arr, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        sort(arr, left, mid);
        sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void MergeSortPrac02::merge(int* arr, int left, int mid, int right)
{
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    // std::vector<int> l;
    // std::vector<int> r;
    // l.reserve(leftSize);
    // r.reserve(rightSize);
    //
    // for (int i = left; i < left + leftSize; i++)
    // {
    //     l.push_back(arr[i]);
    // }
    // for (int i = mid + 1; i < mid + 1 + rightSize; i++)
    // {
    //     r.push_back(arr[i]);
    // }

    std::vector<int> l(leftSize);
    std::vector<int> r(rightSize);

    for (int i = 0; i < leftSize; i++)
    {
        l[i] = arr[left + i];
    }

    for (int i = 0; i < rightSize; i++)
    {
        r[i] = arr[mid + 1 + i];
    }

    int lIndex = 0;
    int rIndex = 0;

    int newIndex = left;
    while (lIndex < leftSize && rIndex < rightSize)
    {
        if (l[lIndex] < r[rIndex])
        {
            arr[newIndex] = l[lIndex];
            lIndex++;
        }
        else
        {
            arr[newIndex] = r[rIndex];
            rIndex++;
        }

        newIndex++;
    }

    while (lIndex < leftSize)
    {
        arr[newIndex] = l[lIndex];
        lIndex++;
        newIndex++;
    }
    while (rIndex < rightSize)
    {
        arr[newIndex] = r[rIndex];
        rIndex++;
        newIndex++;
    }
}
