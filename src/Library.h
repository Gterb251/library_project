#include "Book.h"
#include "User.h"
#include <fstream>

class Library {

private:

    std::vector<Book> books;
    std::vector<User> users;
    std::string dataFile;

public:

    Library();
    int getNumberUsers();
    void addBook(const Book& book);
    void addUser(const User& user);
    void borrowBook(const std::string& userName, const std::string& isbn);
    void returnBook(const std::string& isbn);
    Book* findBookByISBN(const std::string& isbn);
    User* findUserByName(const std::string& name);
    void displayAllBooks();
    void displayAllUsers();
    void saveToFile();
    void loadFromFile();

};