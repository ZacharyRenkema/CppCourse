#include <iostream>
#include "functions.h"

using std::cout, std::endl;

bool is_valid_range(int a, int b) 
{
	// TODO(student): validate input range
	if(a < b)
	{
		return true;
	}
	else
	{
		return false;
	}

}

char classify_mv_range_type(int a, int b) //char classify_mv_range_type(int number) **original call**
{
/*
<------------------------------------------------------------------------------>
	// TODO(student): return 'M' if number has /\/\... pattern,
	// return 'V' if number has \/\/ pattern, and return 'N' otherwise
<------------------------------------------------------------------------------>
*/	
	if(a > b)
	{
		//std::cout << "M" << std::endl;
		return 'M';
	}
	else
	{
		//std::cout << "N" << std::endl;
		return 'N';
	}


	return 'N';
}

void count_valid_mv_numbers(int a, int b) 
{
/*
<------------------------------------------------------------------------------>
	 TODO(student): count the number of valid mountain ranges and valley
	// ranges in the range [a, b] and print out to console using the format
	// in Requirement 4 of the homework prompt
<------------------------------------------------------------------------------>
*/
	int count = a;
	int n = a;
	int val1; //Temporary value for calculated checking
	int val2;

	while(count <= b)
	{
		//Two Digits
		if((n >= 10) && (n < 100)) 
		{
			//For First Number Use Integer Division
			val1 = n / 10;
			//std::cout << val1 << '\n';

			//For Second Number Use %
			val2 = n % 10;
			//std::cout << val2 << '\n';

			std::cout << n << '\n';

			if(val1 != val2) //Checks to see if range is valid (val1 != val2)
			{
				classify_mv_range_type(val1, val2);
			}

		}
		//Plus Two Digits
		else if((n >= 100) && (n < 1000))
		{
			while(n > 0)
			{
				//
				val2 = n % 10;
				n /= 10;
				val1 = n % 10;

				std::cout << val1 << '\n';
				std::cout << val2 << '\n';

				if(val1 != val2) //Checks to see if range is valid (val1 != val2)
				{
				classify_mv_range_type(val1, val2);
				}

			}
			
		}
		


		count++;
	}
	//std::cout << count << '\n';

}
