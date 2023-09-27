#include "unorderedArrayListType.h"
#include <iostream>

// g++ testunorderedArrayListType.cpp unorderedArrayListType.cpp
// arrayListType.cpp

using namespace std;

int main()
{
    unorderedArrayListType intList(25);

    int number;

    // Populate the array
    cout << "Enter 8 integers: ";
    for (int count = 0; count < 8; count++)
    {
        cin >> number;
        intList.insertEnd(number);
    }

    cout << endl;

    cout << "intList = ";
    intList.print();
    cout << endl;

    // Delete from the array
    cout << "Enter the element to be deleted: ";
    cin >> number;
    intList.remove(number);

    cout << "After removal, intList = ";
    intList.print();
    cout << endl;

    // Search for an element;
    cout << "Enter the search item: ";
    cin >> number;
    if (intList.seqSearch(number) != -1)
    {
        cout << number << " found in list\n";
    }
    else { cout << number << " not found in list\n"; }

    return 0;
}