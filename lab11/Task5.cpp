#include <iostream>
#include <sstream>
#include <exception>
#include <iomanip>
using namespace std;

class InsufficientFundsException : public exception {
    string message;
public:
    InsufficientFundsException(double deficit) {
        stringstream ss;
        ss << fixed << setprecision(2);
        ss << "InsufficientFundsException - Deficit: $" << deficit;
        message = ss.str();
    }

    const char* what() const noexcept override {
        return message.c_str();
    }
};

template <typename T>
class BankAccount {
private:
    T balance;
public:
    BankAccount(T initialBalance) : balance(initialBalance) {}

    void withdraw(T amount) {
        if (amount > balance) {
            double deficit = static_cast<double>(amount - balance);
            throw InsufficientFundsException(deficit);
        }
        balance -= amount;
        cout << "Withdrawal successful. New balance: $" << fixed << setprecision(2) << static_cast<double>(balance) << endl;
    }

    void displayBalance() const {
        cout << "Balance: $" << fixed << setprecision(2) << static_cast<double>(balance) << endl;
    }
};

int main() {
    BankAccount<double> account(500.00);

    account.displayBalance();

    try {
        account.withdraw(600.00);
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
