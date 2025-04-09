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
        int pivot = partition(inDatas, left, right);
        sort(inDatas, left, pivot - 1);
        sort(inDatas, pivot + 1, right);
    }
}

int DT_Quick::partition(int* inDatas, int left, int right)
{
    int pivotIndex = (right + left) / 2;
    int pivotItem = inDatas[pivotIndex];

    while (left < right)
    {
        while (left < right && inDatas[left] <= pivotItem)
        {
            left++;
        }
        while (left < right && inDatas[right] >= pivotItem)
        {
            right--;
        }
        if (left <= right)
        {
            std::swap(inDatas[left], inDatas[right]);
        }
    }
    std::swap(inDatas[pivotIndex], inDatas[right]);

    return right;
}

void DT_Quick::print(int* inDatas, int size)
{
    for (int i = 0 ; i < size; ++i)
    {
        std::cout << inDatas[i] << " ";    
    }
}
