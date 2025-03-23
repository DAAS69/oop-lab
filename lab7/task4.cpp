#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int id;
    string address;
    string phone_number;
    string email;

public:
    Person(string n, int i, string a, string p, string e)
        : name(n), id(i), address(a), phone_number(p), email(e) {}

    virtual void display_info() {
        cout << "Name: " << name << "\nID: " << id << "\nAddress: " << address
             << "\nPhone: " << phone_number << "\nEmail: " << email << endl;
    }
};

class Student : public Person {
    int courses_enrolled;
    double gpa;
    int enrollment_year;

public:
    Student(string n, int i, string a, string p, string e, int c, double g, int y)
        : Person(n, i, a, p, e), courses_enrolled(c), gpa(g), enrollment_year(y) {}
    string get_name(){
        return name;
    }
    void display_info() override {
        Person::display_info();
        cout << "Courses Enrolled: " << courses_enrolled << "\nGPA: " << gpa
             << "\nEnrollment Year: " << enrollment_year << endl;
    }
};

class Professor : public Person {
    string department;
    int courses_taught;
    double salary;

public:
    Professor(string n, int i, string a, string p, string e, string d, int c, double s)
        : Person(n, i, a, p, e), department(d), courses_taught(c), salary(s) {}

    void display_info() override {
        Person::display_info();
        cout << "Department: " << department << "\nCourses Taught: " << courses_taught
             << "\nSalary: $" << salary << endl;
    }
};

class Staff : public Person {
    string department;
    string position;
    double salary;

public:
    Staff(string n, int i, string a, string p, string e, string d, string pos, double s)
        : Person(n, i, a, p, e), department(d), position(pos), salary(s) {}

    void display_info() override {
        Person::display_info();
        cout << "Department: " << department << "\nPosition: " << position
             << "\nSalary: $" << salary << endl;
    }
};

class Course {
    int course_id;
    string course_name;
    int credits;
    string instructor;
    string schedule;

public:
    Course(int id, string name, int c, string inst, string sched)
        : course_id(id), course_name(name), credits(c), instructor(inst), schedule(sched) {}

    void register_student(Student* student) {
        cout << student->get_name() << " has been registered for " << course_name << endl;
    }

    double calculate_grades(double assignment, double exam) {
        return (assignment * 0.4) + (exam * 0.6);
    }

    void display_course_info() {
        cout << "Course ID: " << course_id << "\nCourse Name: " << course_name
             << "\nCredits: " << credits << "\nInstructor: " << instructor
             << "\nSchedule: " << schedule << endl;
    }
};

int main() {
    Student s("umar akmal", 001, "liaqatabad", "1234567890", "umar@email.com", 5, 3.8, 2022);
    Professor p("jahanzaib", 002, "shahrah e faisal", "9876543210", "jahanzaib@email.com", "CS", 3, 75000);
    Staff st("saad", 003, "drigh Road", "5555555555", "saad@email.com", "HR", "Manager", 50000);

    Course c(101, "Computer Science", 4, "jahanzaib", "monday 10AM");

    s.display_info();
    cout << endl;
    p.display_info();
    cout << endl;
    st.display_info();
    cout << endl;
    c.display_course_info();
    cout << endl;
    cout << "Grade Calculation: " << c.calculate_grades(85, 90) << endl;

    return 0;
}
