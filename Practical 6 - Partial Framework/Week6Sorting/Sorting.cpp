// CMP201 Assignment 4: Sorting
// William Kavanagh, Abertay University, 2025 : w.kavanagh@abertay.ac.uk
// Simple main() included for basic testing.

#include "Sorting.h"

// Main method included for testing. 
int main()	
{
	// Configurable experimental values and setup
	int howManyDucks = 5000;	// 5000 suggested, try with more if you like.
	int sampleStart = howManyDucks * 0.8;
	int sampleLength = 10;		// 10 suggested, try with more if you like. You may need to infact...

	std::cout << "CMP201 Assignment 4: Getting our ducks in a row\n================================\n";
	std::cout << "Testing with " << howManyDucks << " ducks\n\n";
	std::cout << "Note: Neither of the comparators are tested here\n\n";

	// MERGESORT 
	std::cout << "Test MergeSort, which should sort ducks in ascending order of wingspan:\n";
	std::vector<Duck> rowOfDucks = createDucks(howManyDucks);
	MergeSort(rowOfDucks);
	std::cout << "Sampling " << sampleLength << " ducks from position " << sampleStart << ":\n";
	for (int i = sampleStart; i < sampleStart + sampleLength; i++) rowOfDucks[i].quack();	


	// COCKTAILSHAKER SORT
	std::cout << "\nTest cocktailshaker sort, which should sort ducks in ascending order of age (likely considerably slower):\n";
	rowOfDucks = createDucks(howManyDucks);
	CocktailShakerSort(rowOfDucks, compareDucksByAge);
	std::cout << "Sampling " << sampleLength << " ducks from position " << sampleStart << ":\n";
	for (int i = sampleStart; i < sampleStart + sampleLength; i++) rowOfDucks[i].quack();


	// QUICKSORT
	std::cout << "\nTest QuickSort, which should sort ducks in ascending order of wingspan:\n";
	rowOfDucks = createDucks(howManyDucks);
	QuickSort(rowOfDucks);
	std::cout << "Sampling " << sampleLength << " ducks from position " << sampleStart << ":\n";
	for (int i = sampleStart; i < sampleStart + sampleLength; i++) rowOfDucks[i].quack();

	return 0;
}
