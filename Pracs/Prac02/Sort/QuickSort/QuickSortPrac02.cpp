#include "QuickSortPrac02.h"

#include <fstream>
#include <iostream>
#include<memory>

void QuickSortPrac02::sort(int* arr, int left, int right)
{
    if (left < right)
    {
        int pivot = partition(arr, left, right);
        sort(arr, left, pivot - 1);
        sort(arr, pivot + 1, right);
    }
}

int QuickSortPrac02::partition(int* arr, int left, int right)
{
    int mid = (left + right) / 2;
    int midItem = arr[mid];
    while (left < right)
    {
        while (left < right && arr[left] < midItem)
        {
            left++;
        }
        while (left < right && arr[right] >= midItem)
        {
            right--;
        }

        if (left < right)
        {
            std::swap(arr[left], arr[right]);
        }
    }

    std::swap(arr[mid], arr[right]);

    return right;
}

int QuickSortPrac02::partition01(int* arr, int left, int right)
{
    int pivot  = left;
    if (left < right)
    {
        
        int pivotItem = arr[pivot];
        for (int i = left + 1; i<=right;++i)
        {
            if (arr[i] < pivotItem)
            {
                pivot++;
                std::swap(arr[i], arr[pivot]);
            }
        }

        std::swap(arr[pivot], arr[left]);
    }
    return pivot;
}

void QuickSortPrac02::print(int* arr, int size)
{
    for (int i = 0 ; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
}
