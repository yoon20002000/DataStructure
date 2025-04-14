#pragma once

class DT_Quick
{
public:
    void solve();
    void sort(int* inDatas, int left, int right);
    int partition(int* inDatas, int left, int right);
    int partition2(int* inDatas, int left, int right);
    void print(int* inDatas, int size);
private:
    int datas[8] = {69,10,30,2,16,8,31,22};
};
