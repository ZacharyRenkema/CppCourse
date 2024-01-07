#include <iostream>

int main()
{
    std::string name;

    std::cout << "Enter your name ";
    std::getline(std::cin,name);

    if(name.length() > 24){ //.length() measures the length of the string
        std::cout << "Your name cannot be over 12 characters ";
    }
    else{
        std::cout << "Welcome " << name;
    }

    name.append("@gmail.com"); //appends string variable
    std::cout << " Your username is now " << name;

    //name.empty() Returns boolean value if string is empty
    //name.clear() Clears the string
    //name.at(n) Returns the character at a specified index (Remember [0] is the start of string) 
    //name.insert(n) Inserts a character at specified index (Remember [0] is the start of string)
    //name.find('(Thing you want to find)') This finds a specific thing in your string. Example name.find(' ') <- This finds a space.
    //name.erase(i,f)) This erases a portion of a string i = initial f = final



    
    return 0;
}