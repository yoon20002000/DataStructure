#pragma once
#include <span>
class Quick12
{
public:
	void sort(std::span<int>& arr);
private:
	void quickSortL(std::span<int>& arr, int left, int right);
	int partitionL(std::span<int>& arr, int left, int right);

	void quickSortH(std::span<int>& arr, int left, int right);
	int partitionH(std::span<int>& arr, int left, int right);

};

