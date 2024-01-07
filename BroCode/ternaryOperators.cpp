#include <iostream> 

int main() 
{
    // Ternary operator ?: = replacemant to an if/else statement
    // condition ? expression1 : expression2;
    // This simplifies conditional statements much quicker

    int grade = 75;

//If statement way
/* 
    if(grade >= 60)
    {
        std::cout << "You passed!";

    }
    else {
        std::cout << "You failed!";
    }
*/

//Ternary operator way

    (grade >= 60) ? std::cout << "You pass!" << '\n' : std::cout << "You failed!" << '\n';
   //(condition)                (expression1)               (expression2)
   //                           (True Expression)           (False Expression) 

//Another way of using tenary operators

    bool hungry = false;

    std::cout << (hungry ? "You are hungry" : "You are full");

    
 
    return 0;
}