#include "linkedListType.h"
#include <iostream>

using namespace std;

void linkedListType::clearList()
{
    if (count == 0) { return; }

    nodeType *tmp;

    while (head != NULL)
    {
        tmp = head;
        head = head->link;
        delete tmp;
    }
    count = 0;
    head = NULL;
    tail = NULL;
}

void linkedListType::insert(int n)
{
    nodeType *newNode = new nodeType;
    newNode->info = n;
    newNode->link = NULL;

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        count++;
        return;
    }

    // First make sure `n` is not already in the list
    int idx = findData(n);
    if (idx != -1)
    {
        cout << "Error: Element " << n << " is already in the list at index "
             << idx << ". Duplicate elements are not allowed." << endl;
        return;
    }

    // Otherwise, insert the element.
    tail->link = newNode; // Make the old tail node point to the new node.
    tail = tail->link;    // Make this new node the tail node.
    // Could this also be tail = newNode?

    count++;
}

void linkedListType::insertNodeAt(int n, int idx)
{
    if (idx > count)
    {
        cout << "Cannot insert data at index " << idx
             << ". Inserting at the end of the list" << endl;
        insert(n);
        return;
    }

    nodeType *newNode = new nodeType;
    newNode->info = n;
    newNode->link = NULL;

    if (idx == 0)
    {
        newNode->link = head;
        head = newNode;
        count++;
        return;
    }

    nodeType *current = head;
    nodeType *previous = head;
    int position = 0;

    while (position < idx)
    {
        previous = current;
        current = current->link;
        position++;
    }

    previous->link = newNode;
    newNode->link = current;
    count++;
}

int linkedListType::findData(int n)
{
    if (count == 0) { return -1; }

    nodeType *current = head;
    int position = 0;

    while (position < count)
    {
        if (current->info == n) { return position; }
        current = current->link;
        position++;
    }
    return -1; // If we made it here, the element is not in the list.
}

void linkedListType::deleteNodeAt(int idx)
{
    if (idx >= count)
    {
        cout << "List is shorter than the index to delete." << endl;
        return;
    }

    nodeType *current = head;
    nodeType *previous = head;
    int position = 0;

    if (idx == 0)
    {
        head = head->link;
        delete previous;
        return;
    }

    while (position < idx)
    {
        previous = current;
        current = current->link;
        position++;
    }

    previous->link = current->link;
    delete current;
    count--;
}

void linkedListType::print() const
{
    nodeType *current = head;

    cout << "[ ";
    while (current != NULL)
    {
        cout << current->info << " ";
        current = current->link;
    }
    cout << "]" << endl;
}

int linkedListType::sum() const
{
    nodeType *current = head;
    int totalSum = 0;

    while (current != NULL)
    {
        totalSum += current->info;
        current = current->link;
    }

    return totalSum;
}

int linkedListType::getLength() const { return count; }

linkedListType::linkedListType()
{
    head = NULL;
    tail = NULL;
    count = 0;
}

linkedListType::~linkedListType() { clearList(); }
