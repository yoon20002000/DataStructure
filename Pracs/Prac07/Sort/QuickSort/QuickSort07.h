#pragma once

class QuickSort07
{
public:
    static void quickSort(int* arr, int left, int right);
private:
    static int partitionL(int* arr, int left, int right);
    static int partitionH(int* arr, int left, int right);
};
