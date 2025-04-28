#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    string id;
    string name;
    float gpa;
};

int main() {
    Student students[5];
    ofstream write_file("students.txt", ios::out);
    
    for (int i = 0; i < 5; i++) {
        cout << "Enter id for student " << i + 1 << ": ";
        getline(cin, students[i].id);
        cout << "Enter name for student " << i + 1 << ": ";
        getline(cin, students[i].name);
        cout << "Enter gpa for student " << i + 1 << ": ";
        cin >> students[i].gpa;
        cin.ignore();
        write_file << students[i].id << "," << students[i].name << "," << students[i].gpa << endl;
    }
    write_file.close();
    
    ofstream append_file("students.txt", ios::app);
    Student new_student;
    cout << "Enter id for additional student: ";
    getline(cin, new_student.id);
    cout << "Enter name for additional student: ";
    getline(cin, new_student.name);
    cout << "Enter gpa for additional student: ";
    cin >> new_student.gpa;
    cin.ignore();
    append_file << new_student.id << "," << new_student.name << "," << new_student.gpa << endl;
    append_file.close();
    
    ifstream read_file("students.txt");
    Student temp_student;
    string line;
    cout << endl << "Student Records:" << endl;
    while (getline(read_file, line)) {
        int first_comma = line.find(',');
        int second_comma = line.find(',', first_comma + 1);
        temp_student.id = line.substr(0, first_comma);
        temp_student.name = line.substr(first_comma + 1, second_comma - first_comma - 1);
        temp_student.gpa = stof(line.substr(second_comma + 1));
        cout << "ID: " << temp_student.id << ", Name: " << temp_student.name << ", GPA: " << temp_student.gpa << endl;
    }
    read_file.close();
    
    return 0;
}
