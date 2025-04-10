#pragma once

class DT_MergeSort
{
public:
    void solve();

private:
    void merge(int* inDatas, int left, int mid, int right);
    void mergeSort(int* inDatas, int left, int right);
    void print(int* inDatas, int length);
    int datas[8] = {69,10,30,2,16,8,31,22};
};
