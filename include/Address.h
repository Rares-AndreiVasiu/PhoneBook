#pragma once

class Address
{
private:
    std::string street;
    
    std::string city;

    std::string country;

    int houseNumber;

public:
    Address(const std::string& str, const std::string& ct, const std::string& ctr, 
    int houseNum) :street(str), city(ct), country(ctr), houseNumber(houseNum)
    {

    }

    std::string getStreet() const;

    std::string getCity() const;

    std::string getCountry() const;

    int getHouseNumber() const;
};
