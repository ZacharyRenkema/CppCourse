#include <iostream> 

int main() 
{
    //Array = A data type that can hold multiple values
    //        these values are accessed by an index number

    std::string car[] = {"Corvette", "Mustange", "Camry"}; //This is how to define an array
    
    std::cout << car[0];
    std::cout << car[1];
    std::cout << car[2];

    return 0;
}