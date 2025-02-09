#include <iostream>
#include <iomanip>

using namespace std;
int flag =1;

class Angle {
private:
    int degrees;
    float minutes;
    char direction;

public:
    Angle(int deg, float min, char dir) : degrees(deg), minutes(min), direction(dir) {}

    void get_angle() {
        cout << "Enter degrees: ";
        cin >> degrees;
        if(degrees == -1){
            flag = 0;
            return;
        }
        cout << "Enter minutes: ";
        cin >> minutes;
        cout << "Enter direction (N, S, E, W): ";
        cin >> direction;

        
        if ((direction == 'N' || direction == 'S') && (degrees < 0 || degrees > 90)) {
            cout << "Invalid latitude degrees! Must be between 0 and 90.\n";
        } else if ((direction == 'E' || direction == 'W') && (degrees < 0 || degrees > 180)) {
            cout << "Invalid longitude degrees! Must be between 0 and 180.\n";
        }
    }

    void display_angle() const {
        cout << fixed << setprecision(1);
        cout << degrees << "°" << minutes << "' " << direction << endl;
    }
};

int main() {
    Angle initial_angle(149, 34.8, 'W');
    cout << "Initial Angle: ";
    initial_angle.display_angle();

    while (flag) {
        Angle user_angle(0, 0.0, 'N');
        cout << "\nEnter a new angle value(-1 to exit): \n";
        user_angle.get_angle();
        cout << "You entered: ";
        user_angle.display_angle();
    }
    return 0;
}
