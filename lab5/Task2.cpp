#include<iostream>
using namespace std;

float validate_rate(float rate){
    if(rate >= 0 && rate <= 0.5){
        return rate;
    }
    else{
        cout << "Invalid interest rate. Please enter a value between 0 and 0.5%" << endl;
        return 0.0;
    }
}

class Loan_Helper {
    const float interest_rate;
    float loan_amount;
    float amount_to_be_paid;
    int months;
    
public:
    Loan_Helper(float interest, float loan, int months) : interest_rate(validate_rate(interest)), loan_amount(loan), months(months) {
        amount_to_be_paid = loan_amount / months;
    }

    void calculate_payment(){
        float interest, amount;
        amount = loan_amount / months;
        interest = amount + (amount * (interest_rate / 100));
        cout << "You have to pay $" << interest << " every month for " << months << " months to repay your loan." << endl;
    }
};

int main(){
    Loan_Helper loan_helper(0.004, 1000, 12);
    loan_helper.calculate_payment();
}
