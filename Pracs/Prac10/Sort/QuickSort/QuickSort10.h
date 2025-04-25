#pragma once

class QuickSort10
{
public:
    static void sortByL(int* arr, int left, int right);
    static void sortByH(int* arr, int left, int right);
private:
    
    static int partitionL(int* arr, int left, int right);
    static int partitionH(int* arr, int left, int right);
};
