#ifndef LUHN_ALGO_HPP
#define LUHN_ALGO_HPP

#include <string>

namespace Luhn {

    /**
     * @brief Sanitizes the input string by removing spaces and hyphens.
     * 
     * @param input The raw input string.
     * @return std::string A string containing only digits.
     * @throws std::invalid_argument if input contains non-digit characters (excluding spaces/hyphens).
     */
    std::string sanitizeInput(const std::string& input);

    /**
     * @brief Validates a number string using the Luhn algorithm.
     * 
     * @param number The string of digits to validate.
     * @return true If the number is valid.
     * @return false Otherwise.
     */
    bool isValid(const std::string& number);

} // namespace Luhn

#endif // LUHN_ALGO_HPP
