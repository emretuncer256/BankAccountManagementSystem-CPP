#include <iostream>
#include "customer.h"
#include <cstdlib>
#include <ctime>

using namespace std;

Customer::Customer(const std::string &name, int age, const std::string &address, const std::string &phone)
        : name(name), age(age), address(address), phone(phone), id(generateId()) {}

long Customer::getId() const {
    return id;
}

std::string Customer::getName() const {
    return name;
}

int Customer::getAge() const {
    return age;
}

std::string Customer::getAddress() const {
    return address;
}

std::string Customer::getPhone() const {
    return phone;
}

void Customer::setName(const std::string &name) {
    this->name = name;
}

void Customer::setAge(int age) {
    if (age < 0) {
        cout << "Invalid age. Please try again." << endl;
        return;
    }
    this->age = age;
}

void Customer::setAddress(const std::string &address) {
    this->address = address;
}

void Customer::setPhone(const std::string &phone) {
    this->phone = phone;
}

long Customer::generateId() {
    srand(time(0));
    return rand() % 99999999 + 10000000;
}

void Customer::display() const {
    cout << "Customer ID: " << id << endl;
    cout << "Name:        " << name << endl;
    cout << "Address:     " << address << endl;
    cout << "Phone:       " << phone << endl;
}