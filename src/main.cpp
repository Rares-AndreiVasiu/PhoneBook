#include "utils.h"
#include "Address.h"
#include "Menu.h"
#include "Person.h"
#include "Phone.h"
#include "PhoneBook.h"
#include "handler.h"

int main()
{
    while(true)
    {
        Menu();

        int opt;

        std::cin >> opt;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if(!checkMenuOption(opt, 1, 6))
        {
            clearConsole();
        }
        else
        {
            handle(opt);
        }
    }

    return 0;
}
