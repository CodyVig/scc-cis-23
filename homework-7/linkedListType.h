#ifndef _linkedListType_H_
#define _linkedListType_H_

#include <iostream>

using namespace std;

struct nodeType
{
    int info;       // Data contained in the node
    nodeType *link; // Pointer to next node
};

class linkedListType
{
private:
    nodeType *head;
    nodeType *tail;
    int count;

public:
    /** Delete all of the nodes from the linked list. */
    void clearList();

    /**
     * Inserts a node with info `n` at the end of the linked list, if `n` is
     * not already in the list.
     */
    void insert(int n);

    /** Inserts a node with info `n` at index `idx` in the linked list. */
    void insertNodeAt(int n, int idx);

    /**
     * Returns the first index of `n` in the linked list.
     * Defaults to -1 if `n` is not in list.
     */
    int findData(int n);

    /** Removes the node at index `idx` from the linked list. */
    void deleteNodeAt(int idx);

    /** Prints the linked list as an array. */
    void print() const;

    /** Returns the sum of the values in the linked list.  */
    int sum() const;

    /** Returns the length of the linked list. */
    int getLength() const;

    linkedListType();
    ~linkedListType();
};

#endif