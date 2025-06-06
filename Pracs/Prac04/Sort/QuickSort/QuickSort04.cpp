﻿#include "QuickSort04.h"

#include <iostream>
#include <memory>

void QuickSort04::sort(int* arr, int left, int right)
{
    if (left < right)
    {
        int pivot = partitionH1(arr, left, right);
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

int QuickSort04::partitionH1(int* arr, int left, int right)
{
    int l = left - 1;
    int r = right + 1;
    int pivotItem = arr[(left+right)/2];
    while (true)
    {
        do
        {
            l++;
        }while (arr[l] < pivotItem);

        do
        {
            r--;
        }while (arr[r] > pivotItem);

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

void QuickSort04::print(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
}
