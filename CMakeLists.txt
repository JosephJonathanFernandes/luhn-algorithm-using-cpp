cmake_minimum_required(VERSION 3.10)

# Project metadata
project(LuhnValidator
    VERSION 1.1.0
    DESCRIPTION "A C++ implementation of the Luhn Algorithm"
    LANGUAGES CXX
)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Create a library for the Luhn algorithm logic
add_library(luhn_lib src/luhn.cpp)

# Add the main executable
add_executable(luhn_validator src/main.cpp)
target_link_libraries(luhn_validator PRIVATE luhn_lib)

# Add the test executable
enable_testing()
add_executable(run_tests tests/test_luhn.cpp)
target_link_libraries(run_tests PRIVATE luhn_lib)

# Register the test
add_test(NAME UnitTests COMMAND run_tests)

# Enable compiler warnings for better code quality
if(MSVC)
    target_compile_options(luhn_lib PRIVATE /W4)
    target_compile_options(luhn_validator PRIVATE /W4)
    target_compile_options(run_tests PRIVATE /W4)
else()
    target_compile_options(luhn_lib PRIVATE -Wall -Wextra -Wpedantic)
    target_compile_options(luhn_validator PRIVATE -Wall -Wextra -Wpedantic)
    target_compile_options(run_tests PRIVATE -Wall -Wextra -Wpedantic)
endif()
