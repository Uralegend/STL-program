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

    // Calculate new character code considering the offset
    char result = start + offset;

    // Check if the result is a letter
    if (!isalpha(result)) {
        throw InvalidRangeException();
    }
return result;
}

int main() {
    try {
        // Test cases
        std::cout << "Test Case 1: Character: " << character('A', 3) << std::endl;  // Output should be 'D'
        std::cout << "Test Case 2: Character: " << character('z', -1) << std::endl; // Output should be 'y'
        std::cout << "Test Case 3: Character: " << character('x', 5) << std::endl;  // Should throw InvalidRangeException

        // This will trigger the InvalidCharacterException
        std::cout << "Test Case 4: Character: " << character('1', 2) << std::endl;
    }
    catch (InvalidCharacterException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (InvalidRangeException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (std::exception& e) {
        // Generic catch block for catching any other unhandled exceptions
        std::cerr << "Unhandled Exception: " << e.what() << std::endl;
    }


    return 0;
}