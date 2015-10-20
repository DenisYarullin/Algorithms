#ifndef MERGE_SORT_H_
#define MERGE_SORT_H_

#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void MergeSort(vector<T> &items)
{
	if (items.size() <= 1)
	{
		return;
	}

	int leftSize = items.size() / 2;
	int rightSize = items.size() - leftSize;

	vector<T> left(leftSize);
	vector<T> right(rightSize);

	copy(items.begin(), items.begin() + leftSize, left.begin());
	copy(items.begin() + leftSize, items.end(), right.begin());

	MergeSort(left);
	MergeSort(right);

	Merge(items, left, right);
}

template <typename T>
void Merge(vector<T> &items, vector<T> &left, vector<T> &right)
{
	int leftIndex = 0;
	int rightIndex = 0;
	int targetIndex = 0;
	int remaining = left.size() + right.size();

	while (remaining > 0)
	{
		if (leftIndex >= left.size())
		{
			items[targetIndex] = right[rightIndex++];
		}
		else if (rightIndex >= right.size())
		{
			items[targetIndex] = left[leftIndex++];
		}
		else if (left[leftIndex] < right[rightIndex])
		{
			items[targetIndex] = left[leftIndex++];
		}
		else
		{
			items[targetIndex] = right[rightIndex++];
		}
		targetIndex++;
		remaining--;
	}
}

template<typename BidirectionalIterator>
BidirectionalIterator merge_sort(BidirectionalIterator start, BidirectionalIterator end)
{
	auto middle = std::next(start, std::distance(start, end) / 2);

	if (start != middle)
		std::inplace_merge(start, merge_sort(start, middle), merge_sort(middle, end));

	return end;
}

#endif // MERGE_SORT_H_ 

