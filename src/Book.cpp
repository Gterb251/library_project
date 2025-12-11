#include "Book.h"

//Конструктор класса
Book::Book(std::string c_title, std::string c_author, int c_year, std::string c_isbn)
{
    title = c_title;
    author = c_author;
    year = c_year;
    isbn = c_isbn;
    isAvailable = true;
}

//Getter-методы класса
std::string Book::getTitle() {return title;}
std::string Book::getAuthor() {return author;}
int Book::getYear() {return year;}
std::string Book::getISBN() {return isbn;}
bool Book::getIsAvailable() {return isAvailable;}
std::string Book::getBorrowedBy() {return borrowedBy;}

//Методы класса
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