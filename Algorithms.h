#ifndef ALGORITHMS_H
#define	ALGORITHMS_H

#include <array>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <ios>
#include <sstream>

using std::vector;

struct pokemon
{
	std::string dexNum;
	int power;
};

std::istream& operator>>(std::istream& input, pokemon& poke)
{
	char comma;
	input >> poke.dexNum;
	input >> comma;
	input >> poke.power;

	return input;
}

class Sorting
{
public:
	Sorting();

	// Getters...
	int getInsertCount();
	int getMergeCount();
	int getQuickCount();

	void InsertionSort(pokemon userData[], int size);
	void MergeSort(pokemon userData[], const int start, const int end);
	void QuickSort(pokemon userData[], const int start, const int end);
	void CreateFile(pokemon userData[], int &size, std::string fileName);

private:
	void Merge(pokemon userData[], const int start, const int mid, const int end);
	void Exchange(pokemon *first, pokemon *second);
	int Partition(pokemon userData[], int start, int end);

	int insertCount;
	int mergeCount;
	int quickCount;
};

#endif
#include "Algorithms.cpp"