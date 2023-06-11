#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "handler.h"
#include "PhoneBook.h"
#include "Menu.h"
#include "utils.h"
#include "linkedList.h"
#include <sstream>

#define FIRSTNAME 1
#define LASTNAME 2
#define MOBILE 3
#define LANDLINE 4

linkedList phoneBook;

void loadData(const std::string& filename)
{
    std::ifstream file(filename);

    if (file.is_open())
    {

        std::string line;

        while (std::getline(file, line))
        {
            std::istringstream iss(line);

            std::string firstName, lastName, street, city, country, mobile, landline;

            int age, houseNumber;

            // Parse the CSV line and extract the fields
            if (std::getline(iss, firstName, ',') &&
                std::getline(iss, lastName, ',') &&
                (iss >> age) && iss.ignore() &&
                std::getline(iss, street, ',') &&
                std::getline(iss, city, ',') &&
                std::getline(iss, country, ',') &&
                (iss >> houseNumber) && iss.ignore() &&
                std::getline(iss, mobile, ',') &&
                std::getline(iss, landline))
            {
                // Create new objects for Address and Phone
                // Address* addressObj = new Address(street, city, country, houseNumber);
                // Phone* phoneObj = new Phone(mobile, landline);

                // Create a new Person object
                // Person* personObj = new Person(firstName, lastName, age, addressObj, phoneObj);

                // Create a new PhoneBook object
                // PhoneBook* phoneBookObj = new PhoneBook(personObj);

                // Add the new node to the linked list
                // addNode(phoneBookObj);   

                Phone *phoneObj = new Phone(mobile, landline);

                Address *addressObj = new Address(street,city, country, houseNumber);
           
                Person *personObj = new Person(firstName, lastName, age, phoneObj, addressObj);

                //we instantiate a phone book type
                PhoneBook *phoneBookObj = new PhoneBook(1, personObj);

                phoneBook.addNode(phoneBookObj);
            }
            else
            {
                std::cerr << "Invalid data format in line: " << line << std::endl;
            }
        }

        file.close();
        std::cout << "Data loaded from file: " << filename << std::endl;
    }
    else
    {
        std::cerr << "Unable to open the file: " << filename << std::endl;
    }
}

void handle(int opt, int *load)
{
    if(*load == 0)
    {
        *load = 1;

        loadData("data.csv");
    }

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


            //gotta check if the mobile phone number is unique
            if(!phoneBook.checkUniqueMobilePhoneNumber(mobilePhoneNumber))
            {
                std::cout << "This mobile phone number has been added before!" << '\n';
            }
            else
            {
                flagValidInput = false;

                while (!flagValidInput)
                {
                    std::cout << "Introduce the landline number: ";
                    // we check the landline number
                    getline(std::cin, landlineNumber);

                    flagValidInput = checkLandlineNumber(landlineNumber);
                }

                /*
                    now we can create a phone object
                */
                // Phone *phoneObj = new Phone(mobilePhoneNumber, landlineNumber);

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

                // Address *addressObj = new Address(street,city, country, houseNum);

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

                while (!flagValidInput)
                {
                    std::cout << "Introduce the age: ";

                    std::cin >> age;

                    flagValidInput = checkNumber(age);
                }

                /*
                    now we can create a person obj
                */
                Phone *phoneObj = new Phone(mobilePhoneNumber, landlineNumber);

                Address *addressObj = new Address(street, city, country, houseNum);

                Person *personObj = new Person(firstName, lastName, age, phoneObj, addressObj);

                // we instantiate a phone book type
                PhoneBook *phoneBookObj = new PhoneBook(1, personObj);

                phoneBook.addNode(phoneBookObj);

                phoneBook.saveData("data.csv");
            }

            break;
        }

        // we update a contact
        case 2:
        {
            bool flagUpdateMenuOption = false;

            int opt;

            while(!flagUpdateMenuOption)
            {
                clearConsole();

                UpdateContactMenu();

                std::cout << "Enter your choice: ";

                std::cin >> opt;

                if(checkMenuOption(opt, 1, 4))
                {
                    //now we get the correct option
                    flagUpdateMenuOption = true;
                }
            }
            
            switch (opt)
            {
                case 1:
                {
                    bool flagValidInput = false;
                    
                    std::string mobilePhoneNumber, firstName;

                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    
                    while (!flagValidInput)
                    {   
                        clearConsole();
                    
                        std::cout << "Introduce the mobile phone number: ";

                        getline(std::cin, mobilePhoneNumber);

                        //we check the mobile phone number
                        flagValidInput = checkMobilePhone(mobilePhoneNumber);
                    }   

                    // here we want to update the first name
                    // but we nned to ask for the main key = mobilePhoneNumber
                    //clear the input buffer

                    bool flagCorrectFirstName = false;

                    while(!flagCorrectFirstName)
                    {
                        clearConsole();
                    
                        //we need first to check if the inputed first name is correct 
                        std::cout << "Introduce the new first name of the contact: ";

                        std::cin >> firstName;

                        if(checkName(firstName))
                        {
                            // we have a correct first name
                            flagCorrectFirstName = true;
                        }
                    }

                    if(!phoneBook.searchContactByMobilePhoneNumber(mobilePhoneNumber))
                    {
                        std::cout << "User not found!" << '\n';
                    }
                    else
                    {
                        // now we modify the first name of the given contact
                        
                        std::cout << "==> New Contact <== " << '\n';
                        phoneBook.updateFirstName(mobilePhoneNumber, firstName);

                        phoneBook.printSingleContact(mobilePhoneNumber);

                        phoneBook.saveData("data.csv");
                    }
                    break;
                }

                case 2:
                {
                    bool flagValidInput = false;
                    
                    std::string mobilePhoneNumber, lastName;

                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    
                    while (!flagValidInput)
                    {   
                        clearConsole();
                    
                        std::cout << "Introduce the mobile phone number: ";

                        getline(std::cin, mobilePhoneNumber);

                        //we check the mobile phone number
                        flagValidInput = checkMobilePhone(mobilePhoneNumber);
                    }   

                    // here we want to update the last name
                    // but we nned to ask for the main key = mobilePhoneNumber
                    //clear the input buffer

                    bool flagCorrectLastName = false;

                    while(!flagCorrectLastName)
                    {
                        clearConsole();
                    
                        //we need first to check if the inputed last name is correct 
                        std::cout << "Introduce the new last name of the contact: ";

                        std::cin >> lastName;

                        if(checkName(lastName))
                        {
                            // we have a correct first name
                            flagCorrectLastName = true;
                        }
                    }

                    if(!phoneBook.searchContactByMobilePhoneNumber(mobilePhoneNumber))
                    {
                        std::cout << "User not found!" << '\n';
                    }
                    else
                    {
                        // now we modify the first name of the given contact
                        
                        std::cout << "==> New Contact <== " << '\n';

                        phoneBook.updateLastName(mobilePhoneNumber, lastName);

                        phoneBook.printSingleContact(mobilePhoneNumber);

                        phoneBook.saveData("data.csv");
                    }
                    break;
                }

                case 3:
                {
                    bool flagValidInput = false;
                    
                    std::string mobilePhoneNumber, newMobilePhoneNumber;

                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    
                    while (!flagValidInput)
                    {   
                        clearConsole();
                    
                        std::cout << "Introduce the mobile phone number: ";

                        getline(std::cin, mobilePhoneNumber);

                        //we check the mobile phone number
                        flagValidInput = checkMobilePhone(mobilePhoneNumber);
                    }   

                    // here we want to update the lmobile phone number
                    // but we nned to ask for the main key = mobilePhoneNumber
                    // clear the input buffer

                    bool flagCorrectMobile = false;

                    while(!flagCorrectMobile)
                    {
                        clearConsole();
                    
                        //we need first to check if the inputed mobile phone number is correct 
                        std::cout << "Introduce the new mobile number phone of the contact: ";

                        std::cin >> newMobilePhoneNumber;

                        if(checkMobilePhone(newMobilePhoneNumber))
                        {
                            // we have a correct mobile phone number
                            flagCorrectMobile = true;
                        }
                    }

                    if(!phoneBook.searchContactByMobilePhoneNumber(mobilePhoneNumber))
                    {
                        std::cout << "User not found!" << '\n';
                    }
                    else
                    {
                        if(!phoneBook.checkUniqueMobilePhoneNumber(newMobilePhoneNumber))
                        {
                            std::cout << "User already exists!" << '\n';
                        }
                        else
                        {
                            // now we modify the mobile phone number of the given contact
                        
                            std::cout << "==> New Contact <== " << '\n';

                            phoneBook.updateMobileNumber(mobilePhoneNumber, newMobilePhoneNumber);

                            phoneBook.printSingleContact(newMobilePhoneNumber);

                            phoneBook.saveData("data.csv");
                        }
                        
                    }
                    break;
                }

                case 4:
                {
                    bool flagValidInput = false;
                    
                    std::string mobilePhoneNumber, newLandlineNumber;

                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    
                    while (!flagValidInput)
                    {   
                        clearConsole();
                    
                        std::cout << "Introduce the mobile phone number: ";

                        getline(std::cin, mobilePhoneNumber);

                        //we check the mobile phone number
                        flagValidInput = checkMobilePhone(mobilePhoneNumber);
                    }   

                    // here we want to update the last name
                    // but we nned to ask for the main key = mobilePhoneNumber
                    //clear the input buffer

                    bool flagCorrectLandline = false;

                    while(!flagCorrectLandline)
                    {
                        clearConsole();
                    
                        //we need first to check if the inputed landline number is correct 
                        std::cout << "Introduce the new lanldinenumber of the contact: ";

                        std::cin >> newLandlineNumber;

                        if(checkLandlineNumber(newLandlineNumber))
                        {
                            // we have a correct first name
                            flagCorrectLandline = true;
                        }
                    }

                    if(!phoneBook.searchContactByMobilePhoneNumber(mobilePhoneNumber))
                    {
                        std::cout << "User not found!" << '\n';
                    }
                    else
                    {
                        // now we modify the landline number of the given contact
                        
                        std::cout << "==> New Contact <== " << '\n';

                        phoneBook.updateLandlineNumber(mobilePhoneNumber, newLandlineNumber);

                        phoneBook.printGeneralContacts(newLandlineNumber, LANDLINE);

                        phoneBook.saveData("data.csv");
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

        // we delete a contact
        case 3:
        {
            int opt;

            bool flagValidChoice = false;

            while(!flagValidChoice)
            {
                clearConsole();

                DeleteContactMenu();

                std::cout << "Enter your choice: ";

                std::cin >> opt;

                if(checkMenuOption(opt, 1, 2))
                {
                    // now we have a valid choice
                    flagValidChoice = true;
                }
            }

            switch (opt)
            {
                case 1:
                {
                    // delete by main key the mobile
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    std::string mobilePhoneNumber;

                    bool flagCorrectMobile = false;

                    while(!flagCorrectMobile)
                    {
                        clearConsole();
                    
                        //we need first to check if the inputed mobile phone is correct 
                        std::cout << "Introduce the mobile number phone of the target: ";

                        std::cin >> mobilePhoneNumber;

                        if(checkMobilePhone(mobilePhoneNumber))
                        {
                            // we have a correct mobile phone
                            flagCorrectMobile = true;
                        }
                    }

                    if(!phoneBook.searchContactByMobilePhoneNumber(mobilePhoneNumber))
                    {
                        std::cout << "User not found!" << '\n';
                    }
                    else
                    {
                        // now we delete the contact based on their mobile phone number
                        phoneBook.deleteNode(mobilePhoneNumber, 1);

                        std::cout << "==> Deletion Successful <==" << '\n';

                        phoneBook.saveData("data.csv");
                    }
                    break;
                }

                case 2:
                {
                    //delete by main key to be landline number
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    std::string landlineNumber;

                    bool flagCorrectLandline = false;

                    while(!flagCorrectLandline)
                    {
                        clearConsole();
                    
                        //we need first to check if the inputed mobile phone number is correct 
                        std::cout << "Introduce the landline number of the target: ";

                        std::cin >> landlineNumber;

                        if(checkLandlineNumber(landlineNumber))
                        {
                            // we have a correct mobile phone
                            flagCorrectLandline = true;
                        }
                    }

                    if(!phoneBook.searchContactByLandlineNumber(landlineNumber))
                    {
                        std::cout << "User not found!" << '\n';
                    }
                    else
                    {
                        // now we delete the contact based on their landline number
                        phoneBook.deleteNode(landlineNumber, 2);

                        std::cout << "==> Deletion Successful <==" << '\n';

                        phoneBook.saveData("data.csv");
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
                        clearConsole();

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
                    else
                    {
                        phoneBook.printGeneralContacts(lastName, LASTNAME);
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
                        clearConsole();

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
                    else
                    {
                        phoneBook.printGeneralContacts(firstName, FIRSTNAME);
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
                    else
                    {
                        phoneBook.printGeneralContacts(mobilePhoneNumber, MOBILE);
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
                    else
                    {
                        phoneBook.printGeneralContacts(landlineNumber, LANDLINE);
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
        
        // we print the entire phone book contact's list
        case 5:
        {
            clearConsole();

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
