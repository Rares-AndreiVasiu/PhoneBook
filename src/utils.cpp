#include "utils.h"
#include <string>

bool checkName(const std::string& name)
{
    for (char c : name)
    {
        if (!isalpha(c) && c != ' ' && c != '-' && c != '\'')
        {
            return false;
        }
    }
    return true;
}

bool checkMenuOption(const int opt, int startValue, int endValue)
{
    return (opt >= startValue && opt <= endValue);
}


bool checkMobilePhone(const std::string& mobileNumber)
{
    std::regex pattern(R"(^(?:(?:\+|00)40|07)\d{8}$)");
    
    return std::regex_match(mobileNumber, pattern);
}

bool checkLandlineNumber(const std::string& landlineNumber)
{
    std::regex pattern(R"(^(?:00|01[1-9]|02[1-9]|023|031|05[1-9]|055
    |058|059|06[1-9]|07[1-9]|081|09[1-9])\d{7}$)");
    
    return std::regex_match(landlineNumber, pattern);
}

bool checkNumber(int n)
{
    return n > 0;
}
    
bool checkCountryName(const std::string& country)
{
    std::regex pattern(R"(^(?!-)(?!.*--)[A-Za-z\s'\-]+$)");
    
    return std::regex_match(country, pattern);
}

void clearConsole()
{
    system("clear");
}

