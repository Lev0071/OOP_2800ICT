#include <iostream>                             /*(1)*/
#include <stdexcept>                            /*(2)*/
#include <string>                               /*(3)*/

// Custom exception class                       /*(4)*/
class InsufficientFundsException : public std::exception { /*(5)*/
private:                                        /*(6)*/
    std::string message;                        /*(7)*/
public:                                         /*(8)*/
    InsufficientFundsException(const std::string& msg)     /*(9)*/
        : message(msg) {}                       /*(10)*/

    // Override what() to return the custom message         /*(11)*/
    virtual const char* what() const noexcept override {   /*(12)*/
        return message.c_str();                 /*(13)*/
    }                                           /*(14)*/
};                                              /*(15)*/

class BankAccount {                             /*(16)*/
private:                                        /*(17)*/
    double balance;                             /*(18)*/
public:                                         /*(19)*/
    BankAccount(double initialBalance)          /*(20)*/
        : balance(initialBalance) {}            /*(21)*/

    void withdraw(double amount) {              /*(22)*/
        if (amount > balance) {                 /*(23)*/
            throw InsufficientFundsException(   /*(24)*/
                "Withdrawal amount exceeds balance."       /*(25)*/
            );                                  /*(26)*/
        }                                       /*(27)*/
        balance -= amount;                      /*(28)*/
        std::cout << "Withdrawal successful. New balance: $"  /*(29)*/
                  << balance << std::endl;      /*(30)*/
    }                                           /*(31)*/
};                                              /*(32)*/

int main() {
    BankAccount account(100.00); // Initialize account with $100

    try {
        std::cout << "Attempting to withdraw $150..." << std::endl;
        account.withdraw(150.00); // Attempt to withdraw $150
    } catch (const InsufficientFundsException& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }

    return 0;
}

// g++ -std=c++2b bank_account.cpp -o bankAccount
