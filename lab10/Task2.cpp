#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string name;
    string email;
    int years_of_experience;
    string summary;
    
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your email: ";
    getline(cin, email);
    cout << "Enter your years of experience: ";
    cin >> years_of_experience;
    cin.ignore();
    cout << "Enter your summary: ";
    getline(cin, summary);
    
    ofstream write_file("resume.txt", ios::trunc);
    write_file << "Name: " << name << endl;
    write_file << "Email: " << email << endl;
    write_file << "Years of Experience: " << years_of_experience << endl;
    write_file << "Summary: " << summary << endl;
    write_file.close();
    
    ifstream read_file("resume.txt");
    string line;
    cout << endl << "Resume Contents:" << endl;
    while (getline(read_file, line)) {
        cout << line << endl;
    }
    read_file.close();
    
    return 0;
}
