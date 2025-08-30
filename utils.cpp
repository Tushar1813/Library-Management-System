#include "utils.h"
#include <iostream>
int getIntInput(const std::string& prompt) {
    int value;
    std::cout << prompt;
    std::cin >> value;
    return value;
}
std::string getStringInput(const std::string& prompt) {
    std::string value;
    std::cout << prompt;
    std::cin.ignore();
    std::getline(std::cin, value);
    return value;
}
