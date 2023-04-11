#include <iostream>
#include "bank_account.h"
#include <cstdlib>
#include <ctime>

using namespace std;

BankAccount::BankAccount(const Customer& customer, double balance, const std::string& accountType)
        : accountNumber(generateAccountNumber()), accountType(accountType), balance(balance), customer(customer) {}

long BankAccount::getAccountNumber() const {
    return accountNumber;
}

std::string BankAccount::getAccountType() const {
    return accountType;
}

double BankAccount::getBalance() const {
    return balance;
}

const Customer& BankAccount::getCustomer() const {
    return customer;
}

void BankAccount::setAccountType(const std::string& accountType) {
    this->accountType = accountType;
}

void BankAccount::setCustomer(const Customer& customer) {
    this->customer = customer;
}

void BankAccount::deposit(double amount) {
    balance += amount;
}

void BankAccount::withdraw(double amount) {
    if (amount > balance) {
        cout << "Error: Insufficient funds." << endl;
        return;
    }
    balance -= amount;
}

long BankAccount::generateAccountNumber() {
    srand(time(0));
    long accountNumber = rand() % 9999999999 + 100000000;
    return accountNumber;
}

void BankAccount::display() const {
    cout << "##### Account details: #####" << endl;
    cout << "Account number: " << accountNumber << endl;
    cout << "Account type:   " << accountType << endl;
    cout << "Balance:        " << balance << endl;
    cout << "##### Customer details: #####" << endl;
    customer.display();
}