#include <iostream>
#include <string>


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