#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

// Custom exception hierarchy.
class BankingException : public runtime_error {
public:
    explicit BankingException(const string& message) : runtime_error(message) {}
};

class InsufficientFundsException : public BankingException {
public:
    InsufficientFundsException()
        : BankingException("Transaction rejected: insufficient account balance.") {}
};

class InvalidAmountException : public BankingException {
public:
    InvalidAmountException()
        : BankingException("Transaction rejected: amount must be greater than zero.") {}
};

class BankAccount {
private:
    double balance;

public:
    explicit BankAccount(double openingBalance) : balance(openingBalance) {}

    void deposit(double amount) {
        if (amount <= 0) throw InvalidAmountException();
        balance += amount;
        cout << "Deposit successful. New balance: Rs. " << balance << '\n';
    }

    void withdraw(double amount) {
        if (amount <= 0) throw InvalidAmountException();
        if (amount > balance) throw InsufficientFundsException();
        balance -= amount;
        cout << "Withdrawal successful. New balance: Rs. " << balance << '\n';
    }
};

int main() {
    BankAccount account(5000.0);

    try {
        account.deposit(1500.0);
        account.withdraw(2000.0);
        account.withdraw(10000.0); // Throws InsufficientFundsException
    } catch (const InsufficientFundsException& error) {
        cerr << error.what() << '\n';
    } catch (const InvalidAmountException& error) {
        cerr << error.what() << '\n';
    } catch (const BankingException& error) {
        cerr << "Banking error: " << error.what() << '\n';
    } catch (const exception& error) {
        cerr << "Unexpected error: " << error.what() << '\n';
    }

    try {
        account.deposit(-100.0); // Throws InvalidAmountException
    } catch (const BankingException& error) {
        cerr << error.what() << '\n';
    }

    return 0;
}
