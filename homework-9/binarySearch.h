#include <iostream>

using namespace std;

/**
 * Returns the index of `item` in list `list`, if it exists, using a binary
 * search. If `item` is not present in the list, returns -1.
 *
 * @param `list`: The sorted array of interest.
 * @param `length`: The length of the array.
 * @param `item`: A reference to the item for which we are searching.
 * @return The index of `item` in `list`, or `-1` if not in `list`.
 */
template <class Type>
int binarySearch(const Type list[], int length, const Type &item)
{
    int first = 0;
    int last = length - 1;
    int middle;
    bool found = false;

    while (first <= last && !found)
    {
        middle = (first + last) / 2;

        if (list[middle] == item) { found = true; }
        else if (list[middle] > item) { last = middle - 1; }
        else { first = middle + 1; }
    }

    if (found) { return middle; }
    else { return -1; }
}

/** Helper function for `recursiveBinarySearch()` */
template <class Type>
int doRecursiveSearch(const Type list[], const Type &item, int first, int last)
{
    cout << "First = " << first << ", Last = " << last << endl;
    if (first > last) { return -1; }

    int middle = (first + last) / 2;

    if (list[middle] == item) { return middle; }
    else if (list[middle] > item)
    {
        return doRecursiveSearch(list, item, first, middle - 1);
    }
    else { return doRecursiveSearch(list, item, middle + 1, last); }
}

/**
 * Returns the index of `item` in list `list`, if it exists, using a binary
 * search with recursion. If `item` is not present in the list, returns -1.
 *
 * @param `list`: The sorted array of interest.
 * @param `length`: The length of the array.
 * @param `item`: A reference to the item for which we are searching.
 * @return The index of `item` in `list`, or `-1` if not in `list`.
 */
template <class Type>
int recursiveBinarySearch(const Type list[], int length, const Type &item)
{
    int first = 0;
    int last = length - 1;
    return doRecursiveSearch(list, item, first, last);
}
