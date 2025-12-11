#include "Book.h"

Book::Book(std::string c_title, std::string c_author, int c_year, std::string c_isbn)
{
    title = c_title;
    author = c_author;
    year = c_year;
    isbn = c_isbn;
    isAvailable = true;
}

void Book::borrowBook(const std::string& userName)
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
    std::cout << "BOOK\n";
    std::cout << "Title: " << title << "\n";
    std::cout << "Author: " << author << "\n";
    std::cout << "Year: " << year << "\n";
    std::cout << "ISBN: " << isbn << "\n";
    if (isAvailable) {
        std::cout << "Avaible: yes\n";
        std::cout << "BorrowedBy:\n\n";
    } else {
        std::cout << "Avaible: no\n";
        std::cout << "BorrowedBy: " << borrowedBy << "\n\n";
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