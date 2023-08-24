#include <string>
using namespace std;

class memberType
{
public:
    // Accessor member functions:

    /**
     * Writes `memberType.firstName` and `memberType.lastName` onto arugments.
     */
    void getName(string &, string &) const;

    /** Returns `memberType.memberID`. */
    int getMemberID() const;

    /** returns `memberType.amountSpent`. */
    double getAmountSpent() const;

    /** Returns `memberType.numberBooks`. */
    int getNumberOfBooks() const;

    // Mutator member functions:

    /** Sets `memberType.firstName` and `memberType.lastName`. */
    void setName(string, string);

    /** Sets `memberType.memberID`. */
    void setMemberID(int);

    /** sets `memberType.amountSpent`. */
    void setAmountSpent(double);

    /** sets `memberType.numberBooks`. */
    void setNumberOfBooks(int);

    /**
     * Prints all attributes of `memberType` to the console.
     */
    void printMemberInformation() const;

    /**
     * Process purchase of a book by `member`. Increases `member.amountSpent` by
     * the price of the book and increments `member.numberBooks`.
     *
     * @param amount: The price of the book.
     */
    void makePurchase(double);

    // Constructors:

    /**
     * Overloaded constructor;  sets all attributes to user-selected values.
     *
     * @param fn: The first name of the member.
     * @param ln: The last name of the member.
     * @param id: The user's member ID.
     * @param numBooks: The number of books the member owns.
     * @param amtSpent: The amount the member has spent on books.
     */
    memberType(string, string, int, int, double);
    memberType();

private:
    string firstName;
    string lastName;
    int memberID;
    int numberBooks;
    double amountSpent;
};