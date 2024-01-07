#include <iostream>

int main()
{
    //do while loop = does a block of code first,
    //                THEN repeats again if condition is true

    int number;

    do{
        std::cout << "Enter a positive number ";
        std::cin >> number;

    } while(number < 0); //This will run the code once and then repeat the while loop
    
    std::cout << "The number is: " << number;


    return 0;
}