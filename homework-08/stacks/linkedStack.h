#ifndef STACKS_LINKEDSTACK_H_
#define STACKS_LINKEDSTACK_H_

#include "stackADT.h"

#include <cassert>
#include <iostream>

using namespace std;

template <class Type> struct nodeType
{
    Type info;
    nodeType<Type> *link;
};

template <class Type> class linkedStack : public stackADT<Type>
{
public:
    const linkedStack<Type> &operator=(const linkedStack<Type> &otherStack);

    /** Initialize the stack to an empty state. */
    void initializeStack();

    /** Whether or not the stack is empty. */
    bool isEmptyStack() const;

    /** Whether or not the stack is full. */
    bool isFullStack() const;

    /** Push an object of type `Type` to the end of the stack. */
    void push(const Type &newItem);

    /** Returns the last element in the stack. */
    Type top() const;

    /** Removes the last element from the stack. */
    void pop();

    linkedStack();
    linkedStack(const linkedStack<Type> &otherStack);
    ~linkedStack();

private:
    nodeType<Type> *stackTop;
    void copyStack(const linkedStack<Type> &otherStack);
};

template <class Type>
const linkedStack<Type> &
linkedStack<Type>::operator=(const linkedStack<Type> &otherStack)
{
    if (this != &otherStack) { copyStack(otherStack); }
    return *this;
}

template <class Type> void linkedStack<Type>::initializeStack()
{
    nodeType<Type> *tempNode;
    while (stackTop != nullptr)
    {
        tempNode = stackTop;
        stackTop = stackTop->link;
        delete tempNode;
    }
}

template <class Type> bool linkedStack<Type>::isEmptyStack() const
{
    return stackTop == nullptr;
}

template <class Type> bool linkedStack<Type>::isFullStack() const
{
    return false; // Linked lists are never full.
}

template <class Type> void linkedStack<Type>::push(const Type &newItem)
{
    // nodeType<Type> *newNode = new nodeType<Type>;
    nodeType<Type> *newNode;
    newNode = new nodeType<Type>;
    newNode->info = newItem;
    newNode->link = stackTop;
    stackTop = newNode;
}

template <class Type> Type linkedStack<Type>::top() const
{
    assert(stackTop != nullptr);
    return stackTop->info;
}

template <class Type> void linkedStack<Type>::pop()
{
    assert(stackTop != nullptr);

    nodeType<Type> *tempNode;

    tempNode = stackTop;
    stackTop = tempNode->link;
    delete tempNode;
}

template <class Type> linkedStack<Type>::linkedStack() { stackTop = nullptr; }

template <class Type>
linkedStack<Type>::linkedStack(const linkedStack<Type> &otherStack)
{
    stackTop = nullptr;
    copyStack(otherStack);
}

template <class Type> linkedStack<Type>::~linkedStack() { initializeStack(); }

template <class Type>
void linkedStack<Type>::copyStack(const linkedStack<Type> &otherStack)
{
    nodeType<Type> *newNode, *current, *last;
    if (stackTop != nullptr) { initializeStack(); }
    if (otherStack.stackTop == nullptr) { stackTop = nullptr; }
    else
    {
        current = otherStack.stackTop;
        stackTop = new nodeType<Type>;
        stackTop->info = current->info;
        stackTop->link = nullptr;
        last = stackTop;
        current = current->link;

        while (current != nullptr)
        {
            newNode = new nodeType<Type>;
            newNode->info = current->info;
            newNode->link = nullptr;
            last->link = newNode;
            last = newNode;
            current = current->link;
        }
    }
}

#endif
