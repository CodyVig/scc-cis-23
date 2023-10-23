#ifndef _STACKADT_H_
#define _STACKADT_H_

#include <iostream>

using namespace std;

template <class Type> class stackADT
{
public:
    /** Initialize the stack to an empty state. */
    virtual void initializeStack() = 0;

    /** Whether or not the stack is empty. */
    virtual bool isEmptyStack() const = 0;

    /** Whether or not the stack is full. */
    virtual bool isFullStack() const = 0;

    /** Push an object of type `Type` to the end of the stack. */
    virtual void push(const Type &) = 0;

    /** Returns the last element in the stack. */
    virtual Type top() const = 0;

    /** Removes the last element from the stack. */
    virtual void pop() = 0;
};

#endif