#include <iostream>

using namespace std;

/**
 * Returns the index of `item` in list `list`, if it exists, using a linear
 * search. If `item` is not present in the list, returns -1.
 *
 * @param `list`: The array of interest.
 * @param `length`: The length of the array.
 * @param `item`: A reference to the item for which we are searching.
 * @param `sorted`: Whether or not the list is sorted (defaults to `false`).
 * @return The index of `item` in `list`, or `-1` if not in `list`.
 */
template <class Type>
int sequentialSearch(
    const Type list[], int length, const Type &item, bool sorted = false
)
{
    int location = 0;
    Type currentItem;
    bool found = false;

    while (location < length && !found)
    {
        currentItem = list[location];

        if (currentItem == item)
        {
            found = true;
            break;
        }
        else if (sorted && currentItem > item) { break; }
        else { location++; }
    }

    if (found) { return location; }
    else { return -1; }
}

/** Helper function for `recursiveSequentialSearch`. */
template <class Type>
int recSeqSearch(const Type list[], const Type &item, int first, int last)
{
    if (first <= last)
    {
        if (list[first] == item) { return first; }
        else { return recSeqSearch(list, item, first++, last); }
    }
    else { return -1; }
}

/**
 * Returns the index of `item` in a sorted list `list`, if it exists, using
 * recursion. If `item` is not present in the list, returns -1.
 *
 * @param `list`: The sorted array of interest.
 * @param `length`: The length of the array.
 * @param `item`: A reference to the item for which we are searching.
 * @return The index of `item` in `list`, or `-1` if not in `list`.
 */
template <class Type>
int recursiveSequentialSearch(const Type list[], int length, const Type &item)
{
    return recSeqSearch(list, item, 0, length - 1);
}
