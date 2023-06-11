#pragma once

#include "Address.h"
#include "Phone.h"

class Person
{
private:
    std::string firstName;
    std::string lastName;

    int age;

    Phone *phone;
    Address *address;

public:
    Person(const std::string& first, const std::string& last, int a, 
    Phone *p, Address *adr) : firstName(first), lastName(last), age(a),
    phone(p), address(adr)
    {

    }

    void setFirstName(std::string firstName);

    void setLastName(std::string);

    std::string getFirstName() const;

    std::string getLastName() const;

    int getAge();

    Phone *getPhone() const;

    Address *getAddress() const;

    void printPerson();
};

