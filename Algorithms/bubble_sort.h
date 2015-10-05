#ifndef BUBBLE_SORT_H_ 
#define BUBBLE_SORT_H_

#include "utility.h"

template <typename T>
void BubbleSort(vector<T> &items)
{
	bool swapped;

	do 
	{
		swapped = false;
		for (int i = 1; i < items.size(); ++i)
		{
			if (items[i - 1] > items[i])
			{
				Swap(items, i - 1, i);
				swapped = true;
			}
		}
	} while (swapped != false);
}


#endif // BUBBLE_SORT_H_