#include <iostream>
#include "Library.h"

int main() {
    Library lib;

    // Menu-driven interface
    int choice;
    do {
        std::cout << "\nLibrary Management System Menu:\n";
        std::cout << "1. Add Book\n";
        std::cout << "2. Remove Book\n";
        std::cout << "3. Search Books\n";
        std::cout << "4. Add User\n";
        std::cout << "5. Issue Book\n";
        std::cout << "6. Return Book\n";
        std::cout << "7. Display All Books\n";
        std::cout << "8. Display All Users\n";
        std::cout << "9. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Clear newline

        if (choice == 1) {
            std::string title, author;
            std::cout << "Enter title: ";
            std::getline(std::cin, title);
            std::cout << "Enter author: ";
            std::getline(std::cin, author);
            lib.addBook(title, author);
        } else if (choice == 2) {
            int bookID;
            std::cout << "Enter book ID to remove: ";
            std::cin >> bookID;
            lib.removeBook(bookID);
        } else if (choice == 3) {
            std::string title;
            std::cout << "Enter title to search: ";
            std::getline(std::cin, title);
            lib.searchBooks(title);
        } else if (choice == 4) {
            std::string name;
            std::cout << "Enter user name: ";
            std::getline(std::cin, name);
            lib.addUser(name);
        } else if (choice == 5) {
            int userID, bookID;
            std::cout << "Enter user ID: ";
            std::cin >> userID;
            std::cout << "Enter book ID: ";
            std::cin >> bookID;
            lib.issueBook(userID, bookID);
        } else if (choice == 6) {
            int userID, bookID;
            std::cout << "Enter user ID: ";
            std::cin >> userID;
            std::cout << "Enter book ID: ";
            std::cin >> bookID;
            lib.returnBook(userID, bookID);
        } else if (choice == 7) {
            lib.displayBooks();
        } else if (choice == 8) {
            lib.displayUsers();
        } else if (choice == 9) {
            std::cout << "Exiting..." << std::endl;
        } else {
            std::cout << "Invalid choice!" << std::endl;
        }
    } while (choice != 9);

    return 0;
}
