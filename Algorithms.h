#ifndef ALGORITHMS_H
#define	ALGORITHMS_H

#include <array>
#include <vector>
#include <string>
#include <iostream>

using std::vector;

class Sorting
{
public:
	Sorting();

	// Getters
	int getInsertCount();
	int getMergeCount();
	int getQuickCount();

	void InsertionSort(int userData[], int N);
	void MergeSort(int array[], const int begin, const int end);
	void QuickSort(int arr[], const int start, const int end);
	void DisplayData(int A[], int size);

private:
	void Merge(int userData[], const int left, const int mid, const int right);

	int Partition(int arr[], int low, int high);
	void Swap(int *first, int *second);

	int insertCount;
	int mergeCount;
	int quickCount;
};

#endif
#include "Algorithms.cpp"