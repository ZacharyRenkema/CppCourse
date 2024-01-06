#include <iostream>

int main() {
    int x; //declaration step
    x = 5;
    int y = 10;

//Calculating Variables
    int sum = x + y;

//Outputing variables
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << sum << '\n';

//Integers
    int age = 21;
    int year = 2023;
    int value = 7.5;

    std::cout << value << std::endl; //Gives truncated value of 7.5

//Doubles
    double price = 10.99;
    double gpa = 4.0;

//Single Characters
    char grade = 'A';
    char initial = 'B';

    std::cout << initial << std::endl;
/*
char can ONLY store a single character. Having multiple will result in an "overflow error"
    Example) char value = 'BC'
*/

//Boolean (True or False)
    bool student = true;
    bool studentTwo = false;

//String (Objects of a sequence of characters[Use ""])
    std::string name = "Zachary Renkema";
    std::cout << name << '\n';

    std::cout << "Hello " << name << '\n'; //This is defined as a string literal. Literally printing a string of text
    std::cout << "You are " << age << " years old!" << '\n';
    return 0; 
}