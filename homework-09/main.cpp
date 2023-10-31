/*****************************************************************************
 * Author:       Cody Vig
 * Assignment:   Homework 9
 * Due Date:     November 2, 2023.
 *****************************************************************************/

// #include "binarySearch.h"
#include <iostream>

using namespace std;

template <class Type>
int doRecursiveSearch(const Type[], const Type &, int, int);

template <class Type>
int recursiveBinarySearch(const Type[], int, const Type &);

/** Test recursive implementation of binary search. */
int main()
{
    int sortedList[] = {1, 1, 2, 3, 5, 8};
    int n = 6;
    int element, idx;

    cout << "The array in question is: [ ";
    for (int i = 0; i < n; i++)
    {
        cout << sortedList[i] << " ";
    }
    cout << "]" << endl;

    cout << "Enter the element you would like to search for: ";
    cin >> element;

    idx = recursiveBinarySearch<int>(sortedList, n, element);

    if (idx == -1)
    {
        cout << "Element `" << element << "` is not in the list." << endl;
    }
    else
    {
        cout << "The index of element `" << element << "` in the list is "
             << idx << "." << endl;
    }

    return 0;
}

/** Helper function for `recursiveBinarySearch()` */
template <class Type>
int doRecursiveSearch(const Type list[], const Type &item, int first, int last)
{
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