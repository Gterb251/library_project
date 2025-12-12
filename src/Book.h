#include <iostream>
#include <cstring>

class Book {
    
private:

    std::string title;
    std::string author;
    int year;
    std::string isbn;
    bool isAvailable;
    std::string borrowedBy;

public:

    Book();
    Book(std::string c_title, std::string c_author, int c_year, std::string c_isbn);
    std::string getTitle();
    std::string getAuthor();
    int getYear();
    std::string getISBN();
    bool getIsAvailable();
    std::string getBorrowedBy();
    void setBook(std::string s_title, std::string s_author, int s_year, std::string s_isbn, bool s_isAvailable, std::string s_borrowedBy);
    void borrowBook(const std::string& userName);
    void returnBook();
    void displayInfo();

};