#include "unorderedArrayListType.h"
#include <iostream>

using namespace std;

void unorderedArrayListType::insertAt(int location, int insertItem)
{
    if (location < 0 || location >= length)
    {
        throw out_of_range(
            "The position of the item to be inserted is out of range.\n"
        );
    }
    if (length >= maxSize)
    {
        throw domain_error("Array is already at max capactiy. Insert failed.");
    }
    for (int idx = length; idx > location; idx--)
    {
        list[idx] = list[idx - 1];
    }
    list[location] = insertItem;
    length++;
}

void unorderedArrayListType::insertEnd(int insertItem)
{
    if (length >= maxSize)
    {
        throw domain_error("Array is already at max capactiy. Insert failed.");
    }
    list[length] = insertItem;
    length++;
}

void unorderedArrayListType::replaceAt(int location, int repItem)
{
    if (location < 0 || location >= length)
    {
        throw out_of_range(
            "The position of the item to be replaced is out of range.\n"
        );
    }
    list[location] = repItem;
}

int unorderedArrayListType::seqSearch(int searchItem) const
{
    int loc = 0;
    bool found = false;

    while (loc < length && !found)
    {
        if (list[loc] == searchItem) { found = true; }
        else { loc++; }
    }

    if (found) { return loc; }
    else { return -1; }
}

void unorderedArrayListType::remove(int removeItem)
{
    int loc;

    if (length == 0)
    {
        throw domain_error("Cannot delete from an empty list.");
    }
    else
    {
        loc = seqSearch(removeItem);

        if (loc != -1) { removeAt(loc); }
        else
        {
            throw out_of_range("The item to be deleted is not in the list.");
        }
    }
}

unorderedArrayListType::unorderedArrayListType(int size) : arrayListType(size)
{
}
