#pragma once
#include <span>
class Merge12
{
public:
	void sort(std::span<int>& arr);
private:
	void mergeSort(std::span<int>& arr, int left, int right, std::span<int>& temp);
	void merge(std::span<int>& arr, int left, int mid, int right, std::span<int>& temp);
};

