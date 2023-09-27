/*****************************************************************************
 * Author:       Cody Vig
 * Assignment:   Homework 4
 * Due Date:     September 27, 2023.
 *****************************************************************************/

#include "orderedArrayListType.h"
#include <iostream>

using namespace std;

int main()
{
    orderedArrayListType intList(25);

    int element;

    cout << "Enter 8 integers: ";
    for (int count = 0; count < 8; count++)
    {
        cin >> element;
        intList.insert(element);
    }
    cout << endl;

    cout << "Ordered list = ";
    intList.print();
    cout << endl;

    // Delete from the array
    cout << "Enter the element to be deleted: ";
    cin >> element;
    intList.remove(element);

    cout << "After removal, ordered list = ";
    intList.print();
    cout << endl;

    // Search for an element;
    cout << "Enter the search item: ";
    cin >> element;
    if (intList.seqSearch(element) != -1)
    {
        cout << element << " found in list\n";
    }
    else { cout << element << " not found in list\n"; }

    return 0;
}