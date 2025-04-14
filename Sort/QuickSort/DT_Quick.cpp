#include "DT_Quick.h"

#include <future>
#include <iostream>
#include <iterator>

void DT_Quick::solve()
{
    sort(datas, 0, std::size(datas) - 1);
    print(datas, std::size(datas));
}

void DT_Quick::sort(int* inDatas, int left, int right)
{
    if (left < right)
    {
        //int pivot = partition(inDatas, left, right);
        int pivot = partition2(inDatas, left, right);
        sort(inDatas, left, pivot - 1);
        sort(inDatas, pivot + 1, right);
    }
}

int DT_Quick::partition(int* inDatas, int left, int right)
{
    int pivot = (left + right) / 2;
    int pivotItem = inDatas[pivot];
    while (left < right)
    {
        while (inDatas[left] < pivotItem && left < right)
        {
            left++;
        }
        while (inDatas[right] >= pivotItem && left < right)
        {
            right--;
        }

        if (left < right)
        {
            std::swap(inDatas[left], inDatas[right]);
        }
    }

    std::swap(inDatas[pivot], inDatas[right]);

    return right;
}

int DT_Quick::partition2(int* inDatas, int left, int right)
{
    int pivot = left;
    int pivotItem = inDatas[pivot];

    for (int i = left + 1; i <= right; ++i)
    {
        if (inDatas[i] < pivotItem)
        {
            pivot++;
            std::swap(inDatas[i], inDatas[pivot]);
        }
    }

    std::swap(inDatas[pivot], inDatas[left]);
    return pivot;
}

void DT_Quick::print(int* inDatas, int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << inDatas[i] << " ";
    }
}
