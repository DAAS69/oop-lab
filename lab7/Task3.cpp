#include <iostream>
using namespace std;

class Currency {
protected:
    double amount;
    string currency_code;
    string currency_symbol;
    double exchange_rate;

public:
    Currency(double amt, string code, string symbol, double rate)
        : amount(amt), currency_code(code), currency_symbol(symbol), exchange_rate(rate) {}

    virtual double convert_to_base() = 0;
    virtual double convert_to(Currency* target_currency) = 0;
    virtual void display_currency() = 0;

    double get_exchange_rate() {
        return exchange_rate;
    }
};

class Dollar : public Currency {
public:
    Dollar(double amt) : Currency(amt, "USD", "$", 1.0) {}

    double convert_to_base() override {
        return amount * exchange_rate;
    }

    double convert_to(Currency* target_currency) override {
        double base_value = convert_to_base();
        return base_value / target_currency->get_exchange_rate();
    }

    void display_currency() override {
        cout << "Currency: " << currency_code << " | Symbol: " << currency_symbol
             << " | Amount: " << amount << " | Exchange Rate: " << exchange_rate << endl;
    }
};

class Euro : public Currency {
public:
    Euro(double amt) : Currency(amt, "EUR", "€", 1.1) {}

    double convert_to_base() override {
        return amount * exchange_rate;
    }

    double convert_to(Currency* target_currency) override {
        double base_value = convert_to_base();
        return base_value / target_currency->get_exchange_rate();
    }

    void display_currency() override {
        cout << "Currency: " << currency_code << " | Symbol: " << currency_symbol
             << " | Amount: " << amount << " | Exchange Rate: " << exchange_rate << endl;
    }
};

class Rupee : public Currency {
public:
    Rupee(double amt) : Currency(amt, "INR", "₹", 0.013) {}

    double convert_to_base() override {
        return amount * exchange_rate;
    }

    double convert_to(Currency* target_currency) override {
        double base_value = convert_to_base();
        return base_value / target_currency->get_exchange_rate();
    }

    void display_currency() override {
        cout << "Currency: " << currency_code << " | Symbol: " << currency_symbol
             << " | Amount: " << amount << " | Exchange Rate: " << exchange_rate << endl;
    }
};

int main() {
    Dollar usd(100);
    Euro eur(100);
    Rupee inr(100);

    usd.display_currency();
    eur.display_currency();
    inr.display_currency();

    cout << "100 USD to EUR: " << usd.convert_to(&eur) << " EUR" << endl;
    cout << "100 EUR to INR: " << eur.convert_to(&inr) << " INR" << endl;
    cout << "100 INR to USD: " << inr.convert_to(&usd) << " USD" << endl;

    return 0;
}
