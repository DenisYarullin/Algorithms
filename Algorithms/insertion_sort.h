#ifndef INSERTION_SORT_H_ 
#define INSERTION_SORT_H_

#include <vector>
#include <exception>
#include "utility.h"

using namespace std;

template <typename T>
void InsertionSort(vector<T> &items)
{
	int sortedRangeEndIndex = 1;

	while (sortedRangeEndIndex < items.size())
	{
		if (items[sortedRangeEndIndex] < items[sortedRangeEndIndex - 1])
		{
			int insertIndex = FindInsertionIndex(items, items[sortedRangeEndIndex]);
			Insert(items, insertIndex, sortedRangeEndIndex);
		}
		sortedRangeEndIndex++;
	}
}


template <typename T>
int FindInsertionIndex(vector<T> &items, T valueToInsert)
{
	for (int index = 0; index < items.size(); index++)
	{
		if (items[index] > valueToInsert)
		{
			return index;
		}
	}
	throw exception("The insertion index was not found");
}

// itemArray =       0 1 2 4 5 6 3 7
// insertingAt =     3
// insertingFrom =   6
// 
// Действия:
//  1: Сохраняем индекс в temp     temp = 4
//  2: Поменять индекс на  -&gt; 0 1 2 3 5 6 3 7   temp = 4
//  3: Перейти от индекса от к индексу к + 1.
//     Сдвинуть элементы влево на один.
//     0 1 2 3 5 6 6 7   temp = 4
//     0 1 2 3 5 5 6 7   temp = 4
//  4: Записать temp на позицию от + 1.
//     0 1 2 3 4 5 6 7   temp = 4
template <typename T>
void Insert(vector<T> &items, int indexInsertingAt, int indexInsertingFrom)
{
	T temp = items[indexInsertingAt];
	items[indexInsertingAt] = items[indexInsertingFrom];
	for (int current = indexInsertingFrom; current > indexInsertingAt; current--)
	{
		items[current] = items[current - 1];
	}
	items[indexInsertingAt + 1] = temp;
}

template <typename ForwardIterator>
void insertion_sort(ForwardIterator start, ForwardIterator end)
{
	for (auto i = start; i != end; ++i)
		std::rotate(std::upper_bound(start, i, *i), i, std::next(i));
}

template<typename RandomAccessIterator>
void shell_sort(RandomAccessIterator start, RandomAccessIterator end)
{
	for (auto x = (end - start) / 2; x != 0; x /= 2)
		for (auto i = start + x; i != end; ++i)
			std::rotate(std::upper_bound(start, i, *i), i, std::next(i));
}

#endif // INSERTION_SORT_H_