#ifndef QUICK_SORT_H_
#define QUICK_SORT_H_

#include <vector>
#include "utility.h"

using namespace std;

template <typename T>
void QuickSort(vector<T> &items)
{
	Sort(items, 0, items.size() - 1);
}

template <typename T>
void Sort(vector<T> &items, int left, int right)
{
	if (left < right)
	{
		srand(time(NULL));

		int pivotIndex = right;//rand() % (right - left + 1);
		int newPivot = Partition(items, left, right, pivotIndex);

		Sort(items, left, newPivot - 1);
		Sort(items, newPivot + 1, right);
	}
}

template <typename T>
int Partition(vector<T> &items, int left, int right, int pivotIndex)
{
	T pivotValue = items[pivotIndex];

	Swap(items, pivotIndex, right);

	int storeIndex = left;

	for (int i = left; i < right; i++)
	{
		if (items[i] < pivotValue)
		{
			Swap(items, i, storeIndex);
			storeIndex++;
		}
	}
	Swap(items, storeIndex, right);
	return storeIndex;
}


#endif // QUICK_SORT_H_