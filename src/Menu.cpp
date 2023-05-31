#include "Menu.h"
#include "utils.h"

void Menu()
{
    // clearConsole();

    std::cout << "=== Phone Book simulator ===" << '\n';

    std::cout << "Add a contact: press 1" << '\n';

    std::cout << "Update a contact: press 2" << '\n';

    std::cout << "Delete a contact: press 3" << '\n';

    std::cout << "Search for contact: press 4" << '\n';

    std::cout << "Print contacts: press 5" << '\n';

    std::cout << "Exit programm: press 6" << '\n';

    std::cout << "Your choice: ";
}

void AddContactMenu()
{
    clearConsole();
 
    std::cout << "--- Here we add the contact ---" << '\n';
}

void UpdateContactMenu()
{
    clearConsole();

    std::cout << "Update first name: press 1" << '\n';

    std::cout << "Update last name: press 2" << '\n';

    std::cout << "Update mobile phone number: press 3" << '\n';

    std::cout << "Update landline number: press 4" << '\n';

    std::cout << "Update address: press 5" << '\n';
}

void DeleteContactMenu()
{
    clearConsole();

    std::cout << "Now we are going to delete a contact." << '\n';

    std::cout << "Choose between the mobile phone number or the landline number" << '\n';

    std::cout << "Mobile phone number: press 1" << '\n';

    std::cout << "Landline number: press 2" << '\n';
}

void SearchContactMenu()
{
    clearConsole();

    std::cout << "Search by last name: press 1" << '\n';

    std::cout << "Search by first name: press 2" << '\n';

    std::cout << "Search by mobile phone number: press 3" << '\n';

    std::cout << "Search by landline number: press 4" << '\n';

    std::cout << "Search by address: press 5" << '\n';
}

void exitProgram()
{
    std::cout << "Exiting program..." << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(2));
    
    std::exit(0);
}
