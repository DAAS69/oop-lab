#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream chapter1_file("chapter1.txt");
    ifstream chapter2_file("chapter2.txt");
    ofstream book_file("book.txt", ios::app);
    
    string line;
    if (chapter1_file.is_open()) {
        while (getline(chapter1_file, line)) {
            book_file << line << endl;
        }
        book_file << endl;
        chapter1_file.close();
    }
    
    if (chapter2_file.is_open()) {
        while (getline(chapter2_file, line)) {
            book_file << line << endl;
        }
        book_file << endl;
        chapter2_file.close();
    }
    
    book_file.close();
    
    ifstream read_book("book.txt");
    cout << "Book Contents:" << endl;
    while (getline(read_book, line)) {
        cout << line << endl;
    }
    read_book.close();
    
    return 0;
}
