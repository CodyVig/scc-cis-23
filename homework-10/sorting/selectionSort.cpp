#include "swapIndices.cpp"

using namespace std;

/**
 * Returns the index of the smallest element in `list` between indices
 * `first` and `last`.
 *
 * @param `list`: The array in question.
 * @param `first`: The lower index.
 * @param `last`: The upper index.
 */
template <class Type> void minLocation(const Type list[], int first, int last)
{
    int minIndex = first;

    for (int location = first + 1; location <= last; location++)
    {
        if (list[location] < list[minIndex]) { minIndex = location; }
    }

    return minIndex;
}

/**
 * Sorts a list from smallest to largest using the selection sort algorithm.
 *
 * @param `list`: The array to be sorted.
 * @param `length`: The length of the array.
 */
template <class Type> void selectionSort(const Type list[], int length)
{
    int minIndex = 0;

    for (int location = 0; location < length; location++)
    {
        minIndex = minLocation(list, location, length - 1);
        swapIndices(list, location, minIndex);
    }
}