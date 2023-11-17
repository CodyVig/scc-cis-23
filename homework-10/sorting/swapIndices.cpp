using namespace std;

/**
 * Helper function to swap two elements in an array.
 *
 * @param `list`: The array in question.
 * @param `first`: One of the indices to be swapped.
 * @param `second`: The other index to be swapped.
 */
template <class Type> void swapIndices(const Type list[], int first, int second)
{
    Type temp = list[first];
    list[first] = list[second];
    list[second] = temp;
}