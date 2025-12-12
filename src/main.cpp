#include "Library.h"

void addNewBook(Library& library)
{
    std::string title;
    std::string author;
    int year;
    std::string isbn;

    std::cout << "Enter title: ";
    std::cin >> title;

    std::cout << "Enter author: ";
    std::cin >> author;

    std::cout << "Enter year: ";
    std::cin >> year;
    //check

    std::cout << "Enter unique ISBN: ";
    std::cin >> isbn;
    //check

    Book book(title, author, year, isbn);

    library.addBook(book);
}

void addNewUser(Library& library)
{
    std::string name;
    std::string userId;
    int id;
    int maxBooksAllowed;

    std::cout << "Enter name: ";
    std::cin >> name;

    std::cout << "Enter max books allowed: ";
    std::cin >> maxBooksAllowed;
    //check

    id = library.getNumberUsers() + 1;
    if (id / 10 == 0) userId = "USR_00" + std::to_string(id);
    else if (id / 100 == 0) userId = "USR_0" + std::to_string(id);
    else userId = "USR_" + std::to_string(id);

    User user(name, userId, maxBooksAllowed);

    library.addUser(user);
}

void borrowBook(Library& library)
{
    std::string userName;
    std::string isbn;

    std::cout << "Enter name of user borrowing book: ";
    std::cin >> userName;
    //check

    std::cout << "Enter ISBN of borrowing book: ";
    std::cin >> isbn;
    //check!!!

    library.borrowBook(userName, isbn);
}

void returnBook(Library& library)
{
    std::string isbn;

    std::cout << "Enter the ISBN of borrowed book: ";
    std::cin >> isbn;
    //check!!!

    library.returnBook(isbn);
}

void searchByISBN(Library& library)
{
    std::string isbn;

    std::cout << "Enter the ISBN of borrowed book: ";
    std::cin >> isbn;
    
    Book* book = library.findBookByISBN(isbn);
    if (book == nullptr) std::cout << "Book was not found\n\n";
    else book->displayInfo();
}

void showUserProfile(Library& library)
{
    std::string name;

    std::cout << "Enter name of user: ";
    std::cin >> name;

    User* user = library.findUserByName(name);
    if (user == nullptr) std::cout << "User was not found\n\n";
    else user->displayProfile();
}

void showMenu()
{
    std::cout << "=== LIBRARY ===\n";
    std::cout << "1. Show all books\n";
    std::cout << "2. Show all users\n";
    std::cout << "3. Add new book\n";
    std::cout << "4. Add new user\n";
    std::cout << "5. Borrow book to user\n";
    std::cout << "6. Return book from user\n";
    std::cout << "7. Book search by ISBN\n";
    std::cout << "8. View user profile\n";
    std::cout << "9. Save data to file\n";
    std::cout << "10. Exit\n";
    std::cout << "Your choice: ";
}

int main()
{
    Library library; 

    int choice;

    do
    {
        showMenu();

        std::cin >> choice;
        //check

        switch(choice)
        {
        case 1:
            library.displayAllBooks();
            break;
        case 2:
            library.displayAllUsers();
            break;
        case 3:
            addNewBook(library);
            break;
        case 4:
            addNewUser(library);
            break;
        case 5:
            borrowBook(library);
            break;
        case 6:
            returnBook(library);
            break;
        case 7:
            searchByISBN(library);
            break;
        case 8:
            showUserProfile(library);
            break;
        case 9:
            library.saveToFile();
            break;
        case 10:
            std::cout << "Exit program\n\n";
            break;
        default:
            std::cout << "Wrong choice\n\n";
        }
    } while (choice != 10);
    
    return 0;
}