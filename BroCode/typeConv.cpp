#include <iostream>

int main() {
    //Type Conversions = conversion of a value of one data type to another
    //                   Implicit = Automatic
    //                   Explicit = Precede value with new data type (int)

//Implicit Example)
    double x = (int)3.14; //In this scenario, the value 3.14 is converted to int but stored in a double variable.
    std::cout << x << '\n';

    char y = 100; //This is another example where the 100 is converted through the "ASCII TABLE"
    std::cout << y << '\n'; 

    std::cout << (char)100; //Another way through std output
    

    return 0;
}