# Library Management System (C++ DSA)

A console-based Library Management System implemented in C++ using fundamental Data Structures and Algorithms (DSA).

## Features
- Add, remove, search, and display books
- Add, remove, search, and display users
- Issue and return books
- Track which user has borrowed which book
- Uses DSA concepts: linked lists, searching, sorting, etc.

## File Structure
- `main.cpp` - Entry point and menu
- `Book.h`/`Book.cpp` - Book class and logic
- `User.h`/`User.cpp` - User class and logic
- `Library.h`/`Library.cpp` - Library management (using DSA)
- `utils.h`/`utils.cpp` - Helper functions

## Build Instructions
Compile all `.cpp` files together:

```
g++ main.cpp Book.cpp User.cpp Library.cpp utils.cpp -o library_system
```

Run the program:
```
./library_system
```
