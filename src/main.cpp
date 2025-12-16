#include "luhn.hpp"
#include <iostream>
#include <string>

int main() {
    std::string rawInput;

    std::cout << "========================================\n";
    std::cout << "      Luhn Algorithm Validator          \n";
    std::cout << "========================================\n";
    std::cout << "Enter card number (spaces/dashes allowed): ";
    
    if (!std::getline(std::cin, rawInput)) {
        std::cerr << "Error reading input.\n";
        return 1;
    }

    try {
        std::string cleanNumber = Luhn::sanitizeInput(rawInput);

        if (cleanNumber.empty()) {
            std::cout << "Error: No digits entered.\n";
            return 1;
        }

        if (Luhn::isValid(cleanNumber)) {
            std::cout << "\nResult: Valid card number \xE2\x9C\x85\n"; // Check mark
        } else {
            std::cout << "\nResult: Invalid card number \xE2\x9D\x8C\n"; // Cross mark
        }

    } catch (const std::exception& e) {
        std::cerr << "\nError: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
