#include "memberType.h"
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

void memberType::getName(string &fn, string &ln) const
{
    fn = firstName;
    ln = lastName;
}

int memberType::getMemberID() const { return memberID; }

double memberType::getAmountSpent() const { return amountSpent; }

int memberType::getNumberOfBooks() const { return numberBooks; }

void memberType::setName(string fn, string ln)
{
    firstName = fn;
    lastName = ln;
}

void memberType::setMemberID(int id) { memberID = id; }

void memberType::setAmountSpent(double amount) { amountSpent = amount; }

void memberType::setNumberOfBooks(int n) { numberBooks = n; }

void memberType::printMemberInformation() const
{
    cout << "Member name: " << lastName << ", " << firstName << endl;
    cout << "Member ID: " << memberID << endl;
    cout << "\tNumber of books purchased: " << numberBooks << endl;
    cout << setprecision(2) << fixed;
    cout << "\tAmount spent: $" << amountSpent << endl << endl;
}

void memberType::makePurchase(double amount)
{
    amountSpent += amount;
    numberBooks++;
}

memberType::memberType()
{
    firstName = "";
    lastName = "";
    memberID = -1;
    numberBooks = 0;
    amountSpent = 0.0;
}

memberType::memberType(
    string fn, string ln, int id, int numBooks, double amtSpent
)
{
    firstName = fn;
    lastName = ln;
    memberID = id;
    numberBooks = numBooks;
    amountSpent = amtSpent;
}
