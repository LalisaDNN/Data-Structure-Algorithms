#include "DoublyLL.h"
#include <ctime>
#include <chrono>

void InsertRandom(DoublyLinkedList<int>& dll, int size, int range)
{
	srand(time(0));
	for (int i = 0; i < size; i++)
	{
		int n = rand() % range + 1; // generates random elements for the list
		dll.Push(n);
	}
}

int main()
{
	DoublyLinkedList<int> dll1; // bubble
	DoublyLinkedList<int> dll2; // insertion
	DoublyLinkedList<int> dll3; // selection

	int size;
	cout << "\nEnter size of list: ";
	cin >> size;

	int range;
	cout << "\nEnter range of the list: ";
	cin >> range;
	

	//// -------------------------------------------- Bubble sort:
	
	//InsertElement(dll1, size, range); // insert elements for bubble sort
	///*cout << "\nList generated to test bubble sort: ";
	//dll1.Display();*/

	//auto startBubble = chrono::high_resolution_clock::now(); // measure the time taken for bubble sort
	//dll1.BubbleSort(); // perform bubble sort
	//auto endBubble = chrono::high_resolution_clock::now();
	//auto durationBubble = chrono::duration_cast<chrono::microseconds>(endBubble - startBubble);

	///*cout << "\n\nList sorted using Bubble sort: ";
	//dll1.Display();*/

	//cout << "\n\nTime taken to sort the list using Bubble sort: " << durationBubble.count() << " (ms)\n";

	
	// -------------------------------------------- Insertion sort:

	InsertRandom(dll2, size, range);
	/*cout << "\nList generated to test Insertion sort: ";
	dll2.Display();*/

	auto startInsertion = chrono::high_resolution_clock::now(); // measure the time taken for insertion sort
	dll2.InsertionSort(); // perform insertion sort
	auto endInsertion = chrono::high_resolution_clock::now();
	auto durationInsertion = chrono::duration_cast<chrono::microseconds>(endInsertion - startInsertion);

	/*cout << "\n\nList sorted using Insertion sort: ";
	dll2.Display();*/

	cout << "\n\nTime taken to sort the list using Insertion sort: " << durationInsertion.count() << " (ms)\n";


	// -------------------------------------------- Selection sort:
	
	//InsertElement(dll3, size, range);
	///*cout << "\nList generated to test Selection sort: ";
	//dll3.Display();*/

	//auto startSelection = chrono::high_resolution_clock::now(); // measure the time taken for selection sort
	//dll3.SelectionSort(); // perform insertion sort
	//auto endSelection = chrono::high_resolution_clock::now();
	//auto durationSelection = chrono::duration_cast<chrono::microseconds>(endSelection - startSelection);

	///*cout << "\n\nList sorted using Selection sort: ";
	//dll3.Display();*/

	//cout << "\n\nTime taken to sort the list using Selection sort: " << durationSelection.count() << " (ms)\n";


	return 0;
}