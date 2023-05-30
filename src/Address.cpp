#include "Address.h"

// address related functions
std::string Address::getStreet() const
{
    return street;
}

std::string Address::getCity() const
{
    return city;
}

std::string Address::getCountry() const
{
    return country;
}

int Address::getHouseNumber() const
{
    return houseNumber;
}
