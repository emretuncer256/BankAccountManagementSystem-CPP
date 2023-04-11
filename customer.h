#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
public:
    Customer(const std::string &name, int age, const std::string &address, const std::string &phone);

    long getId() const;

    std::string getName() const;

    int getAge() const;

    std::string getAddress() const;

    std::string getPhone() const;

    void setName(const std::string &name);

    void setAge(int age);

    void setAddress(const std::string &address);

    void setPhone(const std::string &phone);

    void display() const;

private:
    long id;
    std::string name;
    int age;
    std::string address;
    std::string phone;

    long generateId();
};

#endif // CUSTOMER_H