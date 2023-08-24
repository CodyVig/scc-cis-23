#include <string>

using namespace std;

/**
 * Contains information about books, including title, author, isbn, etc.
 */
class bookType
{
public:
    /** Sets `bookType.title`. `*/
    void setTitle(string);

    /** Sets `bookType.author`. */
    void setAuthor(string);

    /** Sets `bookType.isbn`. */
    void setISBN(string);

    /** Sets `bookType.price`. */
    void setPrice(double);

    /** Sets `bookType.stockQuantity`. */
    void setStockQuantity(int);

    /** Sets `bookType.soldQuantity`. */
    void setSoldQuantity(int);

    /** Sets `bookType.pages'. */
    void setPages(int);

    /** Returns `bookType.title`. */
    string getTitle() const;

    /** Returns `bookType.author`. */
    string getAuthor() const;

    /** Returns `bookType.isbn`. */
    string getISBN() const;

    /** Returns `bookType.price`. */
    double getPrice() const;

    /** Returns `bookType.stockQuantity`. */
    int getStockQuantity() const;

    /** Returns `bookType.soldQuantity`. */
    int getSoldQuantity() const;

    /** Returns `bookType.pages`. */
    int getPages() const;

    /**
     * Prints relevant information about the book to the console.
     */
    void printBook() const;

    /**
     * Overloaded constructor; sets all attributes to user-selected values.
     *
     * @param bookTitle: The title of the book.
     * @param bookAuthor: The author of the book.
     * @param bookISBN: The ISBN number.
     * @param bookPrice: The selling price of the book.
     * @param bookStock: The in-stock quantity of the book.
     * @param bookSold: The number of theses books which have been sold.
     * @param bookPages: The number of pages in the book.
     */
    bookType(string, string, string, double, int, int, int);
    bookType();

private:
    string title;
    string author;
    string isbn;
    double price;
    int stockQuantity;
    int soldQuantity;
    int pages; // My suggestion
};
