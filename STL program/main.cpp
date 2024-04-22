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