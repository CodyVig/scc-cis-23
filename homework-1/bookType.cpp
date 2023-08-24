#include "bookType.h"
#include <iostream>
#include <string>

using namespace std;

void bookType::setTitle(string bookTitle) { title = bookTitle; }

void bookType::setAuthor(string bookAuthor) { author = bookAuthor; }

void bookType::setISBN(string bookISBN) { isbn = bookISBN; }

void bookType::setPrice(double bookPrice) { price = bookPrice; }

void bookType::setStockQuantity(int bookStock) { stockQuantity = bookStock; }

void bookType::setSoldQuantity(int bookSold) { soldQuantity = bookSold; }

void bookType::setPages(int bookPages) { pages = bookPages; }

string bookType::getTitle() const { return title; }

string bookType::getAuthor() const { return author; }

string bookType::getISBN() const { return isbn; }

double bookType::getPrice() const { return price; }

int bookType::getStockQuantity() const { return stockQuantity; }

int bookType::getSoldQuantity() const { return soldQuantity; }

int bookType::getPages() const { return pages; }

void bookType::printBook() const
{
    cout << "Title:  " << title << endl;
    cout << "Author: " << author << endl;
    cout << "ISBN:   " << isbn << endl;
    cout << "\tPrice: $" << price << endl;
    cout << "\tNumber sold:     " << soldQuantity << endl;
    cout << "\tNumber in stock: " << stockQuantity << endl << endl;
}

bookType::bookType()
{
    title = "";
    author = "";
    isbn = "";
    price = 0.0;
    stockQuantity = 0;
    soldQuantity = 0;
    pages = 0;
}

bookType::bookType(
    string bookTitle, string bookAuthor, string bookISBN, double bookPrice,
    int bookStock, int bookSold, int bookPages
)
{
    title = bookTitle;
    author = bookAuthor;
    isbn = bookISBN;
    price = bookPrice;
    stockQuantity = bookStock;
    soldQuantity = bookSold;
    pages = bookPages;
}
