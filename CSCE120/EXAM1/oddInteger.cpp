#include <iostream>

void removeOdd(int n)
{
    int digit;

    while(n != 0)
    {
        digit = n % 10;
        if(digit % 2 == 0)
        {
            std::cout << digit << std::endl;
        }

        n /= 10; // Corrected from digit /= 10;
    }
}

int main()
{
    int number;

    std::cout << "Please enter a number you would like to filter: " << '\n';
    std::cin >> number; 

    removeOdd(number);

    return 0;
}