#include <iostream>
#include "functions.h"

using std::cout, std::cin, std::endl;

int a;
int b;

int main() {
	//Validate range function call
	do 
	{
		std::cout << "Enter numbers 10 <= a <= b < 10000:" << '\n';
		std::cin >> a >> b;
	
	} while(is_valid_range(a,b) != true);


	if(is_valid_range(a, b) == true)
	{
		count_valid_mv_numbers(a, b);
	}

	// TODO(student): read the numbers from standard input

	// TODO(student): validate input (and reprompt on invalid input)

	// TODO(student): compute and display solution
	
	return 0;
}