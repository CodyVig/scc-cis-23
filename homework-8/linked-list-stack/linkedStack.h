#ifndef LINKEDSTACKTYPE_H_
#define LINKEDSTACKTYPE_H_

#include "../stackADT.h" // In parent directory

#include <cassert>
#include <iostream>

using namespace std;

template <class Type> struct nodeType
{
    Type info;
    nodeType<Type> *link;
};

template <class Type> class linkedStackType : public stackADT
{
public:
    const linkedStackType<Type> &
    operator=(const linkedStackType<Type> &otherStack);

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

    linkedStackType();
    linkedStackType(const linkedStackType<Type> &otherStack);
    ~linkedStackType();

private:
    nodeType<Type> *stackTop;
    void copyStack(const linkedStackType<Type> *otherStack);
};

template <class Type>
const linkedStackType<Type> &
linkedStackType<Type>::operator=(const linkedStackType<Type> &otherStack)
{
}

template <class Type> void linkedStackType<Type>::initializeStack() {}

template <class Type> bool linkedStackType<Type>::isEmptyStack() const {}

template <class Type> bool linkedStackType<Type>::isFullStack() const {}

template <class Type> void linkedStackType<Type>::push(const Type &newItem) {}

template <class Type> Type linkedStackType<Type>::top() const {}

template <class Type> void linkedStackType<Type>::pop() {}

template <class Type> linkedStackType<Type>::linkedStackType() {}

template <class Type>
linkedStackType<Type>::linkedStackType(const linkedStackType<Type> &otherStack)
{
}

template <class Type> linkedStackType<Type>::~linkedStackType() {}

template <class Type>
void linkedStackType<Type>::copyStack(const linkedStackType<Type> *otherStack)
{
}

#endif
