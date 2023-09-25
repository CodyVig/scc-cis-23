#include "orderedArrayListType.h"
#include <iostream>

using namespace std;

void orderedArrayListType::insertAt(int location, int insertItem)
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

void orderedArrayListType::insertEnd(int insertItem)
{
    if (length >= maxSize)
    {
        throw domain_error("Array is already at max capactiy. Insert failed.");
    }
    list[length] = insertItem;
    length++; // Can I just call `list[length++] = insertItem`?
}

void orderedArrayListType::replaceAt(int location, int repItem) // WHY??
{
    if (location < 0 || location >= length)
    {
        throw out_of_range(
            "The position of the item to be replaced is out of range."
        );
    }
    list[location] = repItem; // This does not preserve order.
}

int orderedArrayListType::seqSearch(int searchItem) const
{
    int loc = 0;
    bool found = false;

    while (loc < length && !found)
    {
        if (list[loc] == searchItem) { found = true; }
        else if (list[loc] > searchItem) { return -1; }
        else { loc++; }
    }

    if (found) { return loc; }
    else { return -1; }
}

void orderedArrayListType::insert(int insertItem)
{
    if (length == 0) { list[length++] = insertItem; }
    if (length == maxSize)
    {
        throw domain_error("Cannot insert into a full list.");
    }

    // Find the location in the list where to insert insertItem.
    bool found = false;

    for (int loc = 0; loc < length; loc++)
    {
        if (list[loc] >= insertItem)
        {
            found = true;
            insertAt(loc, insertItem);
        }
    }
    if (!found) { insertEnd(insertItem); }
}

void orderedArrayListType::remove(int removeItem)
{
    int loc;

    if (length == 0)
    {
        throw domain_error("Cannot delete from an empty list.");
    }
    else
    {
        loc = seqSearch(removeItem); // Does not remove all occurances.

        if (loc != -1) { removeAt(loc); }
        else
        {
            throw out_of_range("The item to be deleted is not in the list.");
        }
    }
}

orderedArrayListType::orderedArrayListType(int size) {}
