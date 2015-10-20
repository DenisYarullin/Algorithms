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

template <typename InputIterator>
void print(InputIterator start, InputIterator end, const char *delim = " ")
{
	typedef typename std::iterator_traits<InputIterator>::value_type type;

	std::copy(start, end, std::ostream_iterator<type>(std::cout, delim));
}


#endif // UTILITY_H_


