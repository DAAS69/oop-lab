#include "Library.h"
#include <iostream>

Library::Library() {
    currentBookCount = 0;  
}

bool Library::addBook(const Book& book) {
    if (currentBookCount < 100) {
        books[currentBookCount] = new Book(book);  
        currentBookCount++;
        return true;
    }
    return false;
}

bool Library::removeBook(const string& isbn) {
    for (int i = 0; i < currentBookCount; i++) {
        if (books[i]->getISBN() == isbn) {
            delete books[i]; 
            for (int j = i; j < currentBookCount - 1; j++) {
                books[j] = books[j + 1];
            }
            currentBookCount--; 
            return true;
        }
    }
    return false; 
}


Book* Library::searchBook(const string& title) {
    for (int i = 0; i < currentBookCount; i++) {
        if (books[i]->getTitle() == title) {
            return books[i];  
        }
    }
    return nullptr;
}
