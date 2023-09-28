#ifndef ALGORITHMS_CPP
#define ALGORITHMS_CPP

#include "Algorithms.h"

Sorting::Sorting()
{
	insertCount = 0;
	quickCount = 0;
	mergeCount = 0;
}

// Getters
int Sorting::getInsertCount() { return insertCount; }
int Sorting::getMergeCount() { return mergeCount; }
int Sorting::getQuickCount() { return quickCount; }


// INSERTION SORT...
void Sorting::InsertionSort(int userData[], int N)
{
	for (int fIndex = 1; fIndex < N; fIndex++)
	{
		int key = userData[fIndex];
		
		// Inserting array into sorted sequence
		int wIndex = fIndex - 1;
		while (wIndex >= 0 && userData[wIndex] > key)
		{
			// The actual insertion...
			userData[wIndex + 1] = userData[wIndex];

			wIndex--;
			insertCount++; // counting runs of INSERTION SORT
		}

		userData[wIndex + 1] = key;
	}
}


// MERGE SORT...
void Sorting::MergeSort(int array[], const int start, const int end)
{
	if (start < end)
	{
		int mid = (start + (end - start) / 2);

		MergeSort(array, start, mid);
		MergeSort(array, mid + 1, end);
		Merge(array, start, mid, end);
	}
}


// QUICKSORT...
void Sorting::QuickSort(int userData[], const int start, const int end)
{
	if (start < end)
	{
		int pIndex = Partition(userData, start, end);
 
		QuickSort(userData, start, pIndex - 1);
		QuickSort(userData, pIndex + 1, end);
	}
}



//////****HELPER METHODS****//////

void Sorting::Merge(int userData[], const int left, const int mid, const int right)
{
	int const sizeLeft = mid - left + 1;
	int const sizeRight = right - mid;
 
	// Create temp arrays
	int *leftArray = new int[sizeLeft];
	int *rightArray = new int[sizeRight];
 
	// Copy data to temp arrays leftArray[] and rightArray[]
	for (int fLeftIndex = 0; fLeftIndex < sizeLeft; fLeftIndex++) { leftArray[fLeftIndex] = userData[left + fLeftIndex]; }
	for (int fRightIndex = 0; fRightIndex < sizeLeft; fRightIndex++) { rightArray[fRightIndex] = userData[mid + 1 + fRightIndex]; }

	int leftIndex = 0;
	int rightIndex = 0;
 
	// merge separate arrays back into single array, comparing values
	for (int mergedIndex = left; mergedIndex < right; mergedIndex++)
	{
		if (leftArray[leftIndex] <= rightArray[rightIndex])
		{
			userData[mergedIndex] = leftArray[leftIndex];
			leftIndex++;
		}
		else
		{
			userData[mergedIndex] = rightArray[rightIndex];
			rightIndex++;
		}
		
		mergedIndex++;
		mergeCount++; // counting runs of MERGE SORT
	}

	delete[] leftArray;
	delete[] rightArray;
}


// Partition the array using the last element as the pivot
int Sorting::Partition(int userData[], int start, int end)
{
	int pivot = userData[end];
 
	int index = (start - 1);
 
	for (int j = start; j <= end - 1; j++) {
 
		// If current element is smaller than the pivot
		if (userData[j] < pivot) {
 
			// Increment index of smaller element
			index++;
			Swap(&userData[index], &userData[j]);
		}
	}

	Swap(&userData[index + 1], &userData[end]);
	return (index + 1);
}


void Sorting::Swap(int *first, int *second)
{
	int t = *first;
	*first = *second;
	*second = t;
	quickCount++; // counting runs of Quicksort
}


// Function to print an array
void Sorting::DisplayData(int userData[], int size)
{
	for (int index = 0; index < size; index++)
	{
		std::cout << userData[index] << " || ";
	}

	std::cout << std::endl << std::endl;
}

#endif