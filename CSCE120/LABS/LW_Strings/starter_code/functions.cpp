# include "functions.h"
# include <cstring> 
// add any includes

using std::cout, std::cin, std::endl, std::string;

void deobfuscate() 
{
    // TODO

}

void wordFilter() 
{
    // TODO
    

}

void passwordConverter() 
{
    // TODO
    std::string password;
    char letter;

    std::cout << "Please enter your text input: ";
    std::cin >> password;

    for(int i = 0; i < password.length(); i++)
    {
        letter = password.at(i);

        switch(letter)
        {
            case 'a':
                password.at(i) = '@';

            case 'e':
                password.at(i) = '3';

            case 'i':
                password.at(i) = '!';

            case 'o':
                password.at(i) = '0';

            case 'u':
                password.at(i) = '^';

            default:
                break;

        }

    }
    std::cout << password;
}

void wordCalculator() 
{
    // TODO
}

void palindromeCounter() 
{
    // TODO
}