#ifndef SELECTION_SORT_H_
#define SELECTION_SORT_H_

#include <vector>
#include "utility.h"

using namespace std;

template <typename T>
void SelectionSort(vector<T> &items)
{
	int sortedRangeEnd = 0;

	while (sortedRangeEnd < items.size())
	{
		int nextIndex = FindIndexOfSmallestFromIndex(items, sortedRangeEnd);
		Swap(items, sortedRangeEnd, nextIndex);

		sortedRangeEnd++;
	}
}


template <typename T>
int FindIndexOfSmallestFromIndex(vector<T> &items, int sortedRangeEnd)
{
	T currentSmallest = items[sortedRangeEnd];
	int currentSmallestIndex = sortedRangeEnd;

	for (int i = sortedRangeEnd + 1; i < items.size(); i++)
	{
		if (currentSmallest > items[i])
		{
			currentSmallest = items[i];
			currentSmallestIndex = i;
		}
	}
	return currentSmallestIndex;
}

template <typename ForwardIterator>
void selection_sort(ForwardIterator start, ForwardIterator end)
{
	for (auto i = start; i != end; ++i)
		std::iter_swap(i, std::min_element(i, end));
}

#endif // SELECTION_SORT_H_