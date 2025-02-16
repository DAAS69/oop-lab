#include <iostream>

using namespace std;

class Employee{
    int employeeid;
    string name;
    string department;
    double salary;
    public:
    Employee(){
        salary = 0.0;
    }

    Employee(int employeeid, string name, string department, double salary){
        this-> employeeid = employeeid;
        this-> name = name;
        this-> department = department;
        this-> salary = salary;
    }

    void givebonus(double bonus){
        salary = salary + bonus;
        cout << "bonus of amount: " << bonus << " has been added to the account of " << name << endl;
    }

    bool ismanager(string department){
        if(department == "managemant" || department == "Management"){
            return true;
        }
        else{   
            return false;
        }

    }

    void displaydetails(){
        cout << "Employee ID: " << employeeid << "\nEmployee Name: " << name << "\nEmployee Department: " << department <<"\nEmployee Salary: " << salary << endl;
        cout << endl;
    }
};

int main(){
    Employee emp1(100, "saim", "developer", 5000.0);
    Employee emp2(200, "saad", "Management", 100000);
    emp1.displaydetails();
    emp1.givebonus(2000);
    emp1.displaydetails();

    emp2.displaydetails();
}
