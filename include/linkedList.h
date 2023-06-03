#pragma once
#include <iostream>
#include "PhoneBook.h"

typedef struct _node
{
    PhoneBook *phoneBookObj;

    struct _node *next;
} node;

class linkedList
{
private:
    node *head;

public:
    // Constructor
    linkedList();

    // Destructor
    ~linkedList()
    {
        deleteList();
    }

    // Function to add a new node at the end of the list
    void addNode(PhoneBook *data);

    // Function to delete the entire list
    void deleteList();

    // // Function to search for a given value in the list
    // bool search(int value)
    // {
    //     node *current = head;
    //     while (current != nullptr)
    //     {
    //         if (current->data == value)
    //         {
    //             return true;
    //         }
    //         current = current->next;
    //     }
    //     return false;
    // }

    // Function to print the list
    void printList();

    bool searchContactByLastName(std::string lastName);

    bool searchContactByFirstName(std::string firstName);

    bool searchContactByMobilePhoneNumber(std::string mobilePhoneNumber);

    bool searchContactByLandlineNumber(std::string landlineNumber);
};
