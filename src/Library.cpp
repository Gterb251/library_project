#include "Library.h"

Library::Library()
{

}

void Library::addBook(const Book& book)
{
    std::string title;
    std::string author;
    int year;
    std::string isbn;
    
    std::cout << "Enter title of book: ";
    std::cin >> title;

    std::cout << "Enter author: ";
    std::cin >> author;

    std::cout << "Enter year of book's publication: ";
    std::cin >> year;

    std::cout << "Enter unique ISBN: ";
    std::cin >> isbn;

    Book book(title, author, year, isbn);

    books.push_back(book);
}

void Library::addUser(const User& user)
{
    std::string name;
    std::string userId;
    int id;
    int maxBooksAllowed;
    
    std::cout << "Enter name of user: ";
    std::cin >> name;

    id = users.size() + 1;
    if (id / 10 == 0) userId = "USR_00" + std::to_string(id);
    else if (id / 100 == 0) userId = "USR_0" + std::to_string(id);
    else userId = "USR_" + std::to_string(id);
    
    std::cout << "Enter max number books that can be allowed: ";
    std::cin >> maxBooksAllowed;

    User user(name, userId, maxBooksAllowed);

    users.push_back(user);
}

void Library::borrowBook(const std::string& userName, const std::string& isbn)
{
    findUserByName(userName)->addBook(isbn);
    findBookByISBN(isbn)->borrowBook(userName);
}

void Library::returnBook(const std::string& isbn)
{
    Book* book = findBookByISBN(isbn);
    findUserByName(book->getBorrowedBy())->removeBook(isbn);
    book->returnBook();
}

Book* Library::findBookByISBN(const std::string& isbn)
{
    Book* book = books.data();
    for (int i = 0; i < books.size(); ++i) {
        if ((book + i)->getISBN() == isbn) return book + i;
    }
    return nullptr;
}

User* Library::findUserByName(const std::string& name)
{
    User* user = users.data();
    for (int i = 0; i < users.size(); ++i) {
        if ((user + i)->getName() == name) return user + i;
    }
    return nullptr;
}

void Library::displayAllBooks()
{
    Book* book = books.data();
    for (int i = 0; i < books.size(); ++i) (book + i)->displayInfo();
}

void Library::displayAllUsers()
{
    User* user = users.data();
    for (int i = 0; i < users.size(); ++i) (user + i)->displayProfile();
}

void Library::saveToFile()
{

}

void Library::loadFromFile()
{

}