#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "calculations.h"
#include "fileOps.h"

static void clearScreen(void)
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int menu(void)
{
    int option = 0;
    clearScreen();

    printf("=================================\n");
    printf("            MAIN MENU            \n");
    printf("=================================\n");
    printf("1. Calculation 1 (Addition)\n");
    printf("2. Calculation 2 (Multiplication)\n");
    printf("3. Write to File\n");
    printf("4. Read File\n");
    printf("5. Exit\n");
    printf("=================================\n");
    printf("Select an option (1-5): ");

    while (scanf("%d", &option) != 1 || option < 1 || option > 5)
    {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) { }
        printf("Invalid input. Enter a number 1-5: ");
    }

    return option;
}

void mainLoop(int option)
{
    switch (option)
    {
        case 1:
            firstCalculation();
            break;
        case 2:
            secondCalculation();
            break;
        case 3:
            writeFile();
            break;
        case 4:
            readFile();
            break;
        default:
            std::cout << "Unknown option." << std::endl;
            break;
    }

    std::cout << "\nPress Enter to continue...";
    std::cin.ignore();
    std::cin.get();
}
