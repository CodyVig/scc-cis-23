// Header file QueueAsArray

#ifndef QUEUES_LISTQUEUE_H_
#define QUEUES_LISTQUEUE_H_

#include <cassert>
#include <iostream>

#include "queueADT.h"

using namespace std;

template <class Type> class listQueue : public queueADT<Type>
{
public:
    /** Overload the assignment operator. */
    const listQueue<Type> &operator=(const listQueue<Type> &);

    /** Function to determine whether the queue is empty. */
    bool isEmptyQueue() const;

    /** Function to determine whether the queue is full. */
    bool isFullQueue() const;

    /** Function to initialize the queue to an empty state. */
    void initializeQueue();

    /** Function to return the first element of the queue. */
    Type front() const;

    /** Function to return the last element of the queue. */
    Type back() const;

    /** Function to add queueElement to the queue. */
    void addQueue(const Type &queueElement);

    /** Function to remove the first element of the queue. */
    void deleteQueue();

    listQueue(int queueSize = 100);

    listQueue(const listQueue<Type> &otherQueue);

    ~listQueue();

private:
    int maxQueueSize; // variable to store the maximum queue size
    int count;        // variable to store the number of elements in the queue
    int queueFront;   // variable to point to the first element of the queue
    int queueRear;    // variable to point to the last element of the queue
    Type *list;       // pointer to the array that holds the queue elements
};

template <class Type> bool listQueue<Type>::isEmptyQueue() const
{
    return (count == 0);
}

template <class Type> bool listQueue<Type>::isFullQueue() const
{
    return (count == maxQueueSize);
}

template <class Type> void listQueue<Type>::initializeQueue()
{
    queueFront = 0;
    queueRear = maxQueueSize - 1;
    count = 0;
}

template <class Type> Type listQueue<Type>::front() const
{
    assert(!isEmptyQueue());
    return list[queueFront];
}

template <class Type> Type listQueue<Type>::back() const
{
    assert(!isEmptyQueue());
    return list[queueRear];
} // end back

template <class Type> void listQueue<Type>::addQueue(const Type &newElement)
{
    if (!isFullQueue())
    {
        queueRear = (queueRear + 1) % maxQueueSize;
        count++;
        list[queueRear] = newElement;
    }
    else { cout << "Cannot add to a full queue." << endl; }
}

template <class Type> void listQueue<Type>::deleteQueue()
{
    if (!isEmptyQueue())
    {
        count--;
        queueFront = (queueFront + 1) % maxQueueSize;
    }
    else { cout << "Cannot remove from an empty queue." << endl; }
}

template <class Type> listQueue<Type>::listQueue(int queueSize)
{
    if (queueSize <= 0)
    {
        cout << "Size of the array to hold the queue must "
             << "be positive." << endl;
        cout << "Creating an array of size 100." << endl;

        maxQueueSize = 100;
    }
    else
        maxQueueSize = queueSize;

    queueFront = 0;
    queueRear = maxQueueSize - 1;
    count = 0;
    list = new Type[maxQueueSize];
}

template <class Type> listQueue<Type>::~listQueue() { delete[] list; }

template <class Type>
const listQueue<Type> &
listQueue<Type>::operator=(const listQueue<Type> &otherQueue)
{
    cout << "Write the definition of the function "
         << "to overload the assignment operator." << endl;
}

template <class Type>
listQueue<Type>::listQueue(const listQueue<Type> &otherQueue)
{
    cout << "Write the definition of the copy constructor." << endl;
}

#endif
