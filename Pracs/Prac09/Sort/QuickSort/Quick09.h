#pragma once

class Quick09
{
public:
    static void sort(int* arr, int size);
private:
    static void quickSort(int* arr, int left, int right);
    static int partitionL(int* arr, int left, int right);
    static int partitionH(int* arr, int left, int right);
    static void lomuto(int* arr, int left, int right);
    static void hoare(int* arr, int left, int right);
};
