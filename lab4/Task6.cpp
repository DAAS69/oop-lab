#include <iostream>

using namespace std;

class Bankaccount{
    int account_number;
    string name;
    double balance;
    public:
    Bankaccount(){
        balance = 0.0;
    }
    void create_account(int account_number, string name){
        this -> account_number = account_number;
        this -> name = name;
        cout << "Account created successfully." << endl;
    }
    void deposit(double amount){
        balance += amount;
        cout << "Deposited successfully." << endl;
    }
    void withdraw(double amount){
        if (amount > balance){
            cout << "sorry your withdraw amount is less then the money you have in your account" << endl;
        }
        else {
            balance -= amount;
            cout << "withdraw successfull. Your new balance is: " << balance << endl;
        }
    }
    void display_details(){
        cout << "\nAccount Number: " << account_number << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
    }
    int getAccountNumber() {
        return account_number;
    }

};

int main(){

    int choice;
    double amount;
    int account_number;
    string name;
    const int MAX_ACCOUNTS = 10;
    Bankaccount accounts[MAX_ACCOUNTS];  
    int num_accounts = 0;
    bool status=true;
    while(status){
        cout << "\n\nWelcome to bank of Fast\n\n" << "1. create an account" << "\n2. add money" << "\n3. withdraw" << "\n4. display details" << "\n5. exit" << endl;
        cout << "Please choose a number between 1 and 5: ";
        cin >> choice;
        switch(choice){
            case 1:
                if (num_accounts < MAX_ACCOUNTS) {
                    cout << "Enter account number: ";
                    cin >> account_number;
                    cout << "Enter name: ";
                    cin >> name;
                    accounts[num_accounts].create_account(account_number, name);
                    num_accounts++;
                } else {
                    cout << "Maximum number of accounts reached.\n";
                }
            break;
            
                        case 2:
                cout << "Enter account number: ";
                cin >> account_number;
                for (int i = 0; i < num_accounts; i++) {
                    if (accounts[i].getAccountNumber() == account_number) {
                        cout << "Enter deposit amount: ";
                        cin >> amount;
                        accounts[i].deposit(amount);
                        break;
                    }
                }
                break;

            case 3:
                cout << "Enter account number: ";
                cin >> account_number;
                for (int i = 0; i < num_accounts; i++) {
                    if (accounts[i].getAccountNumber() == account_number) {
                        cout << "Enter withdrawal amount: ";
                        cin >> amount;
                        accounts[i].withdraw(amount);
                        break;
                    }
                }
                break;

            case 4:
                cout << "Enter account number: ";
                cin >> account_number;
                for (int i = 0; i < num_accounts; i++) {
                    if (accounts[i].getAccountNumber() == account_number) {
                        accounts[i].display_details();
                        break;
                    }
                }
                break;

            case 5:
                status = false;
                cout << "Exiting... Thank you!\n";
                break;

            default:
                cout << "Please enter a number between 1 and 5.\n";
        }

    }
}
