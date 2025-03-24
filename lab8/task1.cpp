#include <iostream>
#include <string>
using namespace std;

class Device {
protected:
    string device_id;
    string device_type;
    double power_rating;
    bool status;
public:
    Device(string id, string type, double rating)
        : device_id(id), device_type(type), power_rating(rating), status(false) {}

    void turn_on() { status = true; cout << device_type << " [ID: " << device_id << "] turned ON." << endl; }
    void turn_off() { status = false; }
    virtual double calculate_power_usage(int hours) { return 0; }
};

class Light : public Device {
public:
    Light(string id, double rating) : Device(id, "LED Light", rating) {}
    double calculate_power_usage(int hours) {
        return power_rating * hours;
    }
};

class Fan : public Device {
    double speed_factor;
public:
    Fan(string id, double rating, double speed)
        : Device(id, "Ceiling Fan", rating), speed_factor(speed) {}
    double calculate_power_usage(int hours) {
        return power_rating * hours * speed_factor;
    }
};

class Air_Conditioner : public Device {
    double current_temp, desired_temp;
public:
    Air_Conditioner(string id, double rating, double curr, double desired)
        : Device(id, "Split AC", rating), current_temp(curr), desired_temp(desired) {}
    double calculate_power_usage(int hours) {
        return power_rating * hours * (1 - (current_temp - desired_temp) / 100);
    }
};

class Security_System : public Device {
public:
    Security_System(string id, double rating) : Device(id, "Home Alarm", rating) {}
    void turn_off() {
        cout << "Authorization required to turn off security system." << endl;
    }
    double calculate_power_usage(int hours) {
        return power_rating * hours + (status ? 10 : 0);
    }
};

class User {
protected:
    string user_id;
    string user_role;
    int access_level;
public:
    User(string id, string role, int level) : user_id(id), user_role(role), access_level(level) {}
    virtual void view_accessible_devices() {}
};

class Regular_User : public User {
public:
    Regular_User(string id) : User(id, "Regular User", 1) {}
    void view_accessible_devices() {
        cout << "User: " << user_id << " - Accessible Devices:\n- LED Light\n- Ceiling Fan\n- Split AC" << endl;
    }
};

class Maintenance_Staff : public User {
public:
    Maintenance_Staff(string id) : User(id, "Maintenance Staff", 2) {}
    void view_accessible_devices() {
        cout << "Maintenance staff can control all devices including security systems." << endl;
    }
    void access_security_logs() {
        cout << "User: " << user_id << " - Security Logs Accessed:\n- Intrusion Detected at 3:00 AM\n- System Reset Performed" << endl;
    }
};

int main() {

    Regular_User user1("U001");
    Maintenance_Staff user2("U002");

    Light light1("L001", 10);
    Fan fan1("F001", 75, 3);
    Air_Conditioner ac1("AC001", 1500, 30, 25);
    Security_System sec1("SEC001", 1000);

    light1.turn_on();
    fan1.turn_on();
    ac1.turn_on();
    sec1.turn_on();

    cout << "\nPower Consumption:" << endl;
    cout << "LED Light: " << light1.calculate_power_usage(5) << " Watts" << endl;
    cout << "Ceiling Fan: " << fan1.calculate_power_usage(5) << " Watts" << endl;
    cout << "Split AC: " << ac1.calculate_power_usage(5) << " Watts" << endl;
    cout << "Security System: " << sec1.calculate_power_usage(5) << " Watts" << endl;

    user1.view_accessible_devices();

    user2.access_security_logs();
    
    return 0;
}
