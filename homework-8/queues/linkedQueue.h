// Header file linkedQueue.h

#ifndef QUEUES_LINKEDQUEUE_H_
#define QUEUES_LINKEDQUEUE_H_

#include "queueADT.h"
#include <cassert>
#include <iostream>

using namespace std;

template <class Type> struct nodeType
{
    Type info;
    nodeType<Type> *link;
};

template <class Type> class linkedQueue : public queueADT<Type>
{
public:
    /** Overload the assignment operator. */
    const linkedQueue<Type> &operator=(const linkedQueue<Type> &);

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

    /** Function  to remove the first element of the queue. */
    void deleteQueue();

    linkedQueue();

    linkedQueue(const linkedQueue<Type> &otherQueue);

    ~linkedQueue();

private:
    nodeType<Type> *queueFront;
    nodeType<Type> *queueRear;
};

template <class Type> linkedQueue<Type>::linkedQueue()
{
    queueFront = nullptr;
    queueRear = nullptr;
}

template <class Type> bool linkedQueue<Type>::isEmptyQueue() const
{
    return (queueFront == nullptr);
}

template <class Type> bool linkedQueue<Type>::isFullQueue() const
{
    return false;
}

template <class Type> void linkedQueue<Type>::initializeQueue()
{
    nodeType<Type> *temp;

    while (queueFront != nullptr)
    {
        temp = queueFront;
        queueFront = queueFront->link;
        delete temp;
    }

    queueRear = nullptr;
}

template <class Type> void linkedQueue<Type>::addQueue(const Type &newElement)
{
    nodeType<Type> *newNode;

    newNode = new nodeType<Type>;

    newNode->info = newElement;
    newNode->link = nullptr;

    if (queueFront == nullptr)
    {
        queueFront = newNode;
        queueRear = newNode;
    }
    else
    {
        queueRear->link = newNode;
        queueRear = queueRear->link;
    }
}

template <class Type> Type linkedQueue<Type>::front() const
{
    assert(queueFront != nullptr);
    return queueFront->info;
}

template <class Type> Type linkedQueue<Type>::back() const
{
    assert(queueRear != nullptr);
    return queueRear->info;
}

template <class Type> void linkedQueue<Type>::deleteQueue()
{
    nodeType<Type> *temp;

    if (!isEmptyQueue())
    {
        temp = queueFront;
        queueFront = queueFront->link;

        delete temp;

        if (queueFront == nullptr) queueRear = nullptr;
    }
    else
        cout << "Cannot remove from an empty queue" << endl;
}

template <class Type> linkedQueue<Type>::~linkedQueue() {}

template <class Type>
const linkedQueue<Type> &
linkedQueue<Type>::operator=(const linkedQueue<Type> &otherQueue)
{
}

template <class Type>
linkedQueue<Type>::linkedQueue(const linkedQueue<Type> &otherQueue)
{
}

#endif
