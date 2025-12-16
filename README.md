# Luhn Algorithm Validator (C++)

![Build Status](https://github.com/yourusername/luhn-algorithm-using-cpp/actions/workflows/cmake.yml/badge.svg)

A professional, robust implementation of the Luhn Algorithm (also known as the "modulus 10" or "mod 10" algorithm) in C++. This utility validates identification numbers such as credit card numbers, IMEI numbers, and Canadian Social Insurance Numbers.

## 📖 About the Algorithm

The Luhn algorithm is a simple checksum formula used to validate a variety of identification numbers. It is not intended to be a cryptographically secure hash function; it was designed to protect against accidental errors, such as a digit mistype.

**How it works:**
1.  Starting from the rightmost digit (check digit) and moving left, double the value of every second digit.
2.  If the result of this doubling operation is greater than 9 (e.g., 8 × 2 = 16), then add the digits of the product (e.g., 16: 1 + 6 = 7, or equivalently 16 - 9 = 7).
3.  Take the sum of all the digits.
4.  If the total modulo 10 is equal to 0 (if the total ends in zero), then the number is valid according to the Luhn formula; else it is not valid.

## 🚀 Features

*   **Modular Design:** Separated logic (`src/luhn.cpp`) from interface (`include/luhn.hpp`) and entry point (`src/main.cpp`).
*   **Input Sanitization:** Automatically ignores spaces and hyphens for user-friendly input.
*   **Validation:** Checks for non-numeric characters to prevent errors.
*   **Unit Tests:** Includes a test suite to verify correctness.
*   **CI/CD Ready:** GitHub Actions workflow included for automated building and testing.
*   **Cross-Platform:** Standard C++11 compliant code.

## 📂 Project Structure

```
.
├── include/
│   └── luhn.hpp        # Header file
├── src/
│   ├── luhn.cpp        # Implementation
│   └── main.cpp        # Main entry point
├── tests/
│   └── test_luhn.cpp   # Unit tests
├── CMakeLists.txt      # Build configuration
└── README.md
```

## 🛠️ Build Instructions

### Prerequisites
*   A C++ compiler (GCC, Clang, MSVC)
*   CMake (version 3.10 or higher)

### Building with CMake

1.  Create a build directory:
    ```bash
    mkdir build
    cd build
    ```

2.  Configure the project:
    ```bash
    cmake ..
    ```

3.  Build the project:
    ```bash
    cmake --build .
    ```

4.  Run the application:
    ```bash
    ./luhn_validator
    # On Windows: .\Debug\luhn_validator.exe
    ```

## 🧪 Running Tests

After building the project (see above), you can run the unit tests:

```bash
ctest --output-on-failure
# Or run the test executable directly:
./run_tests
```

## 📝 Usage Example

```text
Enter card number: 4539-1488-0343-6467
Valid card number ✅
```

```text
Enter card number: 1234 5678 1234 5678
Invalid card number ❌
```

## 🤝 Contributing

Contributions, issues, and feature requests are welcome!
Feel free to check the [issues page](../../issues).

## 📝 License

This project is open source and available under the [MIT License](LICENSE).
