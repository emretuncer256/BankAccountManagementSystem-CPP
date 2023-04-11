#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <string>
#include "customer.h"

class BankAccount {
public:
    explicit BankAccount(const Customer &customer, double balance = 0.0, const std::string &accountType = "Checking");

    long getAccountNumber() const;

    std::string getAccountType() const;

    double getBalance() const;

    const Customer &getCustomer() const;

    void setAccountType(const std::string &accountType);

    void setCustomer(const Customer &customer);

    void deposit(double amount);

    void withdraw(double amount);

    void display() const;

private:
    int accountNumber;
    std::string accountType;
    double balance;
    Customer customer;

    long generateAccountNumber();
};

#endif // BANK_ACCOUNT_H