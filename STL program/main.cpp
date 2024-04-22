#include <iostream>

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