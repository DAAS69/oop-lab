#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream write_file("data.txt", ios::out);
    write_file << "AI is the future. AI will transform the world. Embrace AI now.";
    write_file.close();
    
    string search_word, replacement_word;
    cout << "Enter word to search: ";
    cin >> search_word;
    cout << "Enter replacement word: ";
    cin >> replacement_word;
    
    if (replacement_word.length() > search_word.length()) {
        cout << "Replacement word is longer than search word. Operation not allowed." << endl;
        return 0;
    }
    
    fstream file("data.txt", ios::in | ios::out);
    if (!file) {
        cout << "Error opening file." << endl;
        return 0;
    }
    
    char ch;
    string word;
    int pos;
    
    while (file.get(ch)) {
        if (isalpha(ch)) {
            word += ch;
        } else {
            if (word == search_word) {
                pos = file.tellg();
                pos = pos - word.length() - 1;
                
                file.seekp(pos);
                file.write(replacement_word.c_str(), replacement_word.length());
                
                for (int i = 0; i < search_word.length() - replacement_word.length(); i++) {
                    file.put(' ');
                }
                
                file.seekg(pos + search_word.length() + 1);
            }
            word.clear();
        }
    }
    
    file.close();
    
    ifstream read_file("data.txt");
    string updated_line;
    while (getline(read_file, updated_line)) {
        cout << updated_line << endl;
    }
    read_file.close();
    
    return 0;
}
