#pragma once
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// define class Node with generic type:
template <typename T>
class Node {
public:
	T data;
	Node<T>* next;
	Node<T>* prev;
};


// define class Doubly Linked-list with generic type
template <typename T>
class DoublyLinkedList {
public:
	Node<T>* head; // pointer to the 1st node of list
	Node<T>* tail; // pointer to the last node of list

	DoublyLinkedList() // default constructor
	{
		head = nullptr;
		tail = nullptr;
	}

	void Push(T n); // Add an element at the end of list

	int SizeOfLL(); // Get the number of nodes in list

	void insertVector(vector<T> v); // Initialise a list with a vector
	
	void Display(); // display the list

	void BubbleSort(); 

	void InsertionSort();

	void SelectionSort();

	Node<T>* Split(Node<T>* head, int stepSize);
	Node<T>* GetTail(Node<T>* head); // get the tail of a sub-list
	void mergeSort(Node<T>** headRef);
	Node<T>* Merge(Node<T>* left, Node<T>* right);
	void MergeSort();

	Node<T>* partition(Node<T>* low, Node<T>* high);
	void quickSort(Node<T>* head, Node<T>* tail);
	void QuickSort();
};

template <typename T>
void DoublyLinkedList<T> ::Push(T n) // Add an element at the end of list
{
	Node<T>* t = new Node<T>;
	t->data = n;

	if (head == nullptr)
	{
		t->next = t->prev = nullptr;
		head = tail = t;
		return;
	}

	t->prev = tail;
	t->next = nullptr;
	tail->next = t;
	tail = t;
}

template <typename T>
int DoublyLinkedList<T> ::SizeOfLL() // Get the number of nodes in list
{
	int count = 0;
	Node<T>* p = head;
	while (p)
	{
		p = p->next;
		count++;
	}
	return count;
}

template <typename T>
void DoublyLinkedList<T> ::insertVector(vector<T> v) // Initialise a list with a vector
{
	for (T i : v)
	{
		Push(i);
	}
}

template <typename T>
void DoublyLinkedList<T> ::Display() // display the list
{
	if (head == nullptr)
	{
		return;
	}
	Node<T>* p = head;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
}


template <typename T>
void DoublyLinkedList<T> ::BubbleSort()
{
	if (head == nullptr || head->next == nullptr)
	{
		return;
	}

	for (Node<T>* p = tail; p != head; p = p->prev)
	{
		bool swapped = false;
		for (Node<T>* q = head; q != p; q = q->next)
		{
			if (q->data > q->next->data)
			{
				T t = q->data;
				q->data = q->next->data;
				q->next->data = t;
				swapped = true;
			}
		}
		if (swapped == false)
			break;
	}
}

template <typename T>
void DoublyLinkedList<T> ::InsertionSort()
{
	if (head == nullptr || head->next == nullptr)
	{
		return;
	}

	for (Node<T>* p = head->next; p != nullptr; p = p->next)
	{
		Node<T>* q = p;
		T temp = p->data;
		for (; q->prev != nullptr && q->prev->data > temp; q = q->prev)
		{
			q->data = q->prev->data;
		}
		q->data = temp;
	}
}

template <typename T>
void DoublyLinkedList<T> ::SelectionSort()
{
	if (head == nullptr || head->next == nullptr)
	{
		return;
	} 

	for (Node<T>* p = head; p != tail; p = p->next)
	{
		Node<T>* min = p;
		Node<T>* q = p->next;
		for (; q != nullptr; q = q->next)
		{
			if (q->data < min->data)
			{
				min = q;
			}
		}
		if (min != p)
		{
			T t = min->data;
			min->data = p->data;
			p->data = t;
		}
	}
}

template <typename T>
Node<T>* DoublyLinkedList<T> ::Merge(Node<T>* left, Node<T>* right) 
{
	Node<T>* result = nullptr;
	Node<T>** tail = &result;

	while (left && right) 
	{
		if (left->data <= right->data) 
		{
			*tail = left;
			left = left->next;
		}
		else 
		{
			*tail = right;
			right = right->next;
		}
		(*tail)->prev = nullptr;
		tail = &((*tail)->next);
	}

	if (left) 
	{
		*tail = left;
		left->prev = nullptr;
	}
	if (right) 
	{
		*tail = right;
		right->prev = nullptr;
	}

	return result;
}

template <typename T>
Node<T>* DoublyLinkedList<T> ::Split(Node<T>* head, int stepSize)
{
	if (head == nullptr)
		return nullptr;

	Node<T>* current = head;
	for (int i = 1; i < stepSize && current; ++i) 
	{
		current = current->next;
	}

	if (current == nullptr)
		return nullptr;

	Node<T>* nextBlock = current->next;
	current->next = nullptr;

	if (nextBlock)
		nextBlock->prev = nullptr;

	return nextBlock;
}

template <typename T>
Node<T>* DoublyLinkedList<T> ::GetTail(Node<T>* head) 
{
	if (head == nullptr) 
	{
		return nullptr;
	}

	Node<T>* tail = head;
	while (tail->next) 
	{
		tail = tail->next;
	}

	return tail;
}

template <typename T>
void DoublyLinkedList<T> ::mergeSort(Node<T>** headRef)
{
	if (*headRef == nullptr || (*headRef)->next == nullptr) 
	{
		return;  // Base case: empty list or single element, already sorted
	}

	int length = SizeOfLL();  // Get the length of the list

	// Iterate over different subarray sizes (1, 2, 4, 8, ...)
	for (int stepSize = 1; stepSize < length; stepSize *= 2) 
	{
		Node<T>* current = *headRef;
		Node<T>* result = nullptr;
		Node<T>* tail = nullptr;

		while (current) 
		{
			// Split the list into two parts of size stepSize
			Node<T>* left = current;
			Node<T>* right = Split(left, stepSize);
			current = Split(right, stepSize);

			// Merge the two sorted parts and append to the result list
			Node<T>* merged = Merge(left, right);
			if (result == nullptr) 
			{
				result = merged;
			}
			else {
				tail->next = merged;
			}

			// Update the tail to the end of the merged list
			tail = GetTail(merged);
		}

		*headRef = result;  // Update the head of the list
	}
}

template <typename T>
void DoublyLinkedList<T> ::MergeSort()
{
	mergeSort(&head);
}


template <typename T>
Node<T>* DoublyLinkedList<T> ::partition(Node<T>* low, Node<T>* high) 
{
	T pivot = high->data;
	Node<T>* i = low->prev;

	for (Node<T>* j = low; j != high; j = j->next) 
	{
		if (j->data <= pivot) 
		{
			i = (i == nullptr) ? low : i->next;
			swap(i->data, j->data);
		}
	}

	i = (i == nullptr) ? low : i->next;
	swap(i->data, high->data);

	return i;
}

template <typename T>
void DoublyLinkedList<T> ::quickSort(Node<T>* head, Node<T>* tail) 
{
	stack<Node<T>*> stack;
	stack.push(head);
	stack.push(tail);

	while (!stack.empty()) 
	{
		Node<T>* high = stack.top();
		stack.pop();
		Node<T>* low = stack.top();
		stack.pop();

		if (low != nullptr && high != nullptr && low != high && low != high->next) 
		{
			Node<T>* pivot = partition(low, high);

			// Push the sublists before and after the pivot to the stack
			stack.push(low);
			stack.push(pivot->prev);
			stack.push(pivot->next);
			stack.push(high);
		}
	}
}

template <typename T>
void DoublyLinkedList<T> ::QuickSort()
{
	quickSort(head, tail);
}