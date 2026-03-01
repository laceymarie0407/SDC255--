#include <iostream>
#include <fstream>
#include <string>
#include "fileOps.h"

static const char* FILE_PATH = "test.txt";

void writeFile()
{
    std::ofstream fp(FILE_PATH, std::ios::app);

    if (!fp.is_open()) {
        std::cout << "Error opening file..." << std::endl;
        return;
    }

    std::string line;
    std::cin.ignore();

    std::cout << "\nEnter line 1: ";
    std::getline(std::cin, line);
    fp << line << std::endl;

    std::cout << "Enter line 2: ";
    std::getline(std::cin, line);
    fp << line << std::endl;

    fp.close();
}

void readFile()
{
    std::ifstream fp(FILE_PATH);

    if (!fp.is_open()) {
        std::cout << "Error opening file..." << std::endl;
        return;
    }

    std::string buff;
    while (std::getline(fp, buff))
    {
        std::cout << buff << std::endl;
    }

    fp.close();
}
