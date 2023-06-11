#include <limits>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "linkedList.h"
#include "PhoneBook.h"

linkedList::linkedList()
{
    this->head = nullptr;
}

void linkedList::addNode(PhoneBook *data)
{
    node *newnode = new node;

    newnode->phoneBookObj = data;

    newnode->next = nullptr;

    if (head == nullptr)
    {
        head = newnode;
    }
    else
    {
        node *temp = head;

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = newnode;
    }

    std::cout << "New node has been added!" << '\n';
}

void linkedList::deleteList()
{
    node *current = head;

    while (current != nullptr)
    {
        node *next = current->next;

        delete current;

        current = next;
    }
    head = nullptr;

    std::cout << "Deleted the entire list." << std::endl;
}

void linkedList::printList()
{
    if (head == nullptr)
    {
        std::cout << "The list is empty." << std::endl;
    }
    else
    {
        node *current = head;

        int index = 0;

        // std::cout << "List: ";

        while (current != nullptr)
        {
            index++;

            std::cout << "Index: " << index << std::endl;

            current->phoneBookObj->getPerson()->printPerson();

            current->phoneBookObj->getPerson()->getPhone()->printPhone();

            current->phoneBookObj->getPerson()->getAddress()->printAddress();

            current = current->next;
        }
        std::cout << '\n';
    }
}

bool linkedList::searchContactByLastName(std::string lastName)
{
    bool flag = false;

    if (head == nullptr)
    {
        return false;
    }
    else
    {
        node *current = head;

        int index = 0;

        // std::cout << "List: ";

        while (current != nullptr)
        {
            index ++;

            if(current->phoneBookObj->getPerson()->getLastName() == lastName)
            {
                std::cout << "User found!" << '\n';

                // current -> phoneBookObj -> getPerson() -> printPerson();

                // current -> phoneBookObj -> getPerson() -> getPhone() -> printPhone();

                // current -> phoneBookObj -> getPerson() -> getAddress() -> printAddress();

                flag = true;
            }
            current = current->next;
        }
    }
    return flag;
}

bool linkedList::searchContactByFirstName(std::string firstName)
{
    bool flag = false;

    if (head == nullptr)
    {
        return false;
    }
    else
    {
        node *current = head;

        int index = 0;

        // std::cout << "List: ";

        while (current != nullptr)
        {
            index ++;

            if(current->phoneBookObj->getPerson()->getFirstName() == firstName)
            {
                std::cout << "User found!" << '\n';

                // current -> phoneBookObj -> getPerson() -> printPerson();

                // current -> phoneBookObj -> getPerson() -> getPhone() -> printPhone();

                // current -> phoneBookObj -> getPerson() -> getAddress() -> printAddress();
                
                flag = true;
            }

            current = current->next;
        }
    }
    return flag;
}

bool linkedList::searchContactByMobilePhoneNumber(std::string mobilePhoneNumber)
{
    if (head == nullptr)
    {
        return false;
    }
    else
    {
        node *current = head;

        int index = 0;

        // std::cout << "List: ";

        while (current != nullptr)
        {
            index ++;

            if(current->phoneBookObj->getPerson()->getPhone()->getMobileNumber() == mobilePhoneNumber)
            {
                std::cout << "User found!" << '\n';

                // current -> phoneBookObj -> getPerson() -> printPerson();

                // current -> phoneBookObj -> getPerson() -> getPhone() -> printPhone();

                // current -> phoneBookObj -> getPerson() -> getAddress() -> printAddress();

                return true;
            }

            current = current->next;
        }
    }
    return false;
}

bool linkedList::searchContactByLandlineNumber(std::string landlineNumber)
{
    if (head == nullptr)
    {
        return false;
    }
    else
    {
        node *current = head;

        int index = 0;

        // std::cout << "List: ";

        while (current != nullptr)
        {
            index ++;

            if(current->phoneBookObj->getPerson()->getPhone()->getLandlineNumber() == landlineNumber)
            {
                std::cout << "User found!" << '\n';

                // current -> phoneBookObj -> getPerson() -> printPerson();

                // current -> phoneBookObj -> getPerson() -> getPhone() -> printPhone();

                // current -> phoneBookObj -> getPerson() -> getAddress() -> printAddress();
                return true;
            }

            current = current->next;
        }
    }
    return false;
}

void linkedList::updateFirstName(std::string mobilePhoneNumber, std::string firstName)
{
    if (head == nullptr)
    {
        std::cout << "The list is empty!" << '\n';
        std::cout << "Update unsuccessful!" << '\n';
    }
    else
    {
        node *current = head;

        int index = 0;

        // std::cout << "List: ";

        while (current != nullptr)
        {
            index ++;

            if(current->phoneBookObj->getPerson()->getPhone()->getMobileNumber() == mobilePhoneNumber)
            {
                current -> phoneBookObj -> getPerson() -> setFirstName(firstName);

                return;
            }

            current = current->next;
        }
    }
}

void linkedList::printSingleContact(std::string mobilePhoneNumber)
{
    if (head == nullptr)
    {
        std::cout << "The list is empty!" << '\n';
    }
    else
    {
        node *current = head;

        while (current != nullptr)
        {
            if(current -> phoneBookObj -> getPerson() -> getPhone() -> getMobileNumber() == mobilePhoneNumber)
            {
                current -> phoneBookObj -> getPerson() -> printPerson();

                current -> phoneBookObj -> getPerson() -> getPhone() -> printPhone();

                current -> phoneBookObj -> getPerson() -> getAddress() -> printAddress();

                return;
            }
            current = current->next;
        }
    }
}

void linkedList::printGeneralContacts(std::string field, int opt)
{
    /*
        opt values:
        1 - first name printing
        2 - last name printing
        3 - mobile phone number printing
        4 - landline number printing
    */

    if (head == nullptr)
    {
        std::cout << "The list is empty!" << '\n';
    }
    else
    {
        node *current = head;

        while (current != nullptr)
        {
            switch (opt)
            {
                case 1:
                {
                    //we try to find a matching first name for printing
                    if (current->phoneBookObj->getPerson()->getFirstName() == field)
                    {
                        current->phoneBookObj->getPerson()->printPerson();

                        current->phoneBookObj->getPerson()->getPhone()->printPhone();

                        current->phoneBookObj->getPerson()->getAddress()->printAddress();
                    }
                    break;
                }

                case 2:
                {
                    // we try to find a matching last name for printing

                    if (current->phoneBookObj->getPerson()->getLastName() == field)
                    {
                        current->phoneBookObj->getPerson()->printPerson();

                        current->phoneBookObj->getPerson()->getPhone()->printPhone();

                        current->phoneBookObj->getPerson()->getAddress()->printAddress();
                    }
                    break;
                }

                case 3:
                {
                    // we try to find a matching mobile phone number

                    if (current->phoneBookObj->getPerson()->getPhone()->getMobileNumber() == field)
                    {
                        current->phoneBookObj->getPerson()->printPerson();

                        current->phoneBookObj->getPerson()->getPhone()->printPhone();

                        current->phoneBookObj->getPerson()->getAddress()->printAddress();

                        return;
                    }
                    break;
                }

                case 4:
                {
                    // we try to find a matching landline number

                    if (current->phoneBookObj->getPerson()->getPhone()->getLandlineNumber() == field)
                    {
                        current->phoneBookObj->getPerson()->printPerson();

                        current->phoneBookObj->getPerson()->getPhone()->printPhone();

                        current->phoneBookObj->getPerson()->getAddress()->printAddress();

                        return;
                    }
                    break;
                }
            }
            current = current->next;
        }
    }
}

void linkedList::updateLastName(std::string mobilePhoneNumber, std::string lastName)
{
    if (head == nullptr)
    {
        std::cout << "The list is empty!" << '\n';
        std::cout << "Update unsuccessful!" << '\n';
    }
    else
    {
        node *current = head;

        int index = 0;

        // std::cout << "List: ";

        while (current != nullptr)
        {
            index ++;

            if(current->phoneBookObj->getPerson()->getPhone()->getMobileNumber() == mobilePhoneNumber)
            {
                current -> phoneBookObj -> getPerson() -> setLastName(lastName);

                return;
            }

            current = current->next;
        }
    }
}

bool linkedList::checkUniqueMobilePhoneNumber(const std::string& mobile)
{
    if (head == nullptr)
    {
        // std::cout << "The list is empty!" << '\n';

        return true;
    }
    else
    {
        node *current = head;

        while (current != nullptr)
        {
            if(current -> phoneBookObj -> getPerson() -> getPhone() -> getMobileNumber() == mobile)
            {
                return false;
            }
            current = current->next;
        }
    }
    return true;
}

void linkedList::updateMobileNumber(std::string mobilePhoneNumber, std::string newMobileNumber)
{
    if (head == nullptr)
    {
        std::cout << "The list is empty!" << '\n';
        std::cout << "Update unsuccessful!" << '\n';
    }
    else
    {
        node *current = head;

        int index = 0;

        // std::cout << "List: ";

        while (current != nullptr)
        {
            index ++;

            if(current->phoneBookObj->getPerson()->getPhone()->getMobileNumber() == mobilePhoneNumber)
            {
                current -> phoneBookObj -> getPerson() -> getPhone()->setMobileNumber(newMobileNumber);

                return;
            }

            current = current->next;
        }
    }
}

void linkedList::updateLandlineNumber(std::string mobilePhoneNumber, std::string newLanldineNumber)
{
    if (head == nullptr)
    {
        std::cout << "The list is empty!" << '\n';
        std::cout << "Update unsuccessful!" << '\n';
    }
    else
    {
        node *current = head;

        int index = 0;

        // std::cout << "List: ";

        while (current != nullptr)
        {
            index ++;

            if(current->phoneBookObj->getPerson()->getPhone()->getMobileNumber() == mobilePhoneNumber)
            {
                current -> phoneBookObj -> getPerson() -> getPhone()->setLandLineNumber(newLanldineNumber);

                return;
            }

            current = current->next;
        }
    }
}

void linkedList::deleteNode(std::string targetField, int opt)
{
    node *current = head;
    node *previous = nullptr;

    // If the head node itself holds the data to be deleted

    if(opt == 1) // the key we are looking after is the mobile
    {
        if (current != nullptr && current->phoneBookObj->getPerson()->getPhone()->getMobileNumber() == targetField)
        {
            head = current->next; // Changed the head of the list
            delete current;       // Free the left memory
            return;
        }

        // Search for the node to be deleted, keeping track of the previous node
        while (current != nullptr && current->phoneBookObj->getPerson()->getPhone()->getMobileNumber() != targetField)
        {
            previous = current;

            current = current->next;
        }
    }
    else
    {
        // the key we are looking after is the landline
        
        if (current != nullptr && current->phoneBookObj->getPerson()->getPhone()->getLandlineNumber() == targetField)
        {
            head = current->next; // Changed the head of the list
            delete current;       // Free the left memory
            return;
        }

        // Search for the node to be deleted, keeping track of the previous node
        while (current != nullptr && current->phoneBookObj->getPerson()->getPhone()->getLandlineNumber() != targetField)
        {
            previous = current;

            current = current->next;
        }
    }

    // If the node was not found
    if (current == nullptr)
        return;

    // Unlink the node from the linked list
    previous->next = current->next;

    // Free memory
    delete current;
}

void linkedList::saveData(const std::string& filename)
{
    std::ofstream file(filename);

    if (file.is_open())
    {
        node* current = head;

        while (current != nullptr)
        {
            // Extract the fields from the PhoneBook object
            std::string firstName = current -> phoneBookObj -> getPerson() -> getFirstName();

            std::string lastName = current -> phoneBookObj -> getPerson() -> getLastName();
            
            int age = current -> phoneBookObj -> getPerson() ->getAge();
            
            std::string street = current -> phoneBookObj -> getPerson() -> getAddress() -> getStreet();

            std::string city = current -> phoneBookObj -> getPerson() -> getAddress() -> getCity();

            std::string country = current -> phoneBookObj -> getPerson() -> getAddress() -> getCountry();

            int houseNumber = current -> phoneBookObj -> getPerson() -> getAddress() -> getHouseNumber();

            std::string mobile = current -> phoneBookObj -> getPerson() -> getPhone() -> getMobileNumber();

            std::string landline = current -> phoneBookObj -> getPerson() -> getPhone() -> getLandlineNumber();

            // Write the fields to the file in CSV format
            file << firstName << "," << lastName << "," << age << "," << street << "," << 
            city << "," << country << "," << houseNumber << "," << mobile << "," << landline << "\n";

            current = current -> next;
        }

        file.close();

        std::cout << "Data saved to file: " << filename << std::endl;
    }
    else
    {
        std::cerr << "Unable to open the file: " << filename << std::endl;
    }
}
