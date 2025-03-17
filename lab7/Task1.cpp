#include <iostream>
#include <string>

using namespace std;

class Account {
protected:
    string account_number;
    string account_holder_name;
    double balance;
    string account_type;

public:
    Account(string acc_num, string holder_name, double initial_balance, string acc_type = "General")
        : account_number(acc_num), account_holder_name(holder_name), balance(initial_balance), account_type(acc_type) {}

    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << " | New Balance: " << balance << "\n";
    }

    virtual bool withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance!\n";
            return false;
        }
        balance -= amount;
        cout << "Withdrawn: " << amount << " | Remaining Balance: " << balance << "\n";
        return true;
    }

    virtual double calculate_interest() const = 0;

    virtual void print_statement() const {
        cout << "Account Holder: " << account_holder_name << " | Balance: " << balance << "\n";
    }

    virtual void get_account_info() const {
        cout << "Account Number: " << account_number << "\nHolder Name: " << account_holder_name 
             << "\nBalance: " << balance << "\nAccount Type: " << account_type << "\n";
    }

    virtual ~Account() {}
};

class Savings_Account : public Account {
    double interest_rate;
    double minimum_balance;

public:
    Savings_Account(string acc_num, string holder_name, double initial_balance, double rate, double min_bal)
        : Account(acc_num, holder_name, initial_balance, "Savings"), interest_rate(rate), minimum_balance(min_bal) {}

    double calculate_interest() const override {
        return balance * (interest_rate / 100);
    }

    bool withdraw(double amount) override {
        if ((balance - amount) < minimum_balance) {
            cout << "Cannot withdraw! Minimum balance requirement not met.\n";
            return false;
        }
        return Account::withdraw(amount);
    }
};

class Checking_Account : public Account {
public:
    Checking_Account(string acc_num, string holder_name, double initial_balance)
        : Account(acc_num, holder_name, initial_balance, "Checking") {}

    double calculate_interest() const override {
        return 0.0;
    }
};

class Fixed_Deposit_Account : public Account {
    double fixed_interest_rate;
    int maturity_date;

public:
    Fixed_Deposit_Account(string acc_num, string holder_name, double initial_balance, double fixed_rate, int maturity)
        : Account(acc_num, holder_name, initial_balance, "Fixed Deposit"), fixed_interest_rate(fixed_rate), maturity_date(maturity) {}

    double calculate_interest() const override {
        return balance * (fixed_interest_rate / 100);
    }

    bool withdraw(double amount) override {
        cout << "Withdrawals not allowed before maturity!\n";
        return false;
    }
};

int main() {
    Savings_Account sa("S123", "huzaifa", 5000, 3.5, 1000);
    Checking_Account ca("C456", "saim", 3000);
    Fixed_Deposit_Account fda("F789", "saad", 10000, 5.0, 2028);

    cout << "Savings Account";
    sa.deposit(1000);
    sa.withdraw(4500);
    cout << "Interest: " << sa.calculate_interest() << "\n";
    sa.print_statement();

    cout << "Checking Account";
    ca.deposit(500);
    ca.withdraw(2000);
    ca.print_statement();

    cout << "Fixed Deposit Account";
    fda.deposit(2000);
    fda.withdraw(1000);
    cout << "Interest: " << fda.calculate_interest() << "\n";
    fda.print_statement();

    return 0;
}
