#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <stdlib.h>

/* Clears screen before showing the 5 menu options */
static void clearScreen(void)
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

/* FP-1: Menu must return an integer and show 5 options */
static int menu(void)
{
    int option = 0;

    clearScreen();

    printf("=================================\n");
    printf("            MAIN MENU            \n");
    printf("=================================\n");
    printf("1. Calculation 1\n");
    printf("2. Calculation 2\n");
    printf("3. Write to File\n");
    printf("4. Read File\n");
    printf("5. Exit\n");
    printf("=================================\n");
    printf("Select an option (1-5): ");

    /* Validate input: must be an integer from 1 to 5 */
    while (scanf("%d", &option) != 1 || option < 1 || option > 5)
    {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) { }  // clear bad input
        printf("Invalid input. Enter a number 1-5: ");
    }

    return option;
}

#endif
