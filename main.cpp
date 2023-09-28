#include "Algorithms.h"

int main()
{
	Sorting sort;
	int dataSize = 0;

	// Read in data, from file...




	// CALLING INSERTION SORT METHOD
	std::cout << "INSERTION SORT..." << std::endl << std::endl;

	int insertData[] = { 24, 32, 10, 7, 42, 8, 12, 9, 64 };
	dataSize = sizeof(insertData) / sizeof(insertData[0]);

	std::cout << "Original Data: " << std::endl;
	sort.DisplayData(insertData, dataSize);

	//Sorting the data...
	sort.InsertionSort(insertData, dataSize);

	std::cout << "Sorted Data: " << std::endl;
	sort.DisplayData(insertData, dataSize);
	std::cout << "Finished with " << sort.getInsertCount() << " runs." << std::endl << std::endl << std::endl;
	


	// CALLING QUICKSORT METHOD
	std::cout << "QUICKSORT..." << std::endl << std::endl;

	int quickData[] = { 24, 32, 10, 7, 42, 8, 12, 9, 64 };
	dataSize = sizeof(quickData) / sizeof(quickData[0]);

	std::cout << "Original Data: " << std::endl;
	sort.DisplayData(quickData, dataSize);

	//Sorting the data...
	sort.QuickSort(quickData, 1, dataSize);
	
	std::cout << "Sorted Data: " << std::endl;
	sort.DisplayData(quickData, dataSize);
	std::cout << "Finished with " << sort.getQuickCount() << " runs." << std::endl << std::endl << std::endl;



	// CALLING MERGE SORT METHOD
	int mergeData[] = { 24, 32, 10, 7, 42, 8, 12, 9, 64 };
	dataSize = sizeof(mergeData) / sizeof(mergeData[0]);

	std::cout << "Original Data: " << std::endl;
	sort.DisplayData(mergeData, dataSize);

	//Sorting the data...
	sort.MergeSort(mergeData, 0, dataSize - 1);

	std::cout << "Sorted Data: " << std::endl;
	sort.DisplayData(mergeData, dataSize);
	std::cout << "Finished with " << sort.getMergeCount() << " runs." << std::endl << std::endl << std::endl << std::endl;
	return 0;
}