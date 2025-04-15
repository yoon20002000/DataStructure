#include "MergeSortPrac.h"

#include <vector>


void MergeSortPrac::mergeSort(int* inDatas, int left, int right)
{
    if (left >= right)
    {
        return;
    }
        
    int mid = left + (right - left) / 2;
    mergeSort(inDatas, left, mid);
    mergeSort(inDatas, mid + 1, right);
    merge(inDatas, left, mid, right);
}

void MergeSortPrac::merge(int* inDatas, int left, int mid, int right)
{
    std::vector<int> l(mid - left + 1);
    std::vector<int> r (right - mid);

    for (int i = left ; i <= mid ; ++i)
    {
        l.push_back(inDatas[i]);
    }
    for (int j = mid + 1; j <= right; ++j)
    {
        r.push_back(inDatas[j]);
    }

    int lIndex = 0;
    int rIndex = 0;

    int inputIndex = left;
    while (lIndex < l.size() && rIndex < r.size())
    {
        if (l[lIndex] < r[rIndex])
        {
            inDatas[inputIndex] = l[lIndex];
            inputIndex++;
            lIndex++;
        }
        else
        {
            inDatas[inputIndex] = r[rIndex];
            inputIndex++;
            rIndex++;
        }
    }

    while (lIndex < l.size())
    {
        inDatas[inputIndex] = l[lIndex];
        inputIndex++;
        lIndex++;
    }
    while (rIndex < r.size())
    {
        inDatas[inputIndex] = r[rIndex];
        inputIndex++;
        rIndex++;
    }
}
