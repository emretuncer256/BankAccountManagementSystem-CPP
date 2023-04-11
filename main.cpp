#include <iostream>
#include <string>
#include <vector>
#include "bank_account.h"
#include "customer.h"

using namespace std;

// Function to display the main menu options
void displayMenu() {
    cout << "----- Customer Panel -----" << endl;
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
}

// Function to validate a customer ID
bool validateCustomerId(const vector<Customer> &customers, long customerId) {
    for (const Customer &customer: customers) {
        if (customer.getId() == customerId) {
            return true;
        }
    }
    return false;
}

// Function to get the customer object with a given ID
Customer getCustomerById(const vector<Customer> &customers, long customerId) {
    for (const Customer &customer: customers) {
        if (customer.getId() == customerId) {
            return customer;
        }
    }
    // If customer not found, return a default customer object
    return Customer("", 0, "", "");
}

// Function to log in to a customer account
void login(vector<Customer> &customers, vector<BankAccount> &accounts) {
    long customerId;
    cout << "Enter your customer ID: ";
    cin >> customerId;
    if (!validateCustomerId(customers, customerId)) {
        cout << "Invalid customer ID. Please try again." << endl;
        return;
    }
    Customer customer = getCustomerById(customers, customerId);

    // Find the bank account for the customer and display account details
    for (BankAccount &account: accounts) {
        if (account.getCustomer().getId() == customerId) {
            cout << "---------------------------" << endl;
            account.display();
            int choice;
            do {
                cout << "--------- Menu ------------" << endl;
                cout << "1. Make a deposit" << endl;
                cout << "2. Make a withdrawal" << endl;
                cout << "3. Show personal information" << endl;
                cout << "4. Update personal information" << endl;
                cout << "5. Return to main menu" << endl;
                cout << "Enter your choice: ";
                cin >> choice;
                switch (choice) {
                    case 1: {
                        double amount;
                        cout << "Enter the amount to deposit: ";
                        cin >> amount;
                        account.deposit(amount);
                        cout << "Deposit of $" << amount << " successful." << endl;
                        break;
                    }
                    case 2: {
                        double amount;
                        cout << "Enter the amount to withdraw: ";
                        cin >> amount;
                        account.withdraw(amount);
                        break;
                    }
                    case 3:
                        cout << "---------------------------" << endl;
                        account.display();
                        cout << "---------------------------" << endl;
                        break;
                    case 4: {
                        string name, address, phone;
                        cin.ignore();
                        cout << "Enter your name: ";
                        getline(cin, name);
                        customer.setName(name);
                        cout << "Enter your address: ";
                        getline(cin, address);
                        customer.setAddress(address);
                        cout << "Enter your phone number: ";
                        getline(cin, phone);
                        customer.setPhone(phone);
                        account.setCustomer(customer);
                        account.display();
                        cout << "Personal information updated." << endl;
                        break;
                    }
                    case 5:
                        cout << "Returning to main menu." << endl;
                        break;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                        break;
                }
            } while (choice != 5);
            return;
        }
    }
}

// Function to register a new customer and bank account
void registerCustomer(vector<Customer> &customers, vector<BankAccount> &accounts) {
    string name, address, phone, accountType;
    int age;
    cin.ignore();
    cout << "Enter your full name: ";
    getline(cin, name);
    cout << "Enter your age: ";
    cin >> age;
    if(age < 18) {
        cout << "You must be 18 years or older to open an account." << endl;
        return;
    }
    cout << "Enter your address: ";
    getline(cin, address);
    cout << "Enter your phone number: ";
    getline(cin, phone);
    cout << "Enter your account type (Savings/Checking): ";
    getline(cin, accountType);
    Customer customer(name, age, address, phone);
    customers.push_back(customer);
    BankAccount account(customer, 0.0, accountType);
    accounts.push_back(account);
    cout << "--------------------------------------------" << endl;
    cout << "Registration successful. Your customer ID is " << customer.getId() << "." << endl;
}

int main() {
    vector<Customer> customers;
    vector<BankAccount> accounts;

    // Main program loop
    int choice;
    do {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                login(customers, accounts);
                break;
            case 2:
                registerCustomer(customers, accounts);
                break;
            case 3:
                cout << "Exiting... Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 3);

    return 0;
}