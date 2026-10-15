// William Kavanagh, w.kavanagh@abertay.ac.uk
// DATE: Spring 2022 -- UPDATE Summer (well, autumn) 2025
// AX1.2 Provided source file for testing

#include <iostream>
#include "StackAndQueue.h"

// Sample main() method for testing your Stack and Queue implementations.
// This provides a non-exhaustive set of tests to help you check your work.
int main()
{
	std::cout << "CMP201-AX1.2: Stacks and Queues\n";
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";

	// === Test Case 1: ArrayStack<int> ===
	std::cout << "--- Testing ArrayStack with integers ---\n";
	ArrayStack<int> stack;
	std::cout << "Initial state:\n";
	stack.Display();
	stack.IsEmpty() ? std::cout << "IsEmpty appears to work for empty stacks\n" : std::cout << "IsEmpty does not appear to work for empty stacks\n";

	// Test Push
	stack.Push(10);
	stack.Push(20);
	stack.Push(30);
	std::cout << "\nAfter Push(10), Push(20), Push(30):\n";
	stack.Display();
	!stack.IsEmpty() ? std::cout << "IsEmpty appears to work for full stacks\n" : std::cout << "IsEmpty does not appear to work for full stacks\n";


	// Test Peek and Pop
	if (!stack.IsEmpty())
	{
		std::cout << "\nPeeking at top element: " << stack.Peek() << "\n";
		stack.Pop();
		std::cout << "After Pop():\n";
		stack.Display();
	}

	// === Test Case 2: QueueList<std::string> ===
	std::cout << "\n--- Testing QueueList with strings ---\n";
	QueueList<std::string> queue;
	std::cout << "Initial state:\n";
	queue.Display();

	// Test Enqueue
	queue.Enqueue("First");
	queue.Enqueue("Second");
	queue.Enqueue("Third");
	std::cout << "\nAfter Enqueue(\"First\"), Enqueue(\"Second\"), Enqueue(\"Third\"):\n";
	queue.Display();

	// check that isempty returns false for a queue with things in it
	!queue.IsEmpty() ? std::cout << "IsEmpty appears to work for queues\n" : std::cout << "IsEmpty does not appear to work for queues\n";

	// Test Front and Dequeue
	if (!queue.IsEmpty())
	{
		std::cout << "\nValue at front of queue: " << queue.Front() << "\n";
		queue.Dequeue();
		std::cout << "After Dequeue():\n";
		queue.Display();
	}

	// Test Dequeue until empty
	std::cout << "\nDequeuing all elements...\n";
	while (!queue.IsEmpty())
	{
		queue.Dequeue();
	}
	std::cout << "After dequeuing all elements:\n";
	queue.Display();
	queue.IsEmpty() ? std::cout << "IsEmpty appears to work for empty queues\n" : std::cout << "IsEmpty does not appear to work for empty queues\n";
	queue.Front();
	
	std::cout << "\n--- End of Tests ---\n";

	return 0;
}