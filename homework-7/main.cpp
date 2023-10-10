/*****************************************************************************
 * Author:       Cody Vig
 * Assignment:   Homework 7
 * Due Date:     October 19, 2023.
 *****************************************************************************/

#include "linkedListType.h"
#include <iostream>

using namespace std;

int main()
{
    int n, userInput;
    int idx = 0;
    linkedListType testList;

    cout << ">>> Enter the number of elements you want your list to contain: ";
    cin >> n;

    if (n <= 0 || n > 20) // Set 20 as an arbitrary maximum size
    {
        cout << "Not a valid cardinality. Using 5 numbers instead." << endl;
        n = 5;
    }

    // Fill list with arbitrary user input
    while (idx < n)
    {
        cout << "list[" << idx << "] = ";
        cin >> userInput;
        testList.insert(userInput);
        idx++;
        if (testList.getLength() != idx) { idx--; }
    }

    cout << "You entered the list ";
    testList.print();

    // Test node removal
    cout << ">>> "
            "Enter the index of the number you want to remove from the list: ";
    cin >> userInput;
    testList.deleteNodeAt(userInput);

    cout << "Your list is now ";
    testList.print();

    // Test node insertion
    cout << ">>> At which index would you like to add a number: ";
    cin >> idx;

    cout << ">>> What number would you like to add at index " << idx << ": ";
    cin >> userInput;

    testList.insertNodeAt(userInput, idx);

    cout << "Your list is now ";
    testList.print();

    // Test `sum` method
    cout << "The sum of this list is " << testList.sum() << "." << endl;

    return 0;
}