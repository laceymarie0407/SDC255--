#include <stdio.h>



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
    int num1, num2, result;

    std::cout << "\n--- Second Calculation (Multiplication) ---" << std::endl;
    std::cout << "Insert 2 numbers to multiply: ";
    std::cin >> num1 >> num2;

    result = num1 * num2;
    std::cout << "Multiply: " << num1 << " x " << num2 << " = " << result << std::endl;

    std::ofstream fp(FILE_PATH, std::ios::app);
    if (fp.is_open()) {
        fp << "Multiply: " << num1 << " x " << num2 << " = " << result << std::endl;
        fp.close();
        std::cout << "Result saved to file." << std::endl;
    } else {
        std::cout << "Could not save result to file." << std::endl;
    }
}













