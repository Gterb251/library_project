#include "Book.h"

Book::Book(string c_title, string c_author, int c_year, string c_isbn)
{
    title = c_title;
    author = c_author;
    year = c_year;
    isbn = c_isbn;
    isAvailable = true;
}

void Book::borrowBook(const string& userName)
{
    borrowedBy = userName;
    isAvailable = false;
}

void Book::returnBook()
{
    borrowedBy = "";
    isAvailable = true;
}

void Book::displayInfo()
{
    cout << "BOOK\n";
    cout << "Title: " << title << "\n";
    cout << "Author: " << author << "\n";
    cout << "Year: " << year << "\n";
    cout << "ISBN: " << isbn << "\n";
    if (isAvailable) {
        cout << "Avaible: yes\n";
        cout << "BorrowedBy:\n";
    } else {
        cout << "Avaible: no\n";
        cout << "BorrowedBy: " << borrowedBy << "\n";
    }
}

int main()
{
    Book a("adsasd", "sdfs", 1324, "dsfkskdfjk");
    a.displayInfo();
    a.borrowBook("kafkj");
    a.displayInfo();
    a.returnBook();
    a.displayInfo();
    return 0;
}