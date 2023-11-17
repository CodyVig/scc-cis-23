#include "swapIndices.cpp"

using namespace std;

/**
 * Sorts a list from smallest to largest using the bubble sort algorithm.
 *
 * @param `list`: The array to be sorted.
 * @param `length`: The length of the array.
 */
template <class Type> void bubbleSort(const Type list[], int length)
{

    for (int iteration = 1; iteration < length; iteration++)
    {
        for (int idx = 0; idx < length - iteration; idx++)
        {
            if (list[idx] > list[idx + 1]) { swapIndices(list, idx, idx + 1) }
        }
    }
}