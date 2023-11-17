/*****************************************************************************
 * Author:       Cody Vig
 * Assignment:   Homework 10
 * Due Date:     November 16, 2023.
 *****************************************************************************/

#include <iostream>

using namespace std;

// Functions for Problem 6
template <class elemType> void selectionSort(elemType[], int);
template <class elemType> void swapIndices(elemType[], int, int);
template <class elemType> int maxLocation(elemType[], int, int);

// Functions for problem 7
template <class elemType> void mergeSort(elemType[], int);
template <class elemType> void recMergeSort(elemType[], int, int);
template <class elemType>
void mergeLists(elemType[], elemType[], int, int, int);

/**
 * Test solutions for Problem 6 and Problem 7.
 *
 * @param argc: The number of command line arguments
 * @param argv: A pointer to a character array of command line arguments.
 */
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "You must pass exactly one command line argument." << endl;
        cout << "Use either `main 6` for problem 6 or `main 7` for problem 7."
             << endl;

        return EXIT_FAILURE;
    }

    // Test problem 6
    if (atof(argv[1]) == 6)
    {
        cout << "Testing Problem 6...\n" << endl;

        int list[5] = {2, 4, 3, 5, 1};

        // Print the original list
        cout << "Before using selection sort, list = [";
        for (int idx = 0; idx < 4; idx++)
        {
            cout << list[idx] << ", ";
        }
        cout << list[4] << "]" << endl;

        // Sort the list in descending order
        selectionSort(list, 5);

        // Print the sorted list
        cout << "After using selection sort, list  = [";
        for (int idx = 0; idx < 4; idx++)
        {
            cout << list[idx] << ", ";
        }
        cout << list[4] << "]" << endl;

        return 0;
    }

    // Test problem 7
    if (atof(argv[1]) == 7)
    {
        cout << "Testing Problem 7...\n" << endl;

        int list[5] = {2, 4, 3, 5, 1};

        // Print the original list
        cout << "Before using merge sort, list = [";
        for (int idx = 0; idx < 4; idx++)
        {
            cout << list[idx] << ", ";
        }
        cout << list[4] << "]" << endl;

        // Sort the list in ascending order
        mergeSort(list, 5);

        // Print the sorted list
        cout << "After using merge sort, list  = [";
        for (int idx = 0; idx < 4; idx++)
        {
            cout << list[idx] << ", ";
        }
        cout << list[4] << "]" << endl;

        return 0;
    }

    // If we made it here, the user did not use the proper command line argument
    cout << "Invalid usage of `main`." << endl;
    cout << "Use either `main 6` for problem 6 or `main 7` for problem 7."
         << endl;

    return EXIT_FAILURE;
}

/*****************************************************************************
 * Problem 6: Selection Sort
 *****************************************************************************/

/**
 * Runs the `selectionSort` algorithm to sort a list in DESCENDING order.
 *
 * @param list: The `elemType` array-based list to be sorted.
 * @param length: The length of the array.
 */
template <class elemType> void selectionSort(elemType list[], int length)
{
    int maxIndex;

    for (int loc = 0; loc < length; loc++)
    {
        maxIndex = maxLocation(list, loc, length - 1);
        swapIndices(list, loc, maxIndex);
    }
} // end selectionSort

/**
 * A helper function for `selectionSort` which swaps two elements in a list.
 *
 * @param list: The `elemType` array containing the elements to be swapped.
 * @param first: The index of the first element to be swapped.
 * @param second: The index of the second element to be swapped.
 */
template <class elemType>
void swapIndices(elemType list[], int first, int second)
{
    elemType temp;

    temp = list[first];
    list[first] = list[second];
    list[second] = temp;
} // end swapIndices

/**
 * A helper function for `selectionSort` which returns the index of the largest
 * element in a list.
 *
 * @param list: The `elemType` array of which we want to find the maximum.
 * @param first: The index of the starting location in the list.
 * @param last: The index of the ending location in the list.
 */
template <class elemType> int maxLocation(elemType list[], int first, int last)
{
    int maxIndex;

    maxIndex = first;

    for (int loc = first + 1; loc <= last; loc++)
        if (list[loc] > list[maxIndex]) { maxIndex = loc; }

    return maxIndex;
} // end maxLocation

/*****************************************************************************
 * Problem 7: Merge Sort
 *****************************************************************************/

/**
 * Runs the `mergeSort` algorithm to sort a list in ascending order.
 *
 * @param list: The `elemType` array-based list to be sorted.
 * @param length: The length of the array.
 */
template <class elemType> void mergeSort(elemType list[], int length)
{
    recMergeSort(list, 0, length - 1);
} // main mergeSort function

/**
 * A recursive implementation of the `mergeSort` algorithm.
 *
 * @param list: The `elemType` array to be sorted.
 * @param first: The index of the starting location in the list.
 * @param last: The index of the ending location in the list.
 */
template <class elemType>
void recMergeSort(elemType list[], int first, int last)
{
    elemType *tempList;
    int m;
    int i;

    // temporary list will hold the merged sublists
    tempList = new elemType[last + 1];

    if (first < last)
    {
        m = (first + last) / 2;

        recMergeSort(list, first, m);
        recMergeSort(list, m + 1, last);
        mergeLists(list, tempList, first, last, m);

        // tempList[s...t] should contain the merged lists, so copy them to list
        for (i = first; i <= last; i++)
        {
            // Copy tempList[first...last] into list[first...last]
            list[i] = tempList[i];
        }

        delete[] tempList;
    }
} // helper mergeSort for performing recursion

/**
 * A helper function to merge two lists.
 *
 * @param list: Union of two sorted sublists to be merged.
 * @param tempList: The location of the merged list.
 * @param first: The lower index of the first sublist in `list`.
 * @param last: The upper index of the second sublist in `list`.
 * @param m: The upper index of the first sublist in `list`.
 */
template <class elemType>
void mergeLists(
    elemType list[], elemType tempList[], int first, int last, int m
)
{
    int i = first;
    int j = m + 1;
    int k = first;

    while (i <= m && j <= last)
    {
        if (list[i] < list[j])
        {
            tempList[k] = list[i];
            i = i + 1;
        }
        else
        {
            tempList[k] = list[j];
            j = j + 1;
        }

        k = k + 1;
    }

    if (i <= m)
        while (i <= m)
        {
            tempList[k] = list[i];
            k = k + 1;
            i = i + 1;
        }
    else
        while (j <= last)
        {
            tempList[k] = list[j];
            k = k + 1;
            j = j + 1;
        }
} // performs merging of two sorted sublists
//(sublist1 is indexed from first to m, sublist2 is indexed from m + 1 to last)
