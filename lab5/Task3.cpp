#include <iostream>
#include <string>

using namespace std;

class ValidateString {
private:
    string str;

public:
    ValidateString(const string& input_str) {
        str = input_str;
    }
    
    string get_str() const {
        return str;
    }

    void check_and_print() const {
        for (char c : str) {
            if (!(c >= 'A' && c <= 'Z') && !(c >= 'a' && c <= 'z')) {
                cout << "Invalid" << endl;
                return;
            }
        }
        cout << "Valid" << endl;
    }
};

int main() {
    ValidateString obj1("HelloWorld");
    ValidateString obj2("Hello123");
    ValidateString obj3("CPlusPlus");

    cout << obj1.get_str() << ": ";
    obj1.check_and_print();

    cout << obj2.get_str() << ": ";
    obj2.check_and_print();

    cout << obj3.get_str() << ": ";
    obj3.check_and_print();

    return 0;
}
