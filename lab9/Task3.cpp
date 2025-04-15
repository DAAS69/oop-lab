#include <iostream>
#include "Book.h"

using namespace std;

int main() {
    Book book1("charlie and the chocolate factory", "roald dhal", "123456789");

    cout << "Title: " << book1.getTitle() << endl;
    cout << "Author: " << book1.getAuthor() << endl;
    cout << "ISBN: " << book1.getISBN() << endl;

    return 0;
}

// compile command is: g++ -Wall -Wextra -g3 task3.cpp Book.cpp -o task3.exe
