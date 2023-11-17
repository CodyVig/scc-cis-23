#include "swapIndices.cpp"

using namespace std;

/**
 * Partitions a subset of an array (between indices `first` and `last`) about
 * the element at index (`first` + `last`) / 2.
 *
 * @param `list`: The array to be sorted.
 * @param `length`: The length of the array.
 */
template <class Type> int partition(const Type list[], int first, int last)
{
    Type pivot;
    int smallIndex;

    swapIndices(list, first, (first + last) / 2);

    pivot = list[first];
    smallIndex = first;

    for (int index = first + 1; index <= last; index++)
    {
        if (list[index] < pivot)
        {
            smallIndex++;
            swapIndices(list, smallIndex, index);
        }
    }

    swapIndices(list, first, smallIndex);
    return smallIndex;
}

/**
 * Recursive application of the quick sort algorithm. Helper function for
 * `quickSort(cont Type list[], int length)`.
 *
 * @param `list`: The array to be sorted.
 * @param `first`: The lower index of the subarray to be partitioned.
 * @param `last`: The upper index of the subarray to be partitioned.
 */
template <class Type> void recQuickSort(const Type list[], int first, int last)
{
    int pivotLocation;

    if (first < last)
    {
        pivotLocation = partition(list, first, last);
        recQuickSort(list, first, pivotLocation - 1);
        recQuickSort(list, pivotLocation + 1, last);
    }
}

/**
 * Sorts a list from smallest to largest using the quick sort algorithm.
 *
 * @param `list`: The array to be sorted.
 * @param `length`: The length of the array.
 */
template <class Type> void quickSort(const Type list[], int length)
{
    quickSort(list, 0, length - 1);
}