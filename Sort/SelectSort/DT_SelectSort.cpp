#include "DT_SelectSort.h"

#include <algorithm>
#include <future>
#include <iostream>

void DT_SelectSort::sort()
{
    int size = std::size(datas);
    
    for (int i = 0 ; i < size - 1; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j)
        {
            if (datas[j] < datas[minIndex])
            {
                minIndex = j;    
            }
        }

        std::swap(datas[i], datas[minIndex]);
    }

    for (int i = 0 ; i < size ; ++i)
    {
        std::cout << datas[i] << " ";
    }
}
