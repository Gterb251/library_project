#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class User {

private:
    
    std::string name;
    std::string userId;
    std::vector<std::string> borrowedBooks;
    int maxBooksAllowed;

public:

    User();
    User(std::string c_name, std::string c_userId, int c_maxBooksAllowed);
    std::string getName();
    std::string getUserId();
    int getNumberBorrowedBooks();
    std::string getBorrowedBook(int i);
    int getMaxBooksAllowed();
    void setUser(std::string s_name, std::string s_userId, std::vector<std::string>& s_borrowedBooks, int s_maxBooksAllowed);
    bool canBorrowMore();
    void addBook(const std::string& isbn);
    void removeBook(const std::string& isbn);
    void displayProfile();

};