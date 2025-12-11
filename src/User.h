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

    User(std::string c_name, std::string c_userId, int c_maxBooksAllowed);
    bool canBorrowMore();
    void addBook(const std::string& isbn);
    void removeBook(const std::string& isbn);
    void displayProfile();

};