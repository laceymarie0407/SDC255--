#include <stdio.h>
#include "menu.h"
#include "mainLoop.h"   // Broderick’s file (FP-6)

int main(void)
{
    int option;

    do
    {
        option = menu();          // get user selection

        if (option != 5)          // 5 = Exit
        {
            mainLoop(option);     // route to correct module
        }

    } while (option != 5);

    printf("Exiting program...\n");
    return 0;
}
