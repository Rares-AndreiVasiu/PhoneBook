#pragma once

#include "Person.h"

class PhoneBook
{
private:
    int index;

    static int totalContacts;

    Person* person;
public:
    PhoneBook(int ct, Person* p): index(ct), person(p)
    {
        totalContacts += ct;
    }

    int getIndex()
    {
        return index;
    }

    Person *getPerson() const
    {
        return person;
    }

    static int getTotalContacts();

    void printContactWithFilters(int option);
};
