#ifndef USER_H
#define USER_H

#include <string>
#include "Book.h" // For BookNode in borrowedBooks

struct UserNode {
    int userID;
    std::string name;
    BookNode* borrowedBooks; // Linked list of borrowed books
    UserNode* next;

    UserNode(int id, std::string n) : userID(id), name(n), borrowedBooks(nullptr), next(nullptr) {}
};

#endif // USER_H
