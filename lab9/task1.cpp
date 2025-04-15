#include<iostream>
using namespace std;


class Vehicle {
        string model;
        double rate;
    public:
        Vehicle(string model, double rate) : model(model), rate(rate) {}

        virtual double get_daily_rate() = 0;
        virtual void display_details() = 0;


};

class Car: public Vehicle{
        string model;
        double rate;
    public:
        Car(string model, double rate) : Vehicle(model,rate), model(model), rate(rate) {}
        double get_daily_rate() override { return rate; }
        void display_details() override {
            cout << "The model of the car is: " << model << endl;
            cout << "rate of this car is: " << rate << endl;
        }


};

class Bike: public Vehicle{
        string model;
        double rate;
    public:
        Bike(string model, double rate) : Vehicle(model,rate), model(model), rate(rate) {}

        double get_daily_rate() override{ return rate; }
        void display_details() override {
            cout << "The model of the Bike is: " << model << endl;
            cout << "rate of this bike is: " << rate << endl;
        }


};

int main(){
	Car car1("civic", 20000);
	Bike bike1("125", 10000);
	car1.display_details();
	bike1.display_details();
}
