#include <iostream>
#include "Book.h"
#include "Library.h"

using namespace std;

int main() {

    Book book1("charlie and the chocolate factory", "roald dhal", "123456789");


    cout << "Book Title: " << book1.getTitle() << endl;
    cout << "Book Author: " << book1.getAuthor() << endl;
    cout << "Book ISBN: " << book1.getISBN() << endl;


    Library myLibrary;


    if(myLibrary.getTotalBooks() < 100){
        myLibrary.addBook(book1);
        cout << "Book added to the library." << endl;
    }
    else 
        cout << "Library is full, unable to add book." << endl;




    Book* foundBook = myLibrary.searchBook("charlie and the chocolate factory");
    if (foundBook){
        cout << "Found Book: " << foundBook->getTitle() << endl;
    } 
    else{
        cout << "Book not found in the library." << endl;
    }


    if (myLibrary.removeBook("123456789")){
        cout << "Book removed from the library." << endl;
    } 
    
    else{
        cout << "Book not found for removal." << endl;
    }

    return 0;
}

// compile command is: g++ -Wall -Wextra -g3 task3.cpp Library.cpp Book.cpp -o task3.exe
