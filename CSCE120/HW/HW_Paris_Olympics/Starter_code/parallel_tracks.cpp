#include <iostream>
#include <iomanip>
#include <cstring>
#include "parallel_tracks.h"

using std::cin, std::cout, std::endl;

/*
void prep_double_array(double ary[]);
void prep_unsigned_int_array(unsigned int ary[]);
void prep_string_array(char ary[][STRING_SIZE]);
*/

//-------------------------------------------------------
// Name: prep_double_array
// PreCondition:  an array of doubles is passed in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_double_array(double ary[])
// making sure all values within the array are set to 0.0;
{
  //TODO
	for(unsigned int i = 0; i < SIZE; ++i)
	{
		ary[i] = 0.0;
	}

}

//-------------------------------------------------------
// Name: prep_unsigned_int_array
// PreCondition:  an array of unsigned ints is passed in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_unsigned_int_array(unsigned int ary[])
// making sure all values within the array are set to 0;
{
  //TODO
  for(unsigned int i = 0; i <= SIZE; i++)
  {
	ary[i] = 0;
  }

}

//-------------------------------------------------------
// Name: prep_string_array
// PreCondition:  an array of strings is passed in
// PostCondition: each element in the array is set to "N/A"
//---------------------------------------------------------
void prep_string_array(char ary[][STRING_SIZE])
{
    const char na[] = "N/A"; 
    const int na_length = sizeof(na) - 1; 
    
    for(unsigned int i = 0; i < SIZE; ++i)
    {
        for (unsigned int j = 0; j < STRING_SIZE; ++j)
        {
            if (j < na_length)
                ary[i][j] = na[j];
            else
                ary[i][j] = '\0'; 
        }
    }

}

//-------------------------------------------------------
// Name: trim
// PreCondition:  the cstring
// PostCondition: whitespace has been removed from beginning and end of string
//---------------------------------------------------------
void trim(char str[STRING_SIZE]) 
{
    int i = 0;
	int j = 0;

    while (isspace(str[i])) 
	{
        i++;
    }
    while (str[i] != '\0') 
	{
        str[j++] = str[i++];
    }
	str[j] = '\0';
    i = j - 1;

    while (i >= 0 && isspace(str[i])) 
	{
        i--;
    }

    str[i + 1] = '\0';
}

//-------------------------------------------------------
// Name: get_runner_data
// PreCondition:  the prepped parallel arrays
// PostCondition: all arrays contain data from standard in
//---------------------------------------------------------
bool get_runner_data(double timeArray[], char countryArray[][STRING_SIZE], 
		unsigned int numberArray[], char lastnameArray[][STRING_SIZE]) 
{
  //TODO
  	for(unsigned int i = 0; i < SIZE; ++i)
  	{
		double time;
    	char country[4];
    	unsigned int number;
    	char lastName[STRING_SIZE];
        
		std::cin >> time;
		std::cin >> country;
		std::cin >> number;
		//std::cin >> lastName;
		std::cin.ignore();
		cin.getline(lastName, STRING_SIZE);

    	if (time < 0 || strlen(country) != 3 || 
		!isupper(country[0]) || !isupper(country[1]) 
		|| !isupper(country[2]) || strlen(lastName) < 2 
		|| (number > 99)) 
		{
        	//cout << "Bad input" << endl;
            return false;
        } 
		else 
		{
            int j = 0;
            while (lastName[j] != '\0') 
			{
                if (!isalpha(lastName[j])) 
				{
                    //cout << "Bad input" << endl;
                    return false;
                }
                ++j;
            }
        
		}       
        // Pass Conditions
        timeArray[i] = time;
        strcpy(countryArray[i], country);
        numberArray[i] = number;
        trim(lastName);
        strcpy(lastnameArray[i], lastName);
    }


    return true;
}

//-------------------------------------------------------
// Name: get_ranking
// PreCondition:  just the time array is passed in, and has valid data
// PostCondition: after a very inefficient nested loop to determine the placements 
// and places the ranks in a new array. That new array is returned
//---------------------------------------------------------
void get_ranking(const double timeArray[], unsigned int rankArray[])
{
	//TODO
	for (unsigned int i = 0; i < SIZE; ++i) 
	{
        rankArray[i] = 1; // Initialize all ranks to 1      
        for (unsigned int j = 0; j < SIZE; ++j) 
		{
            if (timeArray[j] < timeArray[i]) 
			{
                rankArray[i]++;
            }
        }
    }

}


//-------------------------------------------------------
// Name: print_results
// PreCondition:  all parallel arrays are passed in and have valid data
// PostCondition: after a very inefficient nested loop to determine the ranks
// it then displays them along with a delta in time from the start
//---------------------------------------------------------
void print_results(const double timeArray[], const char countryArray[][STRING_SIZE],
		const char lastnameArray[][STRING_SIZE], const unsigned int rankArray[])
{

	std::cout << "Final results!!";
	std::cout << std::setprecision(2) << std::showpoint << std::fixed << std::endl;
	double best_time = 0.0;
		
	// print the results, based on rank, but measure the time difference_type
	for(unsigned int j = 1; j <= SIZE; j++)
	{	
		// go thru each array, find who places in "i" spot
		for(unsigned int i = 0; i < SIZE; i++)
		{
			if(rankArray[i] == 1) // has to be a better way, but need the starting time
			{
				best_time = timeArray[i];
			}			
			if(rankArray[i] == j) // then display this person's data
			{
				// this needs precision display
				std::cout << "[" << j << "]  " << timeArray[i] << " " << std::setw(15) << std::left << lastnameArray[i] << "\t" << "(" << countryArray[i] << ")  +" << (timeArray[i] - best_time) << std::endl; 
			}			
		}
	}

}