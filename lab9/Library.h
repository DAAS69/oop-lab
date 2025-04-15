#ifndef LIBRARY_H
#define LIBRARY_H
#include "Book.h"
#include <string>
using namespace std;

class Library {
private:
    Book* books[100];
    int currentBookCount;

public:
    Library();

    bool addBook(const Book& book);
    bool removeBook(const string& isbn);
    Book* searchBook(const string& title);
    int getTotalBooks() {return currentBookCount;}
};

#endif
