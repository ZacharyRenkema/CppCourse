#include <iostream>

int main() {
    double pi = 3.14159;
    double radius = 10;
    double circumference = 2 * pi * radius;

    std::cout << circumference << '\n';

//Any time you do not want a variable to be changed you can use the "const" prefix to keep it constant.
//Proper naming convention also dictates to label constant variables in all caps. 

    const double PI = 3.14159; //Remember to all caps in name declaration.
    radius = 10;
    circumference = 2 * PI * radius;

    std::cout << circumference << '\n';
    

    return 0;
}