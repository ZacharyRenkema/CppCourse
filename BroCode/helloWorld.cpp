#include <iostream>
#include <string>

// Use "//" to comment

/*
   Use this to make a multiline comment
*/

int main(){
    std::cout << "Hello World!" << std::endl;
    std:: cout << "What is your name?: "; 
    std::string name;
    std::cin >> name;
    name.append("balls");
    std::cout << "Hello " << name << "!" << std::endl;
    std::cout << "Yo!" << std::endl;
    std::cout << "Balls!" << "\n";

    return 0;
}
