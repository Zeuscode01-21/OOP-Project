#include <iostream>
#include <string>
using namespace std;

// Base class
class BankAccount {
private:
    string accountHolder;       // Accessible only inside BankAccount
    double balance;

protected:
    string accountNumber;       // Accessible in derived classes

public:
    BankAccount(const string& holder, const string& number, double initialBalance)
        : accountHolder(holder), balance(initialBalance), accountNumber(number) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful.\n";
        } else {
            cout << "Deposit amount must be positive.\n";
        }
    }

    virtual void display() const {
        cout << "Account holder: " << accountHolder << '\n'
             << "Account number: " << accountNumber << '\n'
             << "Balance: Rs. " << balance << '\n';
    }

    double getBalance() const { return balance; }

    virtual ~BankAccount() = default;
};

// Derived class
class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(const string& holder, const string& number,
                   double balance, double rate)
        : BankAccount(holder, number, balance), interestRate(rate) {}

    void addAnnualInterest() {
        deposit(getBalance() * interestRate / 100.0);
    }

    void display() const override {
        cout << "\n--- Savings Account ---\n";
        BankAccount::display();
        cout << "Interest rate: " << interestRate << "%\n";
    }
};

int main() {
    SavingsAccount account("Riya Sharma", "SB1001", 15000.0, 4.0);
    account.display();

    account.deposit(2000.0);
    account.addAnnualInterest();

    cout << "\nAfter transactions:\n";
    account.display();
    return 0;
}
