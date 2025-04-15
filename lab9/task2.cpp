#include <iostream>
#include <string>

using namespace std;

class SmartDevice {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual string getStatus() = 0;
};

class LightBulb : public SmartDevice {
private:
    bool is_on;
    int brightness;

public:
    LightBulb() : is_on(false), brightness(0) {}

    void turnOn() override {
        is_on = true;
        brightness = 100;
    }

    void turnOff() override {
        is_on = false;
        brightness = 0;
    }

    string getStatus() override {
        return "LightBulb is " + string(is_on ? "On" : "Off") + " with brightness " + to_string(brightness) + " %";
    }
};

class Thermostat : public SmartDevice {
private:
    bool is_on;
    double temperature;

public:
    Thermostat() : is_on(false), temperature(22.0) {}

    void turnOn() override {
        is_on = true;
    }

    void turnOff() override {
        is_on = false;
    }

    string getStatus() override {
        return "Thermostat is " + string(is_on ? "On" : "Off") + " with temperature " + to_string(temperature) + " C";
    }
};

int main() {
    LightBulb light;
    Thermostat thermostat;

    light.turnOn();
    thermostat.turnOn();

    cout << light.getStatus() << endl;
    cout << thermostat.getStatus() << endl;

    light.turnOff();
    thermostat.turnOff();

    cout << light.getStatus() << endl;
    cout << thermostat.getStatus() << endl;

    return 0;
}
