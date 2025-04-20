#include "QuickSort05.h"

#include <memory>

void QuickSort05::quickSort(int* arr, int left, int right)
{
    if (left < right)
    {
        // int pivot = partitionL(arr, left, right);
        // quickSort(arr, left, pivot-1);
        // quickSort(arr, pivot+1, right);

        int pivot = partitionH(arr, left, right);
        quickSort(arr, left, pivot-1);
        quickSort(arr, pivot+1, right);
    }
}

int QuickSort05::partitionL(int* arr, int left, int right)
{
    int pivot = left;
    int pivotItem = arr[pivot];

    for (int i = left + 1; i<=right;++i)
    {
        if (arr[i]< pivotItem)
        {
            pivot++;
            std::swap(arr[i], arr[pivot]);
        }
    }

    std::swap(arr[left], arr[pivot]);
    return pivot;
}

int QuickSort05::partitionH(int* arr, int left, int right)
{
    int pivot = (left+right)/2;
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
        while (arr[r]> pivotItem);
        
        if (l<r)
        {
            std::swap(arr[l],arr[r]);    
        }
        else
        {
            return r;
        }
    }
}
