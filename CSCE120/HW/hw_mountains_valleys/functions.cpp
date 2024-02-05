#include <iostream>
#include "functions.h"

using std::cout, std::endl;

bool is_valid_range(int a, int b) 
{
	// TODO(student): validate input range
	if((a >= 10) && (a <= b) && (b < 10000))
	{
		return true;
	}
	else
	{
		classify_mv_range_type(a);
		return false;
	}

}


char classify_mv_range_type(int number) //char classify_mv_range_type(int number) **original call**
{
/*
<------------------------------------------------------------------------------>
	// TODO(student): return 'M' if number has /\/\... pattern,
	// return 'V' if number has \/\/ pattern, and return 'N' otherwise
<------------------------------------------------------------------------------>
*/
	int dig1 = 0;
	int dig2 = 0;
	char category = 'U'; //'U' set to initiate continuation of loop at beginning of iteration

	dig2 = number % 10;
	number /= 10;

	while(number > 0) 
	{
		dig1 = number % 10;

		//std::cout << number << '\n';
		//std::cout << dig2 << '\n';
		//std::cout << dig1 << '\n';

		//Mountain Classification
		if(dig1 < dig2)
		{
			if((category == 'V') || (category == 'U'))
			{
				category = 'M';
			}
			else
			{
				category = 'N';
			}
			
		}
		else if(dig1 > dig2)
		{
			if((category == 'M') || (category == 'U'))
			{
				category = 'V';
			}
			else{
				category = 'N';
			}
		}
		else
		{
			category = 'N';
		}
		dig2 = dig1;
		number /= 10;


	}
	//Return
	switch(category) 
	{
		case 'M':
			return 'M';
			break;

		case 'V':
			return 'V';
			break;

		case 'N':
			return 'N';
			break;

		default:
			return 'N';
			break;

	}


}

/*
	//Two Digits
	if((number >= 10) && (number < 100))
	{
		if(d1 < d2)
		{
			M += 1;
			return 'M';
		}
		else if(d1 > d2)
		{
			V += 1;
			return 'V';
		}
		else
		{
			N += 1;
			return 'N';
		}

	}
	//Three Digits
	else if((number >= 100) && (number < 1000))
	{
		if((d1 < d2) && (d2 > d3))
		{
			M += 1;
			return 'M';
		}
		else if((d1 > d2) && (d2 < d3))
		{
			V += 1;
			return 'V';
		}
		else
		{
			N += 1;
			return 'N';
		}
	}
	//Four Digits
	else if((number >= 1000) && (number < 10000))
	{
		if((d1 < d2) && (d2 > d3) && (d3 < d4))
		{
			M += 1;
			return 'M';
		}
		else if((d1 > d2) && (d2 < d3) && (d3 > d4))
		{
			V += 1;
			return 'V';
		}
		else
		{
			N += 1;
			return 'N';
		}

	} 
	//Error
	else
	{
		return 0;
	}

}
*/

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
	int d1; //Temporary values for calculated checking
	int d2;
	int d3;
	int d4;
	int d5;
	int d6;
	int d7;
	//int d8;

	int M = 0;
	int N = 0;
	int V = 0;

	while(count <= b)
	{
		//std::cout << count << '\n';
		int n = count;

		classify_mv_range_type(count);

		//Two Digits
		if((n >= 10) && (n < 100)) 
		{
			//For First Number Use Integer Division
			d1 = n / 10;
			d2 = n % 10;

			if(d1 < d2)
			{
				M += 1;
			}
			else if(d1 > d2)
			{
				V += 1;
			}
			else
			{
				N += 1;
			}

		
		}
		//Three Digits
		else if((n >= 100) && (n < 1000))
		{
			d3 = n % 10;
			n /= 10;
			d2 = n % 10;
			n /= 10;
			d1 = n % 10;
			
			if((d1 < d2) && (d2 > d3))
			{
				M += 1;
				
			}
			else if((d1 > d2) && (d2 < d3))
			{
				V += 1;
			}
			else
			{
				N += 1;
			}
			
			
		}
		//4 Digits
		else if((n >= 1000) && (n < 10000))
		{
			d4 = n % 10;
			n /= 10;
			d3 = n % 10;
			n /= 10;
			d2 = n % 10;
			n /= 10;
			d1 = n % 10;
			
			if((d1 < d2) && (d2 > d3) && (d3 < d4))
			{
				M += 1;
			}
			else if((d1 > d2) && (d2 < d3) && (d3 > d4))
			{
				V += 1;
			}
			else
			{
				N += 1;
			}
		}
		else if((n >= 10000) && (n < 100000))
		{
			d5 = n % 10;
			n /= 10;
			d4 = n % 10;
			n /= 10;
			d3 = n % 10;
			n /= 10;
			d2 = n % 10;
			n /= 10;
			d1 = n % 10;
			
			if((d1 < d2) && (d2 > d3) && (d3 < d4) && (d4 > d5))
			{
				M += 1;
			}
			else if((d1 > d2) && (d2 < d3) && (d3 > d4) && (d4 < d5))
			{
				V += 1;
			}
			else
			{
				N += 1;
			}
		}
		else if((n >= 100000) && (n < 1000000))
		{
			d6 = n % 10;
			n /= 10;
			d5 = n % 10;
			n /= 10;
			d4 = n % 10;
			n /= 10;
			d3 = n % 10;
			n /= 10;
			d2 = n % 10;
			n /= 10;
			d1 = n % 10;
			
			if((d1 < d2) && (d2 > d3) && (d3 < d4) && (d4 > d5) && (d5 < d6))
			{
				M += 1;
			}
			else if((d1 > d2) && (d2 < d3) && (d3 > d4) && (d4 < d5) && (d5 > d6))
			{
				V += 1;
			}
			else
			{
				N += 1;
			}
		}
		else if((n >= 1000000) && (n < 10000000))
		{
			d7 = n % 10;
			n /= 10;
			d6 = n % 10;
			n /= 10;
			d5 = n % 10;
			n /= 10;
			d4 = n % 10;
			n /= 10;
			d3 = n % 10;
			n /= 10;
			d2 = n % 10;
			n /= 10;
			d1 = n % 10;
			
			if((d1 < d2) && (d2 > d3) && (d3 < d4) && (d4 > d5) && (d5 < d6) && (d6 > d5))
			{
				M += 1;
			}
			else if((d1 > d2) && (d2 < d3) && (d3 > d4) && (d4 < d5) && (d5 > d6) && (d6 < d7))
			{
				V += 1;
			}
			else
			{
				N += 1;
			}
			
		}
		
		++count;

	
	}
	std::cout << "There are " << M << " mountain ranges and " << V << " valley ranges between " << a << " and " << b << "." << '\n';
	
	
}





