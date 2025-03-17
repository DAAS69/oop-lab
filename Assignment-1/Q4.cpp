#include<iostream>

using namespace std;

const int TRANSPORT_FEES = 40000;
const int NUM_OF_ROUTES_PER_BUS = 3;
const int MAX_BUSES = 10;    
const int MAX_STUDENTS = 50; 

class Student{
    int studentID;
    string name;
    string assigned_stop;
    int route_num;
    bool is_fees_paid;

    public:
        Student() : is_fees_paid(false) {}

        Student(int id, string name, string stop){
            studentID = id;
            this -> name = name;
            assigned_stop = stop;
        }

        void pay_fees(int amount){
            if(amount == TRANSPORT_FEES){
                cout << "The fees for student: " << name << " has been paid successfully and his registeration has been completed" << endl;
                is_fees_paid = true;
            }
        }
        
        void tap_card(){
            cout << "Card tap by " << name << endl;
            if(is_fees_paid){
                cout << "Card tapped successfully. you can onboard the bus and your attendance has been marked." << endl;
            }
            else
                cout << "Sorry " << name << " You cannot ride on the bus. Kindly complete your registeration." << endl;
        }
};

class Route{
    int route_num;
    string* pickup_dropoff_points;

    public:
        Route(int num, string* routes){
            route_num = num;
            pickup_dropoff_points = new string[NUM_OF_ROUTES_PER_BUS];
            for (int i=0; i<NUM_OF_ROUTES_PER_BUS; i++){
                pickup_dropoff_points[i] = routes[i];
            }
        }

        ~Route(){
            delete[] pickup_dropoff_points;
        }

        void display_route(){
            cout << "Route Number: " << route_num << endl;
            cout << "pickup and drop-off stops: ";
            for (int i=0; i<NUM_OF_ROUTES_PER_BUS; i++) {
                cout << pickup_dropoff_points[i] << " ";
            }
            cout << endl;
        }
};

class Bus{
    int bus_num;
    Route* r;
    public:
        Bus(int num, Route* r){
            bus_num = num;
            this -> r = r;
        }

        void show_bus_routes(){
            cout << "routes for bus number: " << bus_num << endl;
            r -> display_route();
        }
};

class Transport_system {
    Bus* buses[MAX_BUSES];
    Student* students[MAX_STUDENTS];
    int bus_count;
    int student_count;

public:
    Transport_system() {
        bus_count = 0;
        student_count = 0;
    }

    void add_bus(Bus* bus) {
        if (bus_count < MAX_BUSES) {
            buses[bus_count++] = bus;
        } else {
            cout << "Bus limit reached! Cannot add more buses." << endl;
        }
    }

    void add_student(Student* student) {
        if (student_count < MAX_STUDENTS) {
            students[student_count++] = student;
        } else {
            cout << "Student limit reached! Cannot add more students." << endl;
        }
    }

    void show_all_buses() {
        cout << "\nDisplaying all buses and their routes:\n";
        for (int i=0; i<bus_count; i++) {
            buses[i]->show_bus_routes();
        }
    }

};

int main() {
    string r1[NUM_OF_ROUTES_PER_BUS] = {"Stop1", "Stop2", "Stop3"};
    string r2[NUM_OF_ROUTES_PER_BUS] = {"Stop4", "Stop5", "Stop6"};

    Route* route1 = new Route(1, r1);
    Route* route2 = new Route(2, r2);

    Bus* bus1 = new Bus(1, route1);
    Bus* bus2 = new Bus(2, route2);

    Student* stud1 = new Student(101, "Saad", "Stop1");
    Student* stud2 = new Student(102, "Ali", "Stop5");

    Transport_system transport_system;
    transport_system.add_bus(bus1);
    transport_system.add_bus(bus2);
    transport_system.add_student(stud1);
    transport_system.add_student(stud2);

    transport_system.show_all_buses();


    stud1->pay_fees(40000);

    stud2->tap_card(); // will give cannot ride message as fees not paid for student 2

    stud2->pay_fees(40000);

    stud1->tap_card();

    stud2->tap_card(); // can ride on bus now as fees has been paid.



    delete route1;
    delete route2;
    delete bus1;
    delete bus2;
    delete stud1;
    delete stud2;

    return 0;
}
