#include "DT_InsertionSort.h"

#include <cstdio>
#include <future>
#include <iterator>

void DT_InsertionSort::solve()
{
    insertionSort(datas, std::size(datas));
    print(datas, std::size(datas));
}

void DT_InsertionSort::insertionSort(int* inDatas, int length)
{
    for (int i = 1; i < length; i++)
    {
        int temp = inDatas[i];
        int j = i;
        while (j > 0 && inDatas[j - 1] > temp)
        {
            inDatas[j] = inDatas[j - 1];
            j--;
        }
        inDatas[j] = temp;
    }
}

void DT_InsertionSort::print(int* inDatas, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", inDatas[i]);
    }
}
