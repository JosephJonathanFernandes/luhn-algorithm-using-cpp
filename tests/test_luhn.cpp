#include "luhn.hpp"
#include <iostream>
#include <cassert>
#include <vector>

void testSanitizeInput() {
    std::cout << "Running testSanitizeInput... ";
    assert(Luhn::sanitizeInput("1234") == "1234");
    assert(Luhn::sanitizeInput("1234-5678") == "12345678");
    assert(Luhn::sanitizeInput("1234 5678") == "12345678");
    assert(Luhn::sanitizeInput("  1234  ") == "1234");
    
    try {
        Luhn::sanitizeInput("1234a5678");
        assert(false && "Should have thrown invalid_argument");
    } catch (const std::invalid_argument&) {
        // Expected
    }
    std::cout << "PASSED\n";
}

void testLuhnCheck() {
    std::cout << "Running testLuhnCheck... ";
    // Valid numbers
    assert(Luhn::isValid("4539148803436467") == true);
    assert(Luhn::isValid("79927398713") == true);
    
    // Invalid numbers
    assert(Luhn::isValid("4539148803436468") == false); // Last digit changed
    assert(Luhn::isValid("1234567812345678") == false);
    std::cout << "PASSED\n";
}

int main() {
    std::cout << "Starting Unit Tests...\n";
    testSanitizeInput();
    testLuhnCheck();
    std::cout << "All tests passed successfully!\n";
    return 0;
}
