#include <iostream>
#include <string>

#include "Person.h"

std::string Person::getFirstName() const
{
    return firstName;
}

std::string Person::getLastName() const
{
    return lastName;
}

int Person::getAge()
{
    return age;
}

Phone *Person::getPhone() const
{
    return phone;
}

Address *Person::getAddress() const
{
    return address;
}

void Person::printPerson()
{
    std::cout << "First name: " << this->firstName << '\n';
    
    std::cout << "Last name: " << this->lastName << '\n';

    std::cout << "Age: " << this->age << '\n';
}

void Person::setFirstName(std::string firstName)
{
    this->firstName = firstName;
}

void Person::setLastName(std::string lastName)
{
    this->lastName = lastName;
}