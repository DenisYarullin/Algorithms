#ifndef UTILITY_H_ 
#define UTILITY_H_

#include <vector>
#include <vld.h>

using std::vector;

template <typename T>
void Swap(vector<T> &items, int left, int right)
{
	if (left != right)
	{
		T temp = items[left];
		items[left] = items[right];
		items[right] = temp;
	}
}


#endif // UTILITY_H_


