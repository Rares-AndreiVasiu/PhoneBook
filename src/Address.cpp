#include <string>
#include <iostream>
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

void Address::printAddress()
{
    std::cout << "Street: " << this->street << '\n';

    std::cout << "City: " << this->city << '\n';

    std::cout << "Country: " << this->country << '\n';

    std::cout << "House number: " << this->houseNumber << '\n';
}