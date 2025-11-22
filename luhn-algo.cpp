#include <iostream>   // This lets us use input/output like cout and cin
#include <string>     // This lets us use the string data type
using namespace std;

// ---------------------- LUHN ALGORITHM FUNCTION ----------------------
// This function checks if a card number is valid or not using the Luhn algorithm.
// It expects that the string 'card' contains ONLY digits (0–9).
bool luhnCheck(const string &card) {
    int sum = 0;               // This will store the total sum of processed digits
    bool doubleDigit = false;  // This will tell us whether to double the current digit or not

    // We start checking from the RIGHTMOST digit and move LEFT
    // Example: for "1234", we start with '4', then '3', then '2', then '1'
    for (int i = card.size() - 1; i >= 0; --i) {
        // Convert character digit like '3' to actual integer 3
        int d = card[i] - '0';

        // According to Luhn algorithm: every second digit from the right must be doubled
        if (doubleDigit) {
            d = d * 2;    // Double the digit

            // If the result is greater than 9 (like 12, 14, 16),
            // we subtract 9. This is same as adding the individual digits.
            // Example: 16 → 1 + 6 = 7, which is equal to 16 - 9 = 7
            if (d > 9)
                d = d - 9;
        }

        // Add the processed digit to the total sum
        sum += d;

        // Flip the doubleDigit flag:
        // - If it was false, it becomes true
        // - If it was true, it becomes false
        //
        // This way, we double every alternate digit.
        doubleDigit = !doubleDigit;
    }

    // After processing all digits:
    // If the total sum is divisible by 10 (sum % 10 == 0),
    // then the card number passes the Luhn check and is considered valid.
    return (sum % 10 == 0);
}

// ---------------------- MAIN FUNCTION (PROGRAM STARTS HERE) ----------------------
int main() {
    string card;

    // Ask the user to enter the card number.
    // User can type with spaces or hyphens, like:
    // "4539 1488 0343 6467" or "4539-1488-0343-6467"
    cout << "Enter card number: ";
    getline(cin, card);   // getline reads the entire line, including spaces

    // We will create a new string that contains only digits (0–9).
    // We will IGNORE spaces and hyphens so that the user can type in a readable format.
    string clean = "";

    // Go through every character the user typed
    for (char c : card) {
        if (c == ' ' || c == '-') {
            // If the character is a space or a hyphen:
            // We simply skip it and do not add it to 'clean'.
            // This allows input like "1234 5678" or "1234-5678".
            continue;
        } else if (isdigit(c)) {
            // If the character is a digit (0–9), we keep it.
            clean += c;
        } else {
            // If the character is anything else (like a letter or symbol),
            // we consider the input invalid because card numbers should not contain those.
            cout << "Invalid character in input. Use only digits, spaces, or -.\n";
            return 0;  // End the program early because input is not proper
        }
    }

    // If after cleaning, there are no digits at all,
    // it means the user didn't really enter a proper number.
    if (clean.empty()) {
        cout << "No number entered.\n";
        return 0;  // End the program
    }

    // Now we have a clean string that contains only digits.
    // Example: user typed "4539 1488-0343 6467"
    // clean will become "4539148803436467"

    // We now pass this clean number to our Luhn check function.
    if (luhnCheck(clean))
        // If Luhn check returns true, we say it's a valid card number.
        cout << "Valid card number ✅\n";
    else
        // Otherwise, it's not valid according to the algorithm.
        cout << "Invalid card number ❌\n";

    return 0;  // Program ends successfully
}
