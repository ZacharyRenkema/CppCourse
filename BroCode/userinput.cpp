#include <iostream>

//cout << (inserstion operator)
//cin >> (extraction operator)
using strings = std::string;

int main() 
{
    strings name;
    int age;

    std::cout << " What is your age? ";
    std::cin >> age; //This stores the user input into variable age.

    std::cout << "What is your full name? ";
    std::getline(std::cin >> std::ws, name); //This stores the user input into variable name. Getline function allows for spaces.
    std::cout << "Hello " << name << '\n';
    
    //std::cout << " What is your age? ";
    //std::cin >> age; //This stores the user input into variable age.
    std::cout << "You are " << age << " years old!" << '\n';

    return 0;
}

/*
Note)
    cin gives a '\n' (newline), thus if we follow std::cin with a getline(), then the getline()
    is inputed with the '\n' character thus not allowing for input.

    In order to avoid this within the getline(), include this: 
    std::getline(std::cin >> std::ws, name);

    ws - Gets ride of white spaces
*/