#include <iostream>
#include <ctime>
#include <algorithm>
#include <iterator>

#include "bubble_sort.h"
#include "insertion_sort.h"
#include "selection_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"

using namespace std;

int main()
{
	srand(time(NULL));
	vector<int> array;
	array.resize(10);

	std::generate(array.begin(), array.end(), rand);
	copy(array.begin(), array.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	//BubbleSort(array);
	//InsertionSort(array);
	//SelectionSort(array);
	//MergeSort(array);
	//QuickSort(array);
	//bubble_sort(array.begin(), array.end());
	//selection_sort(array.begin(), array.end());
	insertion_sort(array.begin(), array.end());

	copy(array.begin(), array.end(), ostream_iterator<int>(cout, " "));

	cin.get();
	return 0;
}