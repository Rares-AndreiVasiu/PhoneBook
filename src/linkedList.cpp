#include <limits>
#include <string>

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
            index ++;
            
            std::cout << "Index: " << index << std::endl;

            std::cout << "Person: " << current->phoneBookObj->getPerson()->getFirstName() << " " << current->phoneBookObj->getPerson()->getLastName() << std::endl;

            std::cout << "Age: " << current->phoneBookObj->getPerson()->getAge() << std::endl;

            std::cout << "Mobile Phone: " << current->phoneBookObj->getPerson()->getPhone()->getMobileNumber() << std::endl;

            std::cout << "Landline Phone: " << current->phoneBookObj->getPerson()->getPhone()->getLandlineNumber() << std::endl;

            std::cout << "Address: " << std::endl;

            std::cout << "Street: " << current->phoneBookObj->getPerson()->getAddress()->getStreet() << std::endl;

            std::cout << "City: " << current->phoneBookObj->getPerson()->getAddress()->getCity() << std::endl;

            std::cout << "Country: " << current->phoneBookObj->getPerson()->getAddress()->getCountry() << std::endl;

            std::cout << "House Number: " << current->phoneBookObj->getPerson()->getAddress()->getHouseNumber() << std::endl;
            
            current = current->next;
        }
        std::cout << std::endl;
    }
}