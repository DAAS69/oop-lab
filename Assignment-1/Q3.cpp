#include <iostream>
#include <string>

using namespace std;

class Vehicles {
    int vehicleID;
    string vehicle_type;
    string vehicle_name;

public:
    Vehicles(int id, string type, string name) : vehicleID(id), vehicle_type(type), vehicle_name(name) {}

    string car_type(){ 
        return vehicle_type; 
    }    

    string get_name(){ 
        return vehicle_name; 
    }
};

class User {
    int userID;
    int age;
    string name;
    string license_type;
    string contact_info;

public:
    User(int id, int age, string name, string license, string info): userID(id), age(age), name(name), license_type(license), contact_info(info) {}
    
    void update_details(int new_age, string new_name, string new_license, string new_info){
        cout << "Updating details for user: " << userID << endl;
        age = new_age;
        name = new_name;
        license_type = new_license;
        contact_info = new_info;
    }
    string get_name(){
        return name;
    }

    bool is_eligible(Vehicles* v){
        if ((license_type == "learner" && v->car_type() == "ATV") || (license_type == "intermediate" && (v->car_type() == "ATV" || v->car_type() == "LTV")) || (license_type == "full")){
            return true;
        }
        cout << "Sorry " << name << " You are not eligible to rent a " << v->car_type() << "." << endl;
        return false;
    }
};

class RentCar {
    Vehicles** available_vehicles;
    int capacity;
    int count;

    void resize(){
        int new_capacity = capacity * 2;
        Vehicles** new_array = new Vehicles*[new_capacity];
        for (int i = 0; i < count; i++) {
            new_array[i] = available_vehicles[i];
        }
        delete[] available_vehicles;
        available_vehicles = new_array;
        capacity = new_capacity;
    }

public:
    RentCar(int cap) : capacity(cap), count(0){
        available_vehicles = new Vehicles*[capacity];
    }

    ~RentCar(){
        for (int i=0; i<count; i++){
            delete available_vehicles[i];
        }
        delete[] available_vehicles;
    }

    void add_vehicle(int id, string type, string name){
        if (count >= capacity){
            resize();
        }
        available_vehicles[count++] = new Vehicles(id, type, name);
    }

    void remove_vehicle(int index){
        delete available_vehicles[index];
        for (int i=index; i<count-1; i++){
            available_vehicles[i] = available_vehicles[i+1];
        }
        count--;
    }

    void show_vehicles(){
        cout << "Available vehicles for rent are:" << endl;
        for (int i=0; i<count; i++) {
            cout << i + 1 << ". " << available_vehicles[i]->car_type() << " - " << available_vehicles[i]->get_name() << endl;
        }
    }

    void rent_vehicle(User& user, int index){
        if (index>=0 && index<count){
            if (user.is_eligible(available_vehicles[index])){
                cout << available_vehicles[index]->get_name() << " is rented successfully for " << user.get_name() << endl;
                remove_vehicle(index);
            }
        } else {
            cout << "Invalid vehicle selection." << endl;
        }
    }
};

int main() {
    RentCar fast_rental(5);
    fast_rental.add_vehicle(1, "ATV", "Quad Bike");
    fast_rental.add_vehicle(2, "LTV", "civic");
    fast_rental.add_vehicle(3, "HTV", "water tanker");
    fast_rental.add_vehicle(4, "LTV", "corolla");
    fast_rental.add_vehicle(5, "LTV", "elantra");


    fast_rental.show_vehicles();
    
    User user1(101, 22, "saad", "learner", "saad@gmail.com");
    User user2(102, 20, "ali", "intermediate", "ali@gmail.com");

    
    user1.update_details(23, "saad", "full", "saad@gmail.com");
    
    fast_rental.rent_vehicle(user1, 1); 

    fast_rental.show_vehicles();

    fast_rental.rent_vehicle(user2, 1); // will give not elligible message
        
    
    return 0;
}
