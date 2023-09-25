#include "arrayListType.h"
#include <iostream>

using namespace std;

bool arrayListType::isEmpty() const { return length == 0; }

bool arrayListType::isFull() const { return length == maxSize; }

int arrayListType::listSize() const { return length; }

int arrayListType::maxListSize() const { return maxSize; }

void arrayListType::print() const
{
    for (int idx = 0; idx < length; idx++)
    {
        cout << list[idx] << " ";
    }
    cout << endl;
}

bool arrayListType::isItemAtEqual(int location, int item) const
{
    if (location < 0 || location >= length)
    {
        cout << "The location of the item to be removed is out of range.\n";
        return false;
    }
    return list[location] == item;
}

void arrayListType::removeAt(int location)
{
    if (location < 0 || location >= length)
    {
        cout << "The location of the item to be removed is out of range.\n";
    }
    else
    {
        // Shift the elements of array after `location` back one memory location
        for (int idx = location; idx < length - 1; idx++)
        {
            list[idx] = list[idx + 1];
        }
        length--;
    }
}

const void arrayListType::retrieveAt(int location, int &retItem)
{
    if (location < 0 || location >= length)
    {
        throw out_of_range(
            "The location of the item to be retrieved is out of range.\n"
        );
    }
    else { retItem = list[location]; }
}

void arrayListType::clearList() { length = 0; }

int &arrayListType::operator[](int idx)
{
    if (idx < 0 || idx >= length)
    {
        throw out_of_range("Index out of range.\n");
    }
    else { return list[idx]; }
}

arrayListType &arrayListType::operator=(arrayListType &otherList)
{
    if (this != &otherList)
    {
        if (length != otherList.listSize())
        {
            cout << "Arrays are different sizes. Cannot complete assignment.\n";
            return *this;
        }

        for (int idx = 0; idx < length; idx++)
        {
            otherList.retrieveAt(idx, list[idx]);
        }
    }
    return *this;
}

arrayListType::arrayListType(int size)
{
    if (size < 0)
    {
        cout << "The array size must be positive. Creating an array of size "
                "100.\n";

        maxSize = 100;
    }
    else { maxSize = size; }
    length = 0;
    list = new int[maxSize];
}

arrayListType::arrayListType(const arrayListType &otherList)
{
    length = otherList.listSize();
    maxSize = otherList.maxListSize();

    list = new int[maxSize];

    // Deep-copy `otherList` into this one.
    for (int idx = 0; idx < length; idx++)
    {
        list[idx] = otherList.list[idx];
    }
}

arrayListType::~arrayListType() { delete[] list; }