#ifndef UNORDEREDARRAYLISTTYPE_H_
#define UNORDEREDARRAYLISTTYPE_H_

#include "arrayListType.h"

class unorderedArrayListType : public arrayListType
{
public:
    /**
     * Inserts `insertItem` at location with index `location.`
     */
    void insertAt(int location, int insertItem);

    /**
     * Inserts `insertItem` the end of the list.
     */
    void insertEnd(int insertItem);

    /**
     * Replaces item at index `location` with `repItem`.
     */
    void replaceAt(int location, int repItem);

    /**
     * Searches through the list for `searchItem` and returns the index of that
     * item, if it exists. Returns -1 if `searchItem` is not in the list.
     */
    int seqSearch(int searchItem) const;

    /**
     * Removes `removeItem` from the list.
     */
    void remove(int removeItem);

    unorderedArrayListType(int size = 100);
};

#endif