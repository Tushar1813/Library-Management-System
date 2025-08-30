#ifndef BOOK_H
#define BOOK_H

#include <string>

struct BookNode {
    int bookID;
    std::string title;
    std::string author;
    bool isAvailable;
    BookNode* next;

    BookNode(int id, std::string t, std::string a) : bookID(id), title(t), author(a), isAvailable(true), next(nullptr) {}
};

#endif // BOOK_H
