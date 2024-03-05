#include <iostream>
#include <exception>

int product_of_two_digits(long long number)
{
    int dig1;
    int dig2;
    int product = 1;

    while(number != 0)
    {
        dig2 = number % 10;
        number /= 10;

        if(number != 0)
        {
            dig1 = number % 10;
            number /= 10;
        }
        
        product += dig1 * dig2;

    }
    return product;


}


int main() 
{
    int n; //number to extract

    std::cout << "Please enter a number: " << std::endl;
    std::cin >> n;

    std::cout << product_of_two_digits(n);

    return 0;
}