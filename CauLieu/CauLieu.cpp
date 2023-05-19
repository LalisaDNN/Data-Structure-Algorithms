#include <algorithm>
#include <iostream>
#include <ctime>
#include <limits>
#include <chrono>
#include <vector>

#include "DoublyLL.h"

void generateRandomNumbers(vector<int>& nums, int size, int range);
void implementation(vector<int> nums);


void generateRandomNumbers(vector<int> &nums, int size, int range)
{
	srand(time(0));
	for (int i = 0; i < size; i++)
	{
		int n = rand() % range + 1; // generates random elements for the list
		nums.push_back(n);
	}
}

void implementation(vector<int> nums)
{
	DoublyLinkedList<int> dll1; // bubble
	DoublyLinkedList<int> dll2; // insertion
	DoublyLinkedList<int> dll3; // selection
	DoublyLinkedList<int> dll4; // merge
	DoublyLinkedList<int> dll5; // quick


	// -------------------------------------------- Bubble sort:
	dll1.insertVector(nums); // insert elements for bubble sort

	auto startBubble = chrono::high_resolution_clock::now(); // measure the time taken for bubble sort
	dll1.BubbleSort(); // perform bubble sort
	auto endBubble = chrono::high_resolution_clock::now();
	auto durationBubble = chrono::duration_cast<chrono::microseconds>(endBubble - startBubble);

	cout << "\n\nTime taken to sort the list using Bubble sort: " << durationBubble.count() << " (ms)\n";
	/*cout << "\nThe sorted list: ";
	dll1.Display();*/



	// -------------------------------------------- Insertion sort:
	dll2.insertVector(nums);

	auto startInsertion = chrono::high_resolution_clock::now(); // measure the time taken for insertion sort
	dll2.InsertionSort(); // perform insertion sort
	auto endInsertion = chrono::high_resolution_clock::now();
	auto durationInsertion = chrono::duration_cast<chrono::microseconds>(endInsertion - startInsertion);

	cout << "\n\nTime taken to sort the list using Insertion sort: " << durationInsertion.count() << " (ms)\n";
	/*cout << "\nThe sorted list: ";
	dll2.Display();*/



	// -------------------------------------------- Selection sort:
	dll3.insertVector(nums);

	auto startSelection = chrono::high_resolution_clock::now(); // measure the time taken for selection sort
	dll3.SelectionSort(); // perform insertion sort
	auto endSelection = chrono::high_resolution_clock::now();
	auto durationSelection = chrono::duration_cast<chrono::microseconds>(endSelection - startSelection);

	cout << "\n\nTime taken to sort the list using Selection sort: " << durationSelection.count() << " (ms)\n";
	/*cout << "\nThe sorted list: ";
	dll3.Display();*/



	// -------------------------------------------- Merge sort:
	dll4.insertVector(nums);

	auto startMerge = chrono::high_resolution_clock::now(); // measure the time taken for heap sort
	dll4.MergeSort(); // perform merge sort
	auto endMerge = chrono::high_resolution_clock::now();
	auto durationMerge = chrono::duration_cast<chrono::microseconds>(endMerge - startMerge);

	cout << "\n\nTime taken to sort the list using Merge sort: " << durationMerge.count() << " (ms)\n";
	/*cout << "\nThe sorted list: ";
	dll4.Display();

	cout << "\nGenerated list: ";
	for (int i : nums)
	{
		cout << i << " ";
	}*/



	// -------------------------------------------- Quick sort:
	dll5.insertVector(nums);

	auto startQuick = chrono::high_resolution_clock::now(); // measure the time taken for heap sort
	dll5.QuickSort(); // perform merge sort
	auto endQuick = chrono::high_resolution_clock::now();
	auto durationQuick = chrono::duration_cast<chrono::microseconds>(endQuick - startQuick);

	cout << "\n\nTime taken to sort the list using Quick sort: " << durationQuick.count() << " (ms)\n";
	/*cout << "\nThe sorted list: ";
	dll5.Display();*/

}

int main()
{

	// initialise a vector to store the list
	vector<int> nums;

	int size;
	cout << "\nEnter size of list: ";
	cin >> size;

	int range;
	cout << "\nEnter range of the list: ";
	cin >> range;

	// generates random numbers for vector nums
	generateRandomNumbers(nums, size, range);

	// display the generated array
	/*cout << "\nGenerated list: ";
	for (int i : nums)
	{
		cout << i << " ";
	}*/
	

	cout << "\nSelect Option:";
	cout << "\n\t1. List in random order.";
	cout << "\n\t2. List in ascending order.";
	cout << "\n\t3. List in descending order.";

	// get the option
	int option;
	cout << "\nYour selection: ";
	while (true)
	{
		if (cin >> option)
		{
			if (option >= 1 && option <= 3)
			{
				break;
			}
			else
			{
				cout << "Invalid input. Re-enter option.\n";
			}
		} 
		else
		{
			cin.clear();                                         // clears the error flags
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignores any remaining input
			cout << "Invalid input. Re-enter option.\n";
		}
	}
	
	// implement with option
	switch (option)
	{
	case 1:
		implementation(nums);
		break;
	case 2:
		sort(nums.begin(), nums.end()); // sort nums in ascending order
		implementation(nums);
		break;
	case 3:
		sort(nums.begin(), nums.end(), greater<int>()); // sort nums in descending order
		implementation(nums);
		break;
	}
	

	return 0;
}