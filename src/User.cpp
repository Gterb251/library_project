#include "User.h"

//Конструктор класса
User::User(std::string c_name, std::string c_userId, int c_maxBooksAllowed = 3)
{
    name = c_name;
    userId = c_userId;
    maxBooksAllowed = c_maxBooksAllowed;
}

//Getter-методы класса
std::string User::getName() {return name;}
std::string User::getUserId() {return userId;}

//Методы класса
bool User::canBorrowMore()
{
    if (borrowedBooks.size() < maxBooksAllowed) return true;
    else return false;
}

void User::addBook(const std::string& isbn)
{
    if (canBorrowMore()) borrowedBooks.push_back(isbn);
    else std::cout << "Too many books have been borrowed user " << name << "\n";
}

void User::removeBook(const std::string& isbn)
{
    std::vector<std::string>::iterator it = std::find(borrowedBooks.begin(), borrowedBooks.end(), isbn);
    if (it != borrowedBooks.end()) borrowedBooks.erase(it);
    else std::cout << "Book " << isbn << " was not borrowed to the user " << name << "\n";
}

void User::displayProfile()
{
    std::cout << "USER\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "UserID: " << userId << "\n";
    std::cout << "BorrowedBooks:";
    for (int i = 0; i < borrowedBooks.size(); ++i) std::cout << " " << borrowedBooks[i];
    std::cout << "\n";
    std::cout << "MaxBooks: " << maxBooksAllowed << "\n\n";
}