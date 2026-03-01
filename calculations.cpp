#include <iostream>
#include <fstream>
#include <climits>
#include "calculations.h"

static const char* FILE_PATH = "test.txt";

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

void secondCalculation()
{
    long long num1, num2, result;
    std::cout << "\n--- Second Calculation (Multiplication) ---" << std::endl;
    std::cout << "Insert 2 numbers to multiply: ";
    std::cin >> num1 >> num2;

    bool isLarge = (num1 > 1000000 || num1 < -1000000 || num2 > 1000000 || num2 < -1000000);

    if (isLarge)
    {
        if (num2 != 0 && (num1 > LLONG_MAX / num2 || num1 < LLONG_MIN / num2))
        {
            std::cout << "Warning: Overflow detected!" << std::endl;
            return;
        }
    }

    result = num1 * num2;
    std::cout << "Result: " << result << std::endl;
}
