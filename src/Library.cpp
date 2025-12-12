#include "Library.h"

//Конструктор класса
Library::Library()
{
    dataFile = "C:\\Nikita_Files\\Programs\\Git\\library_project\\data\\library_data.txt";

    loadFromFile();
}

//Getter-метод класса
int Library::getNumberUsers() {return users.size();}

//Методы класса
void Library::addBook(const Book& book)
{
    books.push_back(book);
}

void Library::addUser(const User& user)
{
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
    std::ofstream fout(dataFile);

    //check

    for (int i = 0; i < books.size(); ++i) {
        fout << "BOOK\n";
        fout << "Title: " << (books.data() + i)->getTitle() << "\n";
        fout << "Author: " << (books.data() + i)->getAuthor() << "\n";
        fout << "Year: " << (books.data() + i)->getYear() << "\n";
        fout << "ISBN: " << (books.data() + i)->getISBN() << "\n";
        if ((books.data() + i)->getIsAvailable()) fout << "Available: yes\n";
        else fout << "Available: no\n";
        fout << "BorrowedBy: " << (books.data() + i)->getBorrowedBy() << "\n\n";
    }

    fout << "---USERS---\n\n";

    for (int i = 0; i < users.size(); ++i) {
        fout << "USER\n";
        fout << "Name: " << (users.data() + i)->getName() << "\n";
        fout << "UserID: " << (users.data() + i)->getUserId() << "\n";
        fout << "BorrowedBooks:";
        for (int j = 0; j < (users.data() + i)->getNumberBorrowedBooks(); ++j) fout << " " << (users.data() + i)->getBorrowedBook(j);
        fout << "\n";
        fout << "MaxBooks: " << (users.data() + i)->getMaxBooksAllowed() << "\n\n";
    }

    fout << "---";
}

void Library::loadFromFile()
{
    std::ifstream fin(dataFile);

    //Check

    std::string title;
    std::string author;
    int year;
    std::string isbn;
    bool isAvailable;
    std::string borrowedBy = "";
    std::string buf;
    Book book;

    std::getline(fin, buf);
    if (buf == "") return;
    for (; buf != "---USERS---"; std::getline(fin, buf)) {
        std::getline(fin, buf);
        buf.erase(0, 7);
        title = buf;
        
        std::getline(fin, buf);
        buf.erase(0, 8);
        author = buf;
        
        std::getline(fin, buf);
        buf.erase(0, 6);
        year = atoi(buf.c_str());
        
        std::getline(fin, buf);
        buf.erase(0, 6);
        isbn = buf;
        
        std::getline(fin, buf);
        buf.erase(0, 11);
        if (buf == "yes") {
            isAvailable = true;
            getline(fin, buf);
            borrowedBy = "";
        } else {
            isAvailable = false;
            std::getline(fin, buf);
            buf.erase(0, 12);
            borrowedBy = buf;
        }

        book.setBook(title, author, year, isbn, isAvailable, borrowedBy);

        books.push_back(book);

        getline(fin, buf);
    }

    std::string name;
    std::string userId;
    std::vector<std::string> borrowedBooks;
    int maxBooksAllowed;
    User user;

    std::getline(fin, buf);
    std::getline(fin, buf);
    for (; buf != "---"; std::getline(fin, buf)) {
        std::getline(fin, buf);
        buf.erase(0, 6);
        name = buf;
        
        std::getline(fin, buf);
        buf.erase(0, 8);
        userId = buf;
        
        std::getline(fin, buf);
        buf.erase(0, 14);
        for (int i = 0; buf != ""; ++i, buf.erase(0, 17)) borrowedBooks.push_back(buf.substr(1, 16));
        
        std::getline(fin, buf);
        buf.erase(0, 10);
        maxBooksAllowed = atoi(buf.c_str());

        user.setUser(name, userId, borrowedBooks, maxBooksAllowed);
        borrowedBooks.clear();

        users.push_back(user);
        
        getline(fin, buf);
    }

}