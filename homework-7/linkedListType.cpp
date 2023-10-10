#include "linkedListType.h"
#include <iostream>

using namespace std;

void linkedListType::clearList()
{
    if (count == 0) { return; }

    nodeType *current = head;
    nodeType *previous = head;
    int position = 0;

    while (position < count)
    {
        previous = current;
        delete previous;
        current = current->link;
        position++;
    }
    delete current;
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
    }
    else
    {
        tail->link = newNode; // Make the old tail node point to the new node.
        tail = tail->link;    // Make this new node the tail node.
        // Could this also be tail = newNode?
    }
    count++;
}

void linkedListType::insertNodeAt(int n, int idx)
{
    nodeType *newNode = new nodeType;
    newNode->info = n;
    newNode->link = NULL;

    if (idx == 0)
    {
        head = newNode;
        tail = newNode;
        count++;
        return;
    }

    nodeType *current = head;
    nodeType *previous = head;
    int position = 0;

    while (position <= idx)
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
    int position = 0;

    cout << "[ ";
    while (position < count)
    {
        cout << current->info << " ";
        current = current->link;
        position++;
    }
    cout << "]" << endl;
}

linkedListType::linkedListType()
{
    head = NULL;
    tail = NULL;
    count = 0;
}

linkedListType::~linkedListType()
{
    clearList();
    delete head;
    delete tail;
}