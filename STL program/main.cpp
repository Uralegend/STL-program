#include <iostream>
#include <cctype>  // Required for isalpha and toupper functions
// Define custom exceptions
class InvalidCharacterException : public std::exception {
    virtual const char* what() const throw() {
        return "Invalid character provided";
    }
};

class InvalidRangeException : public std::exception {
    virtual const char* what() const throw() {
        return "Invalid offset range provided";
    }
};
// Function to calculate character based on start and offset
char character(char start, int offset) {
    // Check if start is a letter
    if (!isalpha(start)) {
        throw InvalidCharacterException();
    }
    // Convert start to uppercase to simplify calculations
    start = toupper(start);

    // Check if offset is within the range of letters
    if (!isalpha(start + offset)) {
        throw InvalidRangeException();
    }

    // Calculate the character based on start and offset
    char result = start + offset;
    return result;
}
int main() {
    try {
        // Test cases
        std::cout << "Test Case 1: ";
        std::cout << "Character: " << character('A', 3) << std::endl;

        std::cout << "Test Case 2: ";
        std::cout << "Character: " << character('z', -1) << std::endl;

        std::cout << "Test Case 3: ";
        std::cout << "Character: " << character('x', 5) << std::endl;

        std::cout << "Test Case 4: ";
        std::cout << "Character: " << character('1', 2) << std::endl;  // Invalid start character
    }
    catch (InvalidCharacterException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (InvalidRangeException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}