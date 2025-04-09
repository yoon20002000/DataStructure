#include "DT_BubbleSort.h"

#include <future>
#include <iostream>
#include <iterator>

void DT_BubbleSort::solve()
{
    sort(datas, std::size(datas));
    print(datas, std::size(datas));
}

void DT_BubbleSort::sort(int* inDatas, int size)
{
    for (int i = 0 ; i < size - 1; ++i)
    {
        for (int j = 0; j < size - 1 - i; ++j)
        {
            if (inDatas[j+1] < inDatas[j])
            {
                std::swap(inDatas[j], inDatas[j+1]);
            }
        }
    }
}

void DT_BubbleSort::print(int* inDatas, int size)
{
    for (int i = 0 ; i < size; ++i)
    {
        std::cout << inDatas[i] << " ";    
    }
    
}
