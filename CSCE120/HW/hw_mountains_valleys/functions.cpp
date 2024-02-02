#include <iostream>
#include "functions.h"

using std::cout, std::endl;

bool is_valid_range(int a, int b) 
{
	// TODO(student): validate input range
	if((a < b) && (a > 0) && (a < 10000) && (b < 10000))
	{
		return true;
	}
	else
	{
		return false;
	}

}

int M = 0;
int N = 0;
int V = 0;

char classify_mv_range_type(int d1, int d2, int d3, int d4, int number) //char classify_mv_range_type(int number) **original call**
{
/*
<------------------------------------------------------------------------------>
	// TODO(student): return 'M' if number has /\/\... pattern,
	// return 'V' if number has \/\/ pattern, and return 'N' otherwise
<------------------------------------------------------------------------------>
*/	
	//Two Digits
	if((number >= 10) && (number < 100))
	{
		if(d1 < d2)
		{
			M += 1;
			return M;
		}
		else if(d1 > d2)
		{
			V += 1;
			return V;
		}
		else
		{
			N += 1;
			return N;
		}

	}
	//Three Digits
	else if((number >= 100) && (number < 1000))
	{
		if((d1 < d2) && (d2 > d3))
		{
			M += 1;
			return M;
		}
		else if((d1 > d2) && (d2 < d3))
		{
			V += 1;
			return V;
		}
		else
		{
			N += 1;
			return N;
		}
	}
	//Four Digits
	else if((number >= 1000) && (number < 10000))
	{
		if((d1 < d2) && (d2 > d3) && (d3 < d4))
		{
			M += 1;
			return M;
		}
		else if((d1 > d2) && (d2 < d3) && (d3 > d4))
		{
			V += 1;
			return V;
		}
		else
		{
			N += 1;
			return N;
		}

	} 
	//Error
	else
	{
		return 0;
	}
	//std::cout << N << '\n';
	//std::cout << M << '\n';
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
	int val1; //Temporary values for calculated checking
	int val2;
	int val3;
	int val4;

	while(count <= b)
	{
		//std::cout << count << '\n';
		int n = count;
		//Two Digits
		if((n >= 10) && (n < 100)) 
		{
			//For First Number Use Integer Division
			val1 = n / 10;
			//std::cout << val1 << '\n';

			//For Second Number Use %
			val2 = n % 10;
			//std::cout << val2 << '\n';

			//std::cout << n << '\n';

			classify_mv_range_type(val1, val2, 0, 0, count);
			

		}
		//Three Digits
		else if((n >= 100) && (n < 1000))
		{
			val3 = n % 10;
			n /= 10;
			val2 = n % 10;
			n /= 10;
			val1 = n % 10;
			
			/*
			std::cout << val1 << "\n";
			std::cout << val2 << "\n";
			std::cout << val3 << "\n";
			*/

			classify_mv_range_type(val1, val2, val3, 0, count);
			
			
		}
		//4 Digits
		else
		{
			val4 = n % 10;
			n /= 10;
			val3 = n % 10;
			n /= 10;
			val2 = n % 10;
			n /= 10;
			val1 = n % 10;
			
			/*
			std::cout << val1 << "\n";
			std::cout << val2 << "\n";
			std::cout << val3 << "\n";
			*/

			classify_mv_range_type(val1, val2, val3, val4, count);
		}
		++count;


	}
	std::cout << " There are " << M << " mountain ranges and " << V << " valley ranges between " << a << " and " << b << "." << '\n';
	
}
