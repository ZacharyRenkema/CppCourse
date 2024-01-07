#include <iostream>

int main()
{
    std::string name;

    while(name.empty()) { //While loop will continously repeat until name is entered.
        std::cout << "Please enter your name ";
        std::getline(std::cin, name);

    }

    std::cout << "Hello " << name;
    //Beware infinite loops

}