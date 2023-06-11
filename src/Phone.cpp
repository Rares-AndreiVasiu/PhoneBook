#include <string>
#include <iostream>

#include "Phone.h"

std::string Phone::getMobileNumber() const
{
    return mobileNumber;
}

std::string Phone::getLandlineNumber() const
{
    return landlineNumber;
}

void Phone::setMobileNumber(std::string mobile)
{
    this -> mobileNumber = mobile;
}

void Phone::setLandLineNumber(std::string landline)
{
    this ->landlineNumber = landline;
}

void Phone::printPhone()
{
    std::cout << "Mobile phone number: " <<  this->mobileNumber << '\n';

    std::cout << "Landline number: " << this->landlineNumber << '\n';
}

