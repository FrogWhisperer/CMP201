// CMP201 Assignment 4: Sorting
// William Kavanagh, Abertay University, 2025 : w.kavanagh@abertay.ac.uk 
// updated: Autumn 2026.
// Partial Framework

#pragma once

#include <iostream>
#include <vector>
#include <random>
#include <algorithm> // you may want to use std::swap

struct Duck
{
	std::string breed;
	float wingSpan;
	int identifier;
	int age_months;

	// A little helper function to print duck facts
	void quack() const {
		std::cout << "\tDUCK: I am a(n) " << breed << ", my id is: " << identifier
			<< ". I am " << age_months << " months old and have a wingspan of "
			<< wingSpan << "cm\n";
	}

	// the standard comparison operators compare ducks by wingspan.
	std::partial_ordering operator<=>(const Duck& otherDuck) const
	{
		// TODO: Assessed [0.5 if compareDucksByAge is also correct]
		return wingSpan <=> otherDuck.wingSpan;
	}

};

// Create a duck army
inline std::vector<Duck> createDucks(int howManyDucks)
{
	// provided
	static const std::vector<std::string> breeds = {
		"Mallard", "Pekin", "Rouen", "Cayuga", "Muscovy", "Indian Runner" // more ducks: https://en.wikipedia.org/wiki/List_of_duck_breeds
	};

	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_int_distribution<> breed_dist(0, breeds.size() - 1);
	std::uniform_real_distribution<float> wingspan_dist(55.0f, 90.0f);
	std::uniform_int_distribution<> age_dist(3, 60);

	std::vector<Duck> ducks;
	ducks.reserve(howManyDucks);		// Saves multiple pesky resize operations

	for (int i = 0; i < howManyDucks; ++i)
	{
		ducks.push_back({
			breeds[breed_dist(gen)],
			wingspan_dist(gen),
			i,
			age_dist(gen)
			});
	}

	return ducks;
}

// Returns true if leftDuck is younger than rightDuck, false otherwise
inline bool compareDucksByAge(const Duck& leftDuck, const Duck& rightDuck)
{
	// TODO Assessed [0.5 if operator<=> is also correct]
	return leftDuck.age_months < rightDuck.age_months;
}

// uses a callable comparator to sort a vector using cocktailshaker sort (bidirectional bubblesort).
template <typename T, typename Compare>
void CocktailShakerSort(std::vector<T>& vector, Compare comp)
{
	// TODO: Assessed [1.0]

	int i = 0;
	bool flipped = false;

	for (int j = 0; j < vector.size(); j++)
	{
		flipped = false;

		for (i = i; i < vector.size() - j - 1; i++)
		{
			if (comp(vector[i + 1], vector[i]))
			{
				std::swap(vector[i], vector[i + 1]);

				flipped = true;
			}
		}
		for (i = i; i > j + 1; i--)
		{
			if (comp(vector[i], vector[i - 1]))
			{
				std::swap(vector[i], vector[i - 1]);

				flipped = true;
			}
		}

		if (!flipped) { return; }
	}
}

// zips together templated vector by dividing into two subvectors and merging back in order
// NOTE: marks will be lost if your implementation is not stable
template <class T>
void Merge(std::vector<T>& vector, int start, int mid, int end)
{
	// TODO: Assessed [1.5] (0.5 of which is for stability, which requires mergeSort to be good also)

	std::vector<T> left(mid), right(mid);

	int leftIndex = 0;
	int rightIndex = 0;
	int mainIndex = start;

	// Get left vector
	for (int i = 0; i < mid; i++)
	{
		left[i] = vector[i];
	}
	// Get right vector
	for (int i = 0; i + mid + 1 < end; i++)
	{
		right[i] = vector[i + mid + 1];
	}

	// Combine vectors
	while (mainIndex < end)
	{
		if (left[leftIndex] <= right[rightIndex])
		{
			vector[mainIndex] = left[leftIndex];
			leftIndex++;
		}
		else
		{
			vector[mainIndex] = right[rightIndex];
			rightIndex++;
		}
		mainIndex++;
	}
}

// templated recursive sort using calls to MergeSort. Should be O(n log(n) )
template <class T>
void MergeSort(std::vector<T>& vector, int start, int end)
{
	// TODO: assessed [0.5]
	if (start < end)
	{
		int mid = (start + end) / 2;

		std::vector<T> left(mid), right(mid );

		// Get left vector
		for (int i = 0; i < mid; i++)
		{
			left[i] = vector[i];
		}

		MergeSort(left, start, end);

		// Get right vector
		for (int i = 0; i + mid + 1 < end; i++)
		{
			right[i] = vector[i + mid + 1];
		}

		MergeSort(right, start, end);

		for (int i = 0; i < end; i++)
		{
			if (i < mid) { vector[i] = left[i]; }
			else { vector[i] = right[i - mid]; }
		}

		Merge(vector, start, mid, end);
	}
}

// A simple wrapper for MergeSorts recursive calls.
template <class T> void MergeSort(std::vector<T>& collection)
{
	// Provided
	MergeSort(collection, 0, static_cast<int>(collection.size() - 1));	// cast from size_t to handle warnings
}

// Partition function for QuickSort.
// Runs in O(n) and chooses the final element as the pivot
template <class T>
int partition(std::vector<T>& collection, int begin, int end)
{
	// TODO: Assessed [1.0]
	// NOTE: other pivot selection will result in marks being deducted.
	return -1;
}

// Sorting using partition() and recusion. Runs in O(n log(n))
template <class T>
void QuickSort(std::vector<T>& collection, int begin, int end)
{
	// TODO: Assessed [0.5]
	
}

// A simple wrapper for QuickSorts recursive calls.
template <class T> void QuickSort(std::vector<T>& collection)
{
	// Provided
	QuickSort(collection, 0, static_cast<int>(collection.size() - 1));
}