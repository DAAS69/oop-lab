#include <iostream>
#include <exception>
#include <string>
using namespace std;

class FileException : public exception {
public:
    virtual const char* what() const noexcept override {
        return "FileException - General file error.";
    }
};

class FileNotFoundException : public FileException {
public:
    const char* what() const noexcept override {
        return "FileNotFoundException - File not found!";
    }
};

class PermissionDeniedException : public FileException {
public:
    const char* what() const noexcept override {
        return "PermissionDeniedException - Access denied!";
    }
};

void readFile(const string& filename) {
    if (filename == "missing.txt") {
        throw FileNotFoundException();
    } 
    
    
    else if (filename == "secret.txt") {
        throw PermissionDeniedException();
    } 
    
    else {
        cout << "Reading '" << filename << "': Success!" << endl;
    }
}

int main() {
    string filenames[] = {"data.txt", "missing.txt", "secret.txt"};

    for (int i = 0; i < 3; i++) {
        try {
            readFile(filenames[i]);
        } 
        
        catch (const FileNotFoundException& e) {
            cout << "Error: " << e.what() << endl;
        } 
        
        catch (const PermissionDeniedException& e) {
            cout << "Error: " << e.what() << endl;
        } 
        
        catch (const FileException& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    return 0;
}
