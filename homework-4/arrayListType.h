#ifndef ARRAYLISTTYPE_H_
#define ARRAYLISTTYPE_H_

class arrayListType
{
public:
    /** Whether or not the arrat is empty. */
    bool isEmpty() const;

    /** Whether or not the list is at capactiy. */
    bool isFull() const;

    /** Returns the current length of the array. */
    int listSize() const;

    /** Returns the maximum capacity of the array. */
    int maxListSize() const;

    /** Prints the contents of the array. */
    void print() const;

    /** Returns `list[location] == item`. */
    bool isItemAtEqual(int location, int item) const;

    /** Inserts `insertItem` into the array at index `location`. */
    virtual void insertAt(int location, int insertItem) = 0;

    /** Inserts `insertItem` at the end of the array. */
    virtual void insertEnd(int insertItem) = 0;

    /** Removes the item at index `location` from the array. */
    void removeAt(int location);

    /** Load the contents of the array at index `location` into `retItem`. */
    const void retrieveAt(int location, int &retItem);

    /** Replaces item at index `location` with `repItem`. */
    virtual void replaceAt(int location, int repItem) = 0;

    /** Deletes all data from the array. */
    void clearList();

    /**
     * Searches through the list for `searchItem` and returns the index of that
     * item, if it exists. Returns -1 if `searchItem` is not in the list.
     */
    virtual int seqSearch(int searchItem) const = 0;

    /** Removes `removeItem` from the list. */
    virtual void remove(int removeItem) = 0;

    int &operator[](int idx);
    arrayListType &operator=(arrayListType &otherList);

    arrayListType(int size = 100);
    arrayListType(const arrayListType &otherList);
    virtual ~arrayListType();

protected:
    int *list;
    int length;
    int maxSize;
};

#endif