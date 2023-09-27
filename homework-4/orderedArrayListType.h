#ifndef ORDEREDARRAYLISTTYPE_H_
#define ORDEREDARRAYLISTTYPE_H_

#include "arrayListType.h"
#include <iostream>

class orderedArrayListType : public arrayListType
{
public:
    /**
     * Inserts `insertItem` at index `location`.
     * Treated as a private method. Calling this method will not preserve
     * ordering.
     */
    void insertAt(int location, int insertItem);

    /**
     * Insers item at the end of the list.
     * Treated as a private method. Calling this method will not preserve
     * ordering.
     */
    void insertEnd(int insertItem);

    /**
     * Replaces all instances of `list[location]` with `repItem`.
     */
    void replaceAt(int location, int repItem);

    /**
     * Searches through the list for `searchItem`.
     *
     * @returns The index of the item, if it exists. Defaults to -1.
     */
    int seqSearch(int searchItem) const;

    /**
     * Inserts `insertItem` in the correct location of the list.
     */
    void insert(int insertItem);

    /**
     * Removes all ocrruences of `removeItem` from the list.
     */
    void remove(int removeItem);

    orderedArrayListType(int size = 100);
};

#endif