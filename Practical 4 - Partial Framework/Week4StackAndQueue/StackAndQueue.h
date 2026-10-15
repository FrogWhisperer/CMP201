// William Kavanagh, w.kavanagh@abertay.ac.uk
// DATE: Spring 2022 -- UPDATE Summer (well, autumn) 2025
// AX1.2 Stacks & Queues: Partial Framework

// Only add code in the //TODO sections and in main() in StackAndQueue.cpp

#pragma once

#ifdef ENABLE_GRADING           // don't mind me.
    extern int g_nodesDeleted;
#endif

template<class T>
class ArrayStack
{
public:
    // default initial values, do not change from 8 and -1
	int capacity = 8;
	int stackTop = -1;
	T* arr;

	ArrayStack();

	void Pop();
    bool IsEmpty();
	T Peek();
	void Push(T n);
	void Display();
	void DoubleArray();
};

template <class T>
class Node
{
public:
	Node(T n);
    #ifdef ENABLE_GRADING   
        ~Node() { g_nodesDeleted++; }
    #endif

	T data;
	Node* next;
};

template <class T> class QueueList
{
public:
	Node<T>* front;
	Node<T>* back;

	QueueList();

    bool IsEmpty();
	void Enqueue(T n);
    T Front();
    void Dequeue();
	void Display();
};

// Default constructor, init array
template <class T>
ArrayStack<T>::ArrayStack()
{
    // Provided in partial framework
    arr = new T[capacity];
}

// Remove element at the top of the stack
template <class T>
void ArrayStack<T>::Pop()
{
    // TODO: ASSESSED [0.5]
    if (!IsEmpty())
    {
        // Move stack top
        stackTop--;
    }
}

// return true if stack is empty
template<class T>
bool ArrayStack<T>::IsEmpty()
{
    // TODO: Assessed [0.5]

    // Check if stack has elements
    if (stackTop == -1)
    {
        return true;
    }
    return false;
}

// Return value from top of stack
template <class T>
T ArrayStack<T>::Peek()
{
    // TODO: Assessed [0.5]
    if (!IsEmpty())
    {
        // Return top value of stack
        T output = arr[stackTop];
        return T(output);
    }
}

// Add element to top of stack, 
// calls DoubleArray() where appropriate
template <class T>
void ArrayStack<T>::Push(T n)
{
    // TODO: ASSESSED [0.5]
    
    // Increase stack top
    stackTop++;

    // Check if there is space in array
    if (stackTop == capacity)
    {
        DoubleArray();
    }

    // Add value to top of stack
    arr[stackTop] = n;
}

// Print elements in Stack neatly
template <class T>
void ArrayStack<T>::Display()
{
    if (IsEmpty())
    {
        std::cout << "Stack: [] (empty)\n";
        return;
    }

    std::cout << "Stack (top to bottom):\n";
    for (int i = stackTop; i >= 0; i--)
    {
        std::cout << "[ " << arr[i] << " ]";
        if (i == stackTop)
        {
            std::cout << " <-- top";
        }
        std::cout << "\n";
    }
}

// Updates array pointer to new array of double the size
// elements are copied in from old array with position preserved.
template <class T>
void ArrayStack<T>::DoubleArray()
{
    // Provided in partial framework
    capacity *= 2;
    T* newArr = new T[capacity];
    for (int i = 0; i < capacity / 2; ++i)
    {
        newArr[i] = arr[i];
    }
    delete[] arr; // free old memory
    arr = newArr;
}

// Node constructor
template <class T>
Node<T>::Node(T n)
{
    // Provided in partial framework
    data = n;
    next = nullptr;
}

// QL constructor
template <class T>
QueueList<T>::QueueList()
{
    // Provided in partial framework
    front = back = nullptr;
}

template <class T>
bool QueueList<T>::IsEmpty()
{
    // TODO: Assessed [0.5]
    // Check if front points to anything
    if (front == nullptr)
    {
        return true;
    }
    return false;
}

// Add item to back of queue
template <class T>
void QueueList<T>::Enqueue(T n)
{
    // TODO: ASSESSED [1]

    // Check if there is no front
    if (IsEmpty())
    {
        // Create Node and point front to it
        front = new Node<T>(n);

        // Set back to new node
        back = front;
    }
    else
    {
        // Create Node and point back to it
        back->next = new Node<T>(n);

        // Move back to new node
        back = back->next;
    }
}

template<class T>
T QueueList<T>::Front()
{
    // TODO: Assessed [0.5]
    if (!IsEmpty())
    {
        // Return front of queue
        T output = front->data;
        return T(output);
    }
}

// Remove item from front of queue
template <class T>
void QueueList<T>::Dequeue()
{
    // TODO: ASSESSED [1]
    if (!IsEmpty())
    {
        // Get front
        Node<T>* temp = front;

        // Check if front is the only element
        if (front == back)
        {
            front = nullptr;
        }
        else
        {
            // Make front 2nd value in queue
            front = front->next;
        }

        // Delete old front
        delete temp;
    }
}

// Print elements in Queue neatly
template <class T>
void QueueList<T>::Display()
{
    if (IsEmpty())
    {
        std::cout << "Queue: [] (empty)\n";
        return;
    }

    std::cout << "Queue (front to back):\n[ ";
    Node<T>* current = front;
    while (current != nullptr)
    {
        std::cout << current->data;
        if (current == front) std::cout << " (front)";
        if (current == back) std::cout << " (back)";

        if (current->next != nullptr)
        {
            std::cout << " -> ";
        }
        current = current->next;
    }
    std::cout << " ]\n";
}
