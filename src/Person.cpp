#include "Person.h"

#pragma region Person
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

#pragma endregion Person
