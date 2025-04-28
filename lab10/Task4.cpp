#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream outFile("info.txt", ios::out);
    if (!outFile) {
        cerr << "Error creating file!" << endl;
        return 1;
    }
    outFile << "C++ is a powerful programming language.";
    outFile.close();
    fstream file("info.txt", ios::in | ios::out);
    if (!file) {
        cerr << "Error opening file!" << endl;
        return 1;
    }
    cout << "Initial get pointer position: " << file.tellg() << endl;
    cout << "Initial put pointer position: " << file.tellp() << endl;

    file.seekg(9);
    string word;
    file >> word;
    cout << "Word at position 9: " << word << endl;

    file.seekp(9);
    file << "dynamic";

    cout << "New get pointer position: " << file.tellg() << endl;
    cout << "New put pointer position: " << file.tellp() << endl;

    file.seekg(0); 
    string content;
    getline(file, content);
    cout << "Updated file content: " << content << endl;

    file.close();
    return 0;
}
