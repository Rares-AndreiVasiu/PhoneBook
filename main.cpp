#include <iostream>
#include <string>

#include "PhoneBook.h"
#include "Person.h"
#include "Phone.h"
#include "Address.h"

// PhoneBook related functions
#pragma region PhoneBook

int PhoneBook::totalContacts = 0;

int PhoneBook::getTotalContacts()
{
    return totalContacts;
}

#pragma endregion PhoneBook

// person related functions

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

// phone class related functions
#pragma region Phone

std::string Phone::getMobileNumber() const
{
    return mobileNumber;
}

std::string Phone::getLandlineNumber() const
{
    return landlineNumber;
}
#pragma endregion Phone

// address related functions
#pragma region Address

std::string Address::getStreet() const
{
    return street;
}

std::string Address::getCity() const
{
    return city;
}

std::string Address::getCountry() const
{
    return country;
}

int Address::getHouseNumber() const
{
    return houseNumber;
}

#pragma endregion Address

int main()
{
    Phone *phoneObj = new Phone("1234567890", "9876543210");

    Address *addressObj = new Address("Main Street", "Cityville", "Countryland", 123);

    Person *personObj = new Person("John", "Doe", 30, phoneObj, addressObj);

    PhoneBook *phoneBookObj = new PhoneBook(1, personObj);

    std::cout << "Index: " << phoneBookObj->getIndex() << std::endl;

    std::cout << "Person: " << phoneBookObj->getPerson()->getFirstName() << " " << phoneBookObj->getPerson()->getLastName() << std::endl;

    std::cout << "Age: " << phoneBookObj->getPerson()->getAge() << std::endl;

    std::cout << "Mobile Phone: " << phoneBookObj->getPerson()->getPhone()->getMobileNumber() << std::endl;

    std::cout << "Landline Phone: " << phoneBookObj->getPerson()->getPhone()->getLandlineNumber() << std::endl;

    std::cout << "Address: " << std::endl;

    std::cout << "Street: " << phoneBookObj->getPerson()->getAddress()->getStreet() << std::endl;

    std::cout << "City: " << phoneBookObj->getPerson()->getAddress()->getCity() << std::endl;

    std::cout << "Country: " << phoneBookObj->getPerson()->getAddress()->getCountry() << std::endl;

    std::cout << "House Number: " << phoneBookObj->getPerson()->getAddress()->getHouseNumber() << std::endl;

    delete phoneObj;

    delete addressObj;

    delete personObj;

    delete phoneBookObj;

    return 0;
}