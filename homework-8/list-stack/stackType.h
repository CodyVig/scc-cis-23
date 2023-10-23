#ifndef STACKTYPE_H_
#define STACKTYPE_H_

#include "../stackADT.h" // In parent directory

#include <cassert>
#include <iostream>

using namespace std;

template <class Type> class stackType : public stackADT<Type>
{
public:
    const stackType<Type> &operator=(const stackType<Type> &);

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

    stackType(int stackSize = 100);

    /**
     * Copy constructor is called when stack object is passed as a value
     * parameter to a function.
     */
    stackType(const stackType<Type> &otherStack);

    ~stackType();

private:
    int maxStackSize;
    int stackTop; // Index of the top of the stack.
    Type *list;
    void copyStack(const stackType<Type> &otherStack);
};

template <class Type>
const stackType<Type> &
stackType<Type>::operator=(const stackType<Type> &otherStack)
{
    copyStack(otherStack);
}

template <class Type> void stackType<Type>::initializeStack()
{
    delete[] list;
    list = new Type[maxStackSize];
    stackTop = 0;
}

template <class Type> bool stackType<Type>::isEmptyStack() const
{
    return stackTop == 0;
}

template <class Type> bool stackType<Type>::isFullStack() const
{
    return stackTop == maxStackSize;
}

template <class Type> void stackType<Type>::push(const Type &newItem)
{
    if (!isFullStack())
    {
        list[stackTop] = newItem;
        stackTop++;
    }
    else
    {
        cout << "Stack is already full. Cannot add to a full stack." << endl;
    }
}

template <class Type> Type stackType<Type>::top() const
{
    assert(stackTop != 0);
    return list[stackTop - 1];
}

template <class Type> void stackType<Type>::pop() { stackTop--; }

template <class Type> stackType<Type>::stackType(int stackSize)
{
    if (stackSize <= 0)
    {
        cout << "Size of the stack must be positive. "
             << "Creating an array of size 100." << endl;

        maxStackSize = 100;
    }
    else { maxStackSize = stackSize; }
    stackTop = 0;
    list = new Type[maxStackSize];
}

template <class Type>
stackType<Type>::stackType(const stackType<Type> &otherStack)
{
    list = nullptr;
    copyStack(otherStack);
}

template <class Type> stackType<Type>::~stackType() { delete[] list; }

template <class Type>
void stackType<Type>::copyStack(const stackType<Type> &otherStack)
{
    delete[] list;

    maxStackSize = otherStack->maxStackSize;
    stackTop = otherStack->stackTop;

    list = new Type[maxStackSize];

    for (int idx = 0; idx < stackTop; idx++)
    {
        list[idx] = otherStack->list[idx];
    }
}

#endif