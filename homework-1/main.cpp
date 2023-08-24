/*
Question 1: Explain briefly what the difference is between a struct and a
            class. When would you use one over the other?
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Answer:     Structs and classes are both abstractions used to group objects of
            similar characteristics. The most obvious difference is that the
            attributes of a struct are public by default and the attributes of
            a class are private by default. In practice, it is customary to use
            structs only for containing public data and if no member functions
            are inteded to be written. Otherwise, classes are used.
*/

#include <cmath>
#include <iostream>

// For problem 2:
#include "structExercise.cpp"

// For problem 4:
#include "bookType.h"
#include "memberType.h"

using namespace std;

double computeDistance(const coordinate &, const coordinate &);
void processPurchase(memberType &, bookType &);

int main()
{
    // The following is code for problem 2 of the homework.
    cout << "For problem 2..." << endl;
    cout << "~~~~~~~~~~~~~~~~" << endl;

    coordinate p1;
    coordinate p2;
    double dist;

    cout << "Enter x and y coordinates: ";
    cin >> p1.x >> p1.y;
    cout << "Enter a second x and y coordinate: ";
    cin >> p2.x >> p2.y;

    dist = computeDistance(p1, p2);

    cout << "The distance between "
         << "(" << p1.x << ", " << p1.y << ") and (" << p2.x << ", " << p2.y
         << ") is " << dist << "." << endl;

    // The following is code for problems 3 and 4 of the homework.
    cout << "\nFor problems 3 and 4..." << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    // Create two bookType instantiations
    bookType millman = bookType(
        "Elements of Differential Geometry", // Title
        "Richard Millman",                   // Author
        "0-13-264143-7",                     // ISBN
        38.84,                               // Price (From Amazon)
        10,                                  // Stock
        0,                                   // Sold
        265                                  // Pages
    );
    bookType bak = bookType(
        "Complex Analysis", // Title
        "Joseph Bak",       // Author
        "0-387-90615-0",    // ISBN
        45.93,              // Price (From Amazon)
        25,                 // Stock
        0,                  // Sold
        244                 // Pages
    );

    // Create two memberType instantiations
    memberType cody = memberType("Cody", "Vig", 101909650, 0, 0);
    memberType gauss = memberType();

    cout << "Before purchase...\n==================\n";
    bak.printBook();
    cody.printMemberInformation();

    processPurchase(cody, bak);

    cout << "After purchase...\n=================\n";
    bak.printBook();
    cody.printMemberInformation();

    return 0;
}

/**
 * Returns the Euclidean distance between coordinates `p1` and `p2`.
 *
 * @param p1: The first coordinate.
 * @param p2: The second coordinate.
 * @return A double representing the Euclidean distance |p2 - p1|.
 */
double computeDistance(const coordinate &p1, const coordinate &p2)
{
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

/**
 * Process the purchase of `book` by `member`. Calls `member.makePurchase()`
 * and updates relevant `book` attributes.
 *
 * @param member: The `memberType` instance who is purchasing the book.
 * @param book: The `bookType` instance representing the book being purchased.
 */
void processPurchase(memberType &member, bookType &book)
{
    /*
    Question 4: Why use references as input to this function?
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    Answer:     We use references because we do not need all of the attributes
                from each class instance to be passed as parameters. Passing
                by reference is more memory efficient.
    */

    int copiesSold = book.getSoldQuantity();
    int copiesStock = book.getStockQuantity();
    double bookCost = book.getPrice();
    string fn, ln;
    member.getName(fn, ln);

    // Process customer purchase
    member.makePurchase(bookCost);

    // Process book inventory
    book.setSoldQuantity(++copiesSold);
    book.setStockQuantity(--copiesStock);

    // Confirmation message
    cout << "Thank you for your purchase, " << fn << "!\n\n";
}