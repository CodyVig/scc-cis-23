/*
Question 1: Explain briefly what the difference is between a struct and a
            class. When would you use one over the other?
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Answer:     Structs and classes are both abstractions used to group objects of
            similar characteristics. The most obvious difference is that the
            attributes of a struct are public by default and the attributes of
            a class are private by default. In practice, it is customary to use
            structs only for containing public data with which no member
            functions are intended to be written. Otherwise, classes are used.
*/

#include "bookType.h"
#include "memberType.h"
#include <iostream>
#include <string>

using namespace std;

void processPurchase(memberType &, bookType &);

int main()
{
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

    cout << "Before purchase...\n~~~~~~~~~~~~~~~~~~\n";
    bak.printBook();
    cody.printMemberInformation();

    processPurchase(cody, bak);

    cout << "After purchase...\n~~~~~~~~~~~~~~~~~\n";
    bak.printBook();
    cody.printMemberInformation();

    return 0;
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
    Answer:     We are passing these classes by reference instead of by value
                because our intention is to edit attributes of these classes.
                Also, we do not intend to access *all* of the memebers of each
                class in our method, so passing by value is memory inefficient.
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