#include <string>
#include "PhoneBook.h"

int PhoneBook::totalContacts = 0;

int PhoneBook::getTotalContacts()
{
    return totalContacts;
}

void PhoneBook::printContactWithFilters(int option)
{
    switch (option)
    {
        case 1:
        {
            //we print the first name, last name, and age

            this->getPerson()->printPerson();

            break;
        }

        case 2:
        {
            //we print the phone numbers

            this->getPerson()->getPhone()->printPhone();

            break;
        }

        case 3:
        {
            // we print the address

            this->getPerson()->getAddress()->printAddress();
        }
    }
}