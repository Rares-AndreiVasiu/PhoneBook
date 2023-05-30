#include <iostream>
#include <string>

#include "PhoneBook.h"

void Menu()
{
    puts("=== Phone Book simulator ===");

    puts("Add a contact: press 1");

    puts("Update a contact: press 2");

    puts("Delete a contact: press 3");

    puts("Search for contact: press 4");

    puts("Exit programm: press 5");
}

void SearchContact()
{
    puts("Search by last name: press 1");

    puts("Search by first name: press 2");

    puts("Search by mobile phone number: press 3");

    puts("Search by landline number: press 4");

    puts("Search by address: press 5");
}

void UpdateContact()
{
    puts("Update first name: press 1");

    puts("Update last name: press 2");

    puts("Update mobile phone number: press 3");

    puts("Update landline number: press 4");

    puts("Update address: press 5");
}

void DeleteContact()
{
    puts("Choose between the mobile phone number or the landline number");

    puts("Mobile phone number: press 1");

    puts("Landline number: press 2");
}

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
