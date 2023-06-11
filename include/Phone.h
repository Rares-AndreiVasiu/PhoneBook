#pragma once

class Phone
{
private:
    std::string mobileNumber;
    std::string landlineNumber;

public:
    Phone(const std::string& mobile, const std::string landline) : 
    mobileNumber(mobile), landlineNumber(landline)
    {

    }

    void setMobileNumber(std::string mobile);

    void setLandLineNumber(std::string landline);

    std::string getMobileNumber() const;

    std::string getLandlineNumber() const;

    void printPhone();
};
