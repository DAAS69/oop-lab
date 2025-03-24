#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    string account_number;
    string account_holder;
    double balance;

public:
    Account(string acc_num, string holder, double bal) : account_number(acc_num), account_holder(holder), balance(bal) {}

    void display() {
        cout << "Account Number: " << account_number << " | Holder: " << account_holder << " | Balance: $" << balance << endl;
    }

    double get_balance() { return balance; }
    void deposit(double amount) { balance += amount; }
    bool withdraw(double amount) {
        if (amount > balance) return false;
        balance -= amount;
        return true;
    }
    friend double operator+(Account a1, Account a2) {
        return a1.balance + a2.balance;
    }
    friend bool operator>(Account a1, Account a2) {
        return a1.balance > a2.balance;
    }
};

int main() {

    Account acc1("101", "Shafique Rehman", 5000);
    Account acc2("102", "Talha", 3000);
    
    cout << "1. Adding Account 1 and Account 2 balances." << endl;
    cout << "Total Balance (After Addition): " << acc1 + acc2 << "\n";

    cout << "2. Transferring $2000 from Account 1 to Account 2." << endl;
    if (acc1.withdraw(2000)) {
        acc2.deposit(2000);
    }

    cout << "After Transfer:\n";
    acc1.display();
    acc2.display();
    
    cout << "\n3. Checking which account has a higher balance." << endl;
    if (acc1 > acc2)
        cout << "Shafique Rehman has more balance than Talha." << endl;
    else
        cout << "Shafique Rehman has less balance than Talha." << endl;
    
    cout << "\n4. Final Account Details:\n";
    acc1.display();
    acc2.display();
    
    return 0;
}
