#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <string>
#include "Book.h"
#include "User.h"

class Library {
private:
    BookNode* bookHead; // Head of book linked list
    UserNode* userHead; // Head of user linked list
    int nextBookID;
    int nextUserID;

    // Helper to find book by ID
    BookNode* findBook(int id);

    // Helper to find user by ID
    UserNode* findUser(int id);

    // Helper to add a borrowed book to user's list
    void addBorrowedBook(UserNode* user, BookNode* book);

    // Helper to remove a borrowed book from user's list
    bool removeBorrowedBook(UserNode* user, int bookID);

public:
    Library();
    ~Library();

    // Add a new book to the library (append to linked list)
    void addBook(const std::string& title, const std::string& author);

    // Remove a book by ID
    void removeBook(int bookID);

    // Search books by title (linear search on linked list)
    void searchBooks(const std::string& title);

    // Add a new user
    void addUser(const std::string& name);

    // Issue a book to a user
    void issueBook(int userID, int bookID);

    // Return a book from a user
    void returnBook(int userID, int bookID);

    // Display all books
    void displayBooks();

    // Display all users and their borrowed books
    void displayUsers();
};

#endif // LIBRARY_H
