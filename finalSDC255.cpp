#include <iostream>
#include <fstream>
#include <string>

void writeFile() {
    // open file in write mode using ofstream
    std::ofstream fp("D:\\ECPI\\codes\\FinalSDC255\\test.txt");

    // checking if file opened correctly, if not print error and stop
    if (!fp.is_open()) {
        std::cout << "Error opening file..." << std::endl;
        return;
    }

    // write to file using << operator
    fp << "This is testing fprintf..." << std::endl;
    fp << "This is testing for fputs..." << std::endl;

    // close file after writing
    fp.close();
    std::cout << "File has been written..." << std::endl;
}

void readFile() {
    // open file in read mode using ifstream
    std::ifstream fp("D:\\ECPI\\codes\\FinalSDC255\\test.txt");

    // checking if file opened correctly, if not print error and stop
    if (!fp.is_open()) {
        std::cout << "Error opening file..." << std::endl;
        return;
    }

    std::string buff;

    // read first word from line 1
    fp >> buff;
    std::cout << "1 : " << buff << std::endl;

    // read the rest of line 1
    std::getline(fp, buff);
    std::cout << "2 : " << buff << std::endl;

    // read all of line 2
    std::getline(fp, buff);
    std::cout << "3 : " << buff << std::endl;

    // close file
    fp.close();
}

int main() {
    writeFile();

    readFile();

    std::cout << "Press enter to exit";
    std::cin.get();

    return 0;
}
