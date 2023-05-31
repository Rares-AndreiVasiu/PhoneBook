#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <regex>
#include <limits>

bool checkName(const std::string& name);

bool checkMenuOption(const int opt, int startValue, int endValue);

bool checkMobilePhone(const std::string& mobileNumber);

bool checkLandlineNumber(const std::string& landlineNumber);

bool checkHouseNumber(int n);

bool checkCountryName(const std::string& country);

bool checkNumber(int n);

void clearConsole();
