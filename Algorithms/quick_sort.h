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

template<typename ForwardIterator>
ForwardIterator quick_sort(ForwardIterator start, ForwardIterator end)
{
	// typedef не будем считать за часть реализации, с ним просто удобнее    
	typedef typename std::iterator_traits<ForwardIterator>::value_type type;

	// Безумная Быстрая сортировка на C++ в одну строку 
	// Не повторять в реальной жизни

	return (start == end) ? end : quick_sort(

		std::partition(

			quick_sort(start,

				std::partition(start, end, std::bind2nd(std::less<type>(), *start))),

			end, std::bind2nd(std::less_equal<type>(), *start)
		),
		end);
}

#endif // QUICK_SORT_H_