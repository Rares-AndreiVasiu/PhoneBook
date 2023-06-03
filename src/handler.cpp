#include <iostream>
#include <string>
#include <limits>
#include "handler.h"
#include "PhoneBook.h"
#include "Menu.h"
#include "utils.h"
#include "linkedList.h"

linkedList phoneBook;

void handle(int opt)
{
    switch (opt)
    {
        // we add a contact
        case 1:
        {
            AddContactMenu();

            std::string mobilePhoneNumber, landlineNumber;
            
            std::string street, city, country;
            
            int houseNum;

            std::string lastName, firstName;

            int age;
            
            bool flagValidInput = false;
           
            while (!flagValidInput)
            {   
                std::cout << "Introduce the mobile phone number: ";
                //we check the mobile phone number
                getline(std::cin, mobilePhoneNumber);

                flagValidInput = checkMobilePhone(mobilePhoneNumber);
            }   

            flagValidInput = false;
           
            while (!flagValidInput)
            {   
                std::cout << "Introduce the landline number: ";
                //we check the landline number
                getline(std::cin, landlineNumber);

                flagValidInput = checkLandlineNumber(landlineNumber);
            } 

            /*
                now we can create a phone object
            */
            Phone *phoneObj = new Phone(mobilePhoneNumber, landlineNumber);

            flagValidInput = false;

            while (!flagValidInput)
            {
                std::cout << "Introduce the street: ";
                // we check the street name
                getline(std::cin, street);

                flagValidInput = checkName(street);
            }

            flagValidInput = false;

            while (!flagValidInput)
            {
                std::cout << "Introduce the city: ";
                // we check the city name
                getline(std::cin, city);

                flagValidInput = checkName(city);
            }

            flagValidInput = false;

            while (!flagValidInput)
            {
                std::cout << "Introduce the country: ";
                // we check the country name
                getline(std::cin, country);

                flagValidInput = checkCountryName(country);
            }

            flagValidInput = false;

            
            while (!flagValidInput)
            {
                std::cout << "Introduce the house number: ";
                // we check the house number
               std::cin >> houseNum;

                flagValidInput = checkNumber(houseNum);
            }

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            /*
                now we can create an address object
            */

            Address *addressObj = new Address(street,city, country, houseNum);

            flagValidInput = false;
           
            while (!flagValidInput)
            {
                std::cout << "Introduce the last name: ";
                // we check the last name
                getline(std::cin, lastName);

                flagValidInput = checkName(lastName);
            }

            flagValidInput = false;
           
            while (!flagValidInput)
            {
                std::cout << "Introduce the first name: ";
                // we check the first name
                getline(std::cin, firstName);

                flagValidInput = checkName(firstName);
            }

            flagValidInput = false;

            while(!flagValidInput)
            {
                std::cout << "Introduce the age: ";
                std::cin >> age;

                flagValidInput = checkNumber(age);
            }

            /*
                now we can create a person obj
            */
            Person *personObj = new Person(firstName, lastName, age, phoneObj, addressObj);

            //we instantiate a phone book type
            PhoneBook *phoneBookObj = new PhoneBook(1, personObj);

            phoneBook.addNode(phoneBookObj);

            // std::cout << "Index: " << phoneBookObj->getIndex() << std::endl;

            // std::cout << "Person: " << phoneBookObj->getPerson()->getFirstName() << " " << phoneBookObj->getPerson()->getLastName() << std::endl;

            // std::cout << "Age: " << phoneBookObj->getPerson()->getAge() << std::endl;

            // std::cout << "Mobile Phone: " << phoneBookObj->getPerson()->getPhone()->getMobileNumber() << std::endl;

            // std::cout << "Landline Phone: " << phoneBookObj->getPerson()->getPhone()->getLandlineNumber() << std::endl;

            // std::cout << "Address: " << std::endl;

            // std::cout << "Street: " << phoneBookObj->getPerson()->getAddress()->getStreet() << std::endl;

            // std::cout << "City: " << phoneBookObj->getPerson()->getAddress()->getCity() << std::endl;

            // std::cout << "Country: " << phoneBookObj->getPerson()->getAddress()->getCountry() << std::endl;

            // std::cout << "House Number: " << phoneBookObj->getPerson()->getAddress()->getHouseNumber() << std::endl;

            // delete phoneObj;

            // delete addressObj;

            // delete personObj;

            // delete phoneBookObj;

            break;
        }

        // we update a contact
        case 2:
        {
            UpdateContactMenu();

            break;
        }

        // we delete a contact
        case 3:
        {
            DeleteContactMenu();

            break;
        }

        // we search for a contact
        case 4:
        {
            bool flagMenuOption = false;

            int opt;

            while (!flagMenuOption)
            {
                clearConsole();

                SearchContactMenu();

                std::cout << "Enter your choice: ";

                std::cin >> opt;

                if(checkMenuOption(opt, 1, 4))
                {
                    flagMenuOption = true;
                }
            }

            clearConsole();

            switch (opt)
            {
                case 1:
                {
                    //search by last name
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    bool flagCorrectLastName = false;

                    std::string lastName;

                    while(!flagCorrectLastName)
                    {
                        std::cout << "Introduce the last name of the contact: ";

                        std::cin >> lastName;

                        if(checkName(lastName))
                        {
                            flagCorrectLastName = true;
                        }
                    }

                    if(!phoneBook.searchContactByLastName(lastName))
                    {
                        std::cout << "User not found!" << '\n';
                    }

                    break;
                }

                case 2:
                {
                    //search by first name
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    bool flagCorrectFirstName = false;

                    std::string firstName;

                    while(!flagCorrectFirstName)
                    {
                        std::cout << "Introduce the first name of the contact: ";

                        std::cin >> firstName;

                        if(checkName(firstName))
                        {
                            flagCorrectFirstName = true;
                        }
                    }

                    if(!phoneBook.searchContactByFirstName(firstName))
                    {
                        std::cout << "User not found!" << '\n';
                    }

                    break;
                }

                case 3:
                {
                    // search by mobile phone number
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    bool flagCorrectMobilePhoneNumber = false;

                    std::string mobilePhoneNumber;

                    while(!flagCorrectMobilePhoneNumber)
                    {
                        std::cout << "Introduce the mobile phone number of the contact: ";

                        std::cin >> mobilePhoneNumber;

                        if(checkMobilePhone(mobilePhoneNumber))
                        {
                            flagCorrectMobilePhoneNumber = true;
                        }
                    }

                    if(!phoneBook.searchContactByMobilePhoneNumber(mobilePhoneNumber))
                    {
                        std::cout << "User not found!" << '\n';
                    }
                    break;
                }

                case 4:
                {
                    // search by landline phone number
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    bool flagCorrectLandlineNumber = false;

                    std::string landlineNumber;

                    while(!flagCorrectLandlineNumber)
                    {
                        std::cout << "Introduce the landline number of the contact: ";

                        std::cin >> landlineNumber;

                        if(checkLandlineNumber(landlineNumber))
                        {
                            flagCorrectLandlineNumber = true;
                        }
                    }

                    if(!phoneBook.searchContactByLandlineNumber(landlineNumber))
                    {
                        std::cout << "User not found!" << '\n';
                    }
                    break;
                }

                default:
                {
                    break;
                }
            }
            break;
        }

        case 5:
        {
            phoneBook.printList();

            break;
        }

        // we exit the program
        case 6:
        {
            exitProgram();

            break;
        }

        default:
        {
            break;
        }
    }
}