#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <climits>

// File path
static const char* FILE_PATH = "test.txt";

// =============================================
//              FUNCTION DECLARATIONS
// =============================================
void firstCalculation();
void secondCalculation();
void writeFile();
void readFile();
void mainLoop(int option);
static void clearScreen(void);
static int menu(void);

// =============================================
//              SCREEN CLEAR
// =============================================
static void clearScreen(void)
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// =============================================
//              MAIN MENU
// =============================================
static int menu(void)
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

// =============================================
//          CALCULATION 1 - ADDITION
// =============================================
void firstCalculation()
{
    int num1, num2, result;

    std::cout << "\n--- First Calculation (Addition) ---" << std::endl;
    std::cout << "Insert 2 numbers to add: ";
    std::cin >> num1 >> num2;

    result = num1 + num2;
    std::cout << "Addition: " << num1 << " + " << num2 << " = " << result << std::endl;

    std::ofstream fp(FILE_PATH, std::ios::app);
    if (fp.is_open()) {
        fp << "Addition: " << num1 << " + " << num2 << " = " << result << std::endl;
        fp.close();
        std::cout << "Result saved to file." << std::endl;
    } else {
        std::cout << "Could not save result to file." << std::endl;
    }
}

// =============================================
//       CALCULATION 2 - MULTIPLICATION
// =============================================
void secondCalculation()
{
    long long num1, num2, result;
    std::cout << "\n--- Second Calculation (Multiplication) ---" << std::endl;
    std::cout << "Insert 2 numbers to multiply: ";
    std::cin >> num1 >> num2;

    // Check if either number exceeds 1,000,000
    bool isLarge = (num1 > 1000000 || num1 < -1000000 || num2 > 1000000 || num2 < -1000000);

    if (isLarge)
    {
        // Check for overflow before multiplying using LLONG_MAX from <climits>
        if (num2 != 0 && (num1 > LLONG_MAX / num2 || num1 < LLONG_MIN / num2))
        {
            std::cout << "Warning: Overflow detected! Numbers are too large to multiply safely." << std::endl;
            std::cout << "Max safe value: " << LLONG_MAX << std::endl;
            return;
        }
        std::cout << "Note: Large numbers detected, using 64-bit precision." << std::endl;
    }

    result = num1 * num2;
    std::cout << "Multiply: " << num1 << " and " << num2 << std::endl;
    std::cout << "Result: " << result << std::endl;
}

// =============================================
//              WRITE TO FILE
// =============================================
void writeFile()
{
    std::ofstream fp(FILE_PATH, std::ios::app);

    if (!fp.is_open()) {
        std::cout << "Error opening file for writing..." << std::endl;
        return;
    }

    std::string line;
    std::cin.ignore();

    std::cout << "\n--- Write to File ---" << std::endl;
    std::cout << "Enter line 1: ";
    std::getline(std::cin, line);
    fp << line << std::endl;

    std::cout << "Enter line 2: ";
    std::getline(std::cin, line);
    fp << line << std::endl;

    fp.close();
    std::cout << "\nYour text has been saved to: " << FILE_PATH << std::endl;
}

// =============================================
//              READ FROM FILE
// =============================================
void readFile()
{
    std::ifstream fp(FILE_PATH);

    if (!fp.is_open()) {
        std::cout << "Error opening file for reading..." << std::endl;
        return;
    }

    std::string buff;
    int lineCount = 1;

    std::cout << "\n--- File Contents ---" << std::endl;

    while (std::getline(fp, buff))
    {
        std::cout << lineCount << " : " << buff << std::endl;
        lineCount++;
    }

    if (lineCount == 1) {
        std::cout << "File is empty." << std::endl;
    }

    fp.close();
}

// =============================================
//         MAIN LOOP - ROUTES OPTIONS
// =============================================
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

// =============================================
//                   MAIN
// =============================================
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

    printf("Exiting program...\n");
    return 0;
}

