#include "Library.h"
#include <iostream>

// Constructor
Library::Library() : bookHead(nullptr), userHead(nullptr), nextBookID(1), nextUserID(1) {}

// Destructor
Library::~Library() {
    // Clean up books
    BookNode* currentBook = bookHead;
    while (currentBook) {
        BookNode* temp = currentBook;
        currentBook = currentBook->next;
        delete temp;
    }
    // Clean up users and their borrowed books
    UserNode* currentUser = userHead;
    while (currentUser) {
        BookNode* currentBorrowed = currentUser->borrowedBooks;
        while (currentBorrowed) {
            BookNode* temp = currentBorrowed;
            currentBorrowed = currentBorrowed->next;
            delete temp;
        }
        UserNode* tempUser = currentUser;
        currentUser = currentUser->next;
        delete tempUser;
    }
}

// Helper to find book by ID
BookNode* Library::findBook(int id) {
    BookNode* current = bookHead;
    while (current) {
        if (current->bookID == id) return current;
        current = current->next;
    }
    return nullptr;
}

// Helper to find user by ID
UserNode* Library::findUser(int id) {
    UserNode* current = userHead;
    while (current) {
        if (current->userID == id) return current;
        current = current->next;
    }
    return nullptr;
}

// Helper to add a borrowed book to user's list
void Library::addBorrowedBook(UserNode* user, BookNode* book) {
    BookNode* newBorrowed = new BookNode(book->bookID, book->title, book->author);
    newBorrowed->next = user->borrowedBooks;
    user->borrowedBooks = newBorrowed;
}

// Helper to remove a borrowed book from user's list
bool Library::removeBorrowedBook(UserNode* user, int bookID) {
    BookNode* current = user->borrowedBooks;
    BookNode* prev = nullptr;
    while (current) {
        if (current->bookID == bookID) {
            if (prev) {
                prev->next = current->next;
            } else {
                user->borrowedBooks = current->next;
            }
            delete current;
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}

// Add a new book to the library (append to linked list)
void Library::addBook(const std::string& title, const std::string& author) {
    BookNode* newBook = new BookNode(nextBookID++, title, author);
    if (!bookHead) {
        bookHead = newBook;
    } else {
        BookNode* current = bookHead;
        while (current->next) {
            current = current->next;
        }
        current->next = newBook;
    }
    std::cout << "Book added: ID " << newBook->bookID << ", Title: " << title << ", Author: " << author << std::endl;
}

// Remove a book by ID
void Library::removeBook(int bookID) {
    BookNode* current = bookHead;
    BookNode* prev = nullptr;
    while (current) {
        if (current->bookID == bookID) {
            if (prev) {
                prev->next = current->next;
            } else {
                bookHead = current->next;
            }
            std::cout << "Book removed: ID " << bookID << std::endl;
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
    std::cout << "Book not found: ID " << bookID << std::endl;
}

// Search books by title (linear search on linked list)
void Library::searchBooks(const std::string& title) {
    BookNode* current = bookHead;
    bool found = false;
    while (current) {
        if (current->title.find(title) != std::string::npos) {
            std::cout << "Found: ID " << current->bookID << ", Title: " << current->title
                      << ", Author: " << current->author << ", Available: " << (current->isAvailable ? "Yes" : "No") << std::endl;
            found = true;
        }
        current = current->next;
    }
    if (!found) {
        std::cout << "No books found with title containing: " << title << std::endl;
    }
}

// Add a new user
void Library::addUser(const std::string& name) {
    UserNode* newUser = new UserNode(nextUserID++, name);
    if (!userHead) {
        userHead = newUser;
    } else {
        UserNode* current = userHead;
        while (current->next) {
            current = current->next;
        }
        current->next = newUser;
    }
    std::cout << "User added: ID " << newUser->userID << ", Name: " << name << std::endl;
}

// Issue a book to a user
void Library::issueBook(int userID, int bookID) {
    UserNode* user = findUser(userID);
    if (!user) {
        std::cout << "User not found: ID " << userID << std::endl;
        return;
    }
    BookNode* book = findBook(bookID);
    if (!book) {
        std::cout << "Book not found: ID " << bookID << std::endl;
        return;
    }
    if (!book->isAvailable) {
        std::cout << "Book is not available: ID " << bookID << std::endl;
        return;
    }
    book->isAvailable = false;
    addBorrowedBook(user, book);
    std::cout << "Book issued to user: Book ID " << bookID << ", User ID " << userID << std::endl;
}

// Return a book from a user
void Library::returnBook(int userID, int bookID) {
    UserNode* user = findUser(userID);
    if (!user) {
        std::cout << "User not found: ID " << userID << std::endl;
        return;
    }
    BookNode* book = findBook(bookID);
    if (!book) {
        std::cout << "Book not found: ID " << bookID << std::endl;
        return;
    }
    if (book->isAvailable) {
        std::cout << "Book is already available: ID " << bookID << std::endl;
        return;
    }
    if (removeBorrowedBook(user, bookID)) {
        book->isAvailable = true;
        std::cout << "Book returned by user: Book ID " << bookID << ", User ID " << userID << std::endl;
    } else {
        std::cout << "User does not have this book borrowed: Book ID " << bookID << std::endl;
    }
}

// Display all books
void Library::displayBooks() {
    BookNode* current = bookHead;
    if (!current) {
        std::cout << "No books in the library." << std::endl;
        return;
    }
    std::cout << "Library Books:" << std::endl;
    while (current) {
        std::cout << "ID: " << current->bookID << ", Title: " << current->title
                  << ", Author: " << current->author << ", Available: " << (current->isAvailable ? "Yes" : "No") << std::endl;
        current = current->next;
    }
}

// Display all users and their borrowed books
void Library::displayUsers() {
    UserNode* currentUser = userHead;
    if (!currentUser) {
        std::cout << "No users registered." << std::endl;
        return;
    }
    std::cout << "Registered Users:" << std::endl;
    while (currentUser) {
        std::cout << "ID: " << currentUser->userID << ", Name: " << currentUser->name << std::endl;
        std::cout << "  Borrowed Books:" << std::endl;
        BookNode* currentBorrowed = currentUser->borrowedBooks;
        if (!currentBorrowed) {
            std::cout << "    None" << std::endl;
        } else {
            while (currentBorrowed) {
                std::cout << "    ID: " << currentBorrowed->bookID << ", Title: " << currentBorrowed->title
                          << ", Author: " << currentBorrowed->author << std::endl;
                currentBorrowed = currentBorrowed->next;
            }
        }
        currentUser = currentUser->next;
    }
}
