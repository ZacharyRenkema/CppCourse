#include "functions.h"
#include <string>
#include <iostream>

using std::cout, std::cin, std::endl, std::string;

void deobfuscate() 
{
    // TODO
    std::string sentence;
    int details;

    std::cout << "Please enter obfuscated sentence: " << std::endl;
    std::getline(std::cin, sentence);

    std::cout << "Please enter deobfuscation details: " << std::endl;
    std::cin >> details;



}

void wordFilter() 
{
    std::string sentence;
    std::string filter;

    std::cout << "Please enter the sentence: ";
    std::getline(std::cin, sentence);

    std::cout << "Please enter the filter word: ";
    std::cin >> filter;

    sentence.resize(sentence.length());

    for (size_t i = 0; i < sentence.length(); ++i) 
    {
        size_t found = sentence.find(filter, i); 

        if (found != std::string::npos) 
        {
            for (int j = found; j < (found + filter.length()); ++j) 
            {
                sentence.at(j) = '#';
            }
            i = found + filter.length() - 1; 
        }
        //std::cout << sentence.length() << endl;
    }

    std::cout << "Filtered sentence: " << sentence << std::endl;
}

void passwordConverter() 
{
    // TODO
    std::string password;
    std::string original;
    std::string modified;
    char letter;

    std::cout << "Please enter your text input: ";
    std::cin >> password;

    original = password;

    for(int i = 0; i < password.length(); i++)
    {
        letter = password.at(i);

        switch(letter)
        {
            case 'a':
                password.at(i) = '@';
                modified += password.at(i);
                break;

            case 'e':
                password.at(i) = '3';
                modified += password.at(i);
                break;

            case 'i':
                password.at(i) = '!';
                modified += password.at(i);
                break;

            case 'o':
                password.at(i) = '0';
                modified += password.at(i);
                break;

            case 'u':
                password.at(i) = '^';
                modified += password.at(i);
                break;

            default:
                modified += password.at(i);
                break;

        }

    
    }
    int i = 0;
    int j = password.length() - 1;
    while (i < j) {
        std::swap(password[i], password[j]);
        i++;
        j--;
    }
    std::cout << "input: " << original << std::endl;
    std::cout << "output: " << modified << password << std::endl;
    
}

void wordCalculator() 
{
    // TODO
}

void palindromeCounter() 
{
    // TODO
}