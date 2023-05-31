#include <string>
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

