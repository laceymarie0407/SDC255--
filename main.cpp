#include <iostream>
#include "menu.h"

int main(void)
{
    int option;

    do
    {
        option = menu();

        if (option != 5)
        {
            mainLoop(option);
        }

    } while (option != 5);

    std::cout << "Exiting program..." << std::endl;
    return 0;
}

