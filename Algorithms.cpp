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
void Sorting::InsertionSort(pokemon userData[], int N)
{
	for (int fIndex = 1; fIndex < N; fIndex++)
	{
		pokemon key = userData[fIndex];
		
		// Inserting array into sorted sequence
		int wIndex = fIndex - 1;
		while (wIndex >= 0 && userData[wIndex].power > key.power)
		{
			// The actual insertion...
			userData[wIndex + 1] = userData[wIndex];

			wIndex--;
			insertCount++; // Counting operations of INSERTION SORT
		}

		userData[wIndex + 1] = key;
	}
}


// MERGE SORT...
void Sorting::MergeSort(pokemon userData[], int const start, int const end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;

		MergeSort(userData, start, mid);
		MergeSort(userData, mid + 1, end);
		Merge(userData, start, mid, end);
	}
}


// QUICKSORT...
void Sorting::QuickSort(pokemon userData[], const int start, const int end)
{
	if (start < end)
	{
		int pIndex = Partition(userData, start, end);
 
		QuickSort(userData, start, pIndex - 1);
		QuickSort(userData, pIndex + 1, end);
	}
}


void Sorting::CreateFile(pokemon userData[], int &size, std::string fileName)
{
	// Open a CSV file for writing.
  	std::ofstream outputFile(fileName);

	// Write the array to the file.
	outputFile << "Pokemon Number, Total Stats" << std::endl;
	
	for (int index = 0; index < size; index++)
	{
		outputFile << userData[index].dexNum << "," << std::to_string(userData[index].power) << std::endl;
	}

	outputFile.close();
}


//////****HELPER METHODS****//////

void Sorting::Merge(pokemon userData[], const int start, const int mid, const int end)
{
	const int leftSize = mid - start + 1;
	const int rightSize = end - mid;
 
	// Temporary Arrays...	
	pokemon leftArray[leftSize];
	pokemon rightArray[rightSize];
 
	// Copying data into temporary arrays...
	for (int leftIndex = 0; leftIndex < leftSize; leftIndex++) { leftArray[leftIndex] = userData[start + leftIndex]; }
	for (int rightIndex = 0; rightIndex < rightSize; rightIndex++) { rightArray[rightIndex] = userData[mid + 1 + rightIndex]; }

	int leftSubIndex = 0, rightSubIndex = 0;
	int mergedIndex = start;
 
	// Merging temporary arrays back in a single array...
	while (leftSubIndex < leftSize && rightSubIndex < rightSize)
	{
		if (leftArray[leftSubIndex].power <= rightArray[rightSubIndex].power)
		{
			userData[mergedIndex] = leftArray[leftSubIndex];
			leftSubIndex++;
		}
		else
		{
			userData[mergedIndex] = rightArray[rightSubIndex];
			rightSubIndex++;
		}

		mergedIndex++;
		mergeCount++; // Counting operations of MERGE SORT
	}
 
	// Copying any remaining elements of leftArray...
	while (leftSubIndex < leftSize)
	{
		userData[mergedIndex] = leftArray[leftSubIndex];
		leftSubIndex++;
		mergedIndex++;
		mergeCount++; // Counting operations of MERGE SORT
	}
 
	// Copying any remaining elements of rightArray...
	while (rightSubIndex < rightSize)
	{
		userData[mergedIndex] = rightArray[rightSubIndex];
		rightSubIndex++;
		mergedIndex++;
		mergeCount++; // Counting operations of MERGE SORT
	}
}


void Sorting::Exchange(pokemon *first, pokemon *second)
{
	pokemon t = *first;
	*first = *second;
	*second = t;
	quickCount++; // Counting operations of Quicksort
}


int Sorting::Partition(pokemon userData[], int start, int end)
{
	pokemon pivot = userData[end];
	int outerIndex = (start - 1);
 
	for (int innerIndex = start; innerIndex < end; innerIndex++) {
 
		// If current element is smaller than the pivot
		if (userData[innerIndex].power < pivot.power)
		{
			// Increment index of smaller element
			outerIndex++;
			Exchange(&userData[outerIndex], &userData[innerIndex]);
		}
	}

	Exchange(&userData[outerIndex + 1], &userData[end]);
	
	return (outerIndex + 1);
}

#endif