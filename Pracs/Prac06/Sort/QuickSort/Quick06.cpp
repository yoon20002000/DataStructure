#include "Quick06.h"

#include <memory>

void Quick06::sort(int* arr, int left, int right)
{
    if (left < right)
    {
        int pivot = partitionH(arr, left, right);
        sort(arr, left, pivot-1);
        sort(arr, pivot+1, right);
    }
}

int Quick06::partitionH(int* arr, int left, int right)
{
    int pivot = left + (right - left) / 2;
    int pivotItem = arr[pivot];

    int l = left - 1;
    int r = right + 1;
    
    while (true)
    {
        do
        {
            l++;
        }while (arr[l] < pivotItem);
        do
        {
            r--;
        }
        while (arr[r] > pivotItem);
        
        if (l<r)
        {
            std::swap(arr[l], arr[r]);
        }
        else
        {
            return r;
        }
    }
}

int Quick06::partitionL(int* arr, int left, int right)
{
    int pivot = left;
    int pivotItem = arr[pivot];
    if (left<right)
    {
        for (int i = left + 1; i <=right; ++i)
        {
            if (arr[i]<pivotItem)
            {
                pivot++;
                std::swap(arr[pivot], arr[i]);
            }
        }
        std::swap(arr[pivot], arr[left]);
    }
    return pivot;
}
