#include "luhn.hpp"
#include <algorithm>
#include <cctype>
#include <stdexcept>

namespace Luhn {

    std::string sanitizeInput(const std::string& input) {
        std::string clean;
        clean.reserve(input.size());

        for (char c : input) {
            if (std::isspace(c) || c == '-') {
                continue;
            } else if (std::isdigit(c)) {
                clean += c;
            } else {
                throw std::invalid_argument("Input contains invalid characters. Only digits, spaces, and hyphens are allowed.");
            }
        }
        return clean;
    }

    bool isValid(const std::string& number) {
        int sum = 0;
        bool doubleDigit = false;

        for (int i = number.size() - 1; i >= 0; --i) {
            int digit = number[i] - '0';

            if (doubleDigit) {
                digit *= 2;
                if (digit > 9) {
                    digit -= 9;
                }
            }

            sum += digit;
            doubleDigit = !doubleDigit;
        }

        return (sum % 10 == 0);
    }

} // namespace Luhn
