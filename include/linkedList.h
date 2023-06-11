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

    // Function to print the list
    void printList();

    bool searchContactByLastName(std::string lastName);

    bool searchContactByFirstName(std::string firstName);

    bool searchContactByMobilePhoneNumber(std::string mobilePhoneNumber);

    bool searchContactByLandlineNumber(std::string landlineNumber);

    void updateFirstName(std::string mobilePhoneNumber, std::string firstName);

    void updateLastName(std::string mobilePhoneNumber, std::string lastName);

    void updateMobileNumber(std::string mobilePhoneNumber, std::string newMobileNumber);

    void updateLandlineNumber(std::string mobilePhoneNumber, std::string newLanldineNumber);

    void printSingleContact(std::string mobilePhoneNumber);

    void printGeneralContacts(std::string field, int opt);

    void deleteNode(std::string targetField, int opt);

    void saveData(const std::string& filename);

    friend void loadData(const std::string& filename);

    bool checkUniqueMobilePhoneNumber(const std::string& mobile);
};
