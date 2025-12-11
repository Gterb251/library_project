#include <iostream>
#include <cstring>

using namespace std;

class Book {
    
private:

    string title;
    string author;
    int year;
    string isbn;
    bool isAvailable;
    string borrowedBy;

public:

    Book(string c_title, string c_author, int c_year, string c_isbn);
    void borrowBook(const string& userName);
    void returnBook();
    void displayInfo();

};