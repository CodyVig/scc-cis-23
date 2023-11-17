#include "swapIndices.cpp"

using namespace std;

/**
 * Sorts a list from smallest to largest using the insertion sort algorithm.
 *
 * @param `list`: The array to be sorted.
 * @param `length`: The length of the array.
 */
template <class Type> void insertionSort(const Type list[], int length)
{
    for (int firstOutOfOrder = 1; firstOutOfOrder < length; firstOutOfOrder++)
    {
        if (list[firstOutOfOrder] < list[firstOutOfOrder - 1])
        {
            Type temp = list[firstOutOfOrder];
            int location = firstOutOfOrder;

            do
            {
                list[location] = list[location - 1];
                location--;
            } while (location > 0 && list[location - 1] > temp);

            list[location] = temp;
        }
    }
}