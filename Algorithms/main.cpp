#include <iostream>
#include <ctime>
#include <algorithm>
#include <iterator>

#include "bubble_sort.h"
#include "insertion_sort.h"
#include "selection_sort.h"
#include "merge_sort.h"

using namespace std;

int main()
{
	srand(time(NULL));
	vector<int> array;
	array.resize(10);

	std::generate(array.begin(), array.end(), rand);
	//BubbleSort(array);
	//InsertionSort(array);
	//SelectionSort(array);
	MergeSort(array);

	copy(array.begin(), array.end(), ostream_iterator<int>(cout, " "));

	cin.get();
	return 0;
}