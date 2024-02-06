/*
#include <iostream>

void printDigits(int number) {
    while (number > 0) {
        int digit = number % 10;  // Extract the current digit
        std::cout << digit << " ";  // Print the current digit
        number /= 10;  // Remove the current digit
    }

    std::cout << std::endl;  // Print a newline after all digits are printed
}

bool compareDigits(int number) {
    int previousDigit = number % 10;  // Extract the last digit
    number /= 10;  // Remove the last digit

    while (number > 0) {
        int currentDigit = number % 10;  // Extract the current digit
        std::cout << "Comparing " << currentDigit << " with " << previousDigit << std::endl;

        if (currentDigit == previousDigit) {
            // Digits are equal, return true
            return true;
        }

        previousDigit = currentDigit;  // Update the previous digit for the next iteration
        number /= 10;  // Remove the current digit
    }

    // No equal adjacent digits found, return false
    return false;
}

int main() {
    // Example usage
    int inputNumber;
    std::cout << "Enter an integer: ";
    std::cin >> inputNumber;

    std::cout << "Digits in the integer: ";
    printDigits(inputNumber);

    if (compareDigits(inputNumber)) {
        std::cout << "The integer has at least one pair of adjacent equal digits.\n";
    } else {
        std::cout << "No pair of adjacent equal digits found in the integer.\n";
    }

    return 0;
}
*/