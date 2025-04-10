#include "DT_MergeSort.h"

#include <algorithm>
#include <iostream>
#include <vector>

void DT_MergeSort::solve()
{
    mergeSort(datas, 0, std::size(datas) - 1);
    print(datas, std::size(datas));
}

void DT_MergeSort::merge(int* inDatas, int left, int mid, int right)
{
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    std::vector<int> leftData(leftSize), rightData(rightSize);
    for (int i = 0; i < leftSize; i++)
    {
        leftData[i] = inDatas[left + i];
    }

    for (int j = 0; j < rightSize; j++)
    {
        rightData[j] = inDatas[mid + 1 + j];
    }
    int i = 0, j = 0, k = left;
    while (i < leftSize && j < rightSize)
    {
        if (leftData[i] <= rightData[j])
        {
            inDatas[k++] = leftData[i++];
        }
        else
        {
            inDatas[k++] = rightData[j++];
        }
    }

    while (i < leftSize)
    {
        inDatas[k++] = leftData[i++];
    }
    while (j < rightSize)
    {
        inDatas[k++] = rightData[j++];
    }
}

void DT_MergeSort::mergeSort(int* inDatas, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(inDatas, left, mid);
        mergeSort(inDatas, mid + 1, right);
        merge(inDatas, left, mid, right);
    }
}

void DT_MergeSort::print(int* inDatas, int length)
{
    for (int data : datas)
    {
        std::cout << data << " ";
    }
    std::cout << '\n';
}
