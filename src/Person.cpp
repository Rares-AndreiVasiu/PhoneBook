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