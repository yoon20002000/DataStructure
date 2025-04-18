#include "QuickSort04.h"

#include <iostream>
#include <memory>

void QuickSort04::sort(int* arr, int left, int right)
{
    if (left < right)
    {
        int pivot = partitionH(arr, left, right);
        sort(arr, left, pivot - 1);
        sort(arr, pivot + 1, right);
    }
}

int QuickSort04::partitionL(int* arr, int left, int right)
{
    int pivot = left;
    int pivotItem = arr[pivot];

    for (int i = left; i <= right; ++i)
    {
        if (arr[i] < pivotItem)
        {
            pivot++;
            std::swap(arr[i], arr[pivot]);
        }
    }

    if (left != pivot)
    {
        std::swap(arr[pivot], arr[left]);
    }

    return pivot;
}

int QuickSort04::partitionH(int* arr, int left, int right)
 {
     int pivot = (left + right) / 2;
     int pivotItem = arr[pivot];
 
     while (true)
     {
         while (arr[left] < pivotItem)
         {
             left++;
         }
         while (arr[right] > pivotItem)
         {
             right--;
         }
 
         if (left < right)
         {
             std::swap(arr[left], arr[right]);
         }
         else
         {
             return pivot;
         }
     }
 }

void QuickSort04::print(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
}
