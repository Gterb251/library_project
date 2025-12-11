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

    Book(std::string c_title, std::string c_author, int c_year, std::string c_isbn);
    void borrowBook(const std::string& userName);
    void returnBook();
    void displayInfo();

};