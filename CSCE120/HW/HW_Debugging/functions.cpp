#include <iostream>
#include "functions.h"
#include <stdexcept>

using std::cout, std::cin, std::endl;

int Largest(int a, int b, int c) 
{
  int d = a;
  if(b > d) 
  {
    d = b;
  }
  if(c > d) 
  {
    d = c;
  }
  /* 
  else if (c >> d) 
  {
    d = c;
  }
  */ 
  return d;
}

bool SumIsEven(int a, int b)
{
  if(((a + b) % 2) == 0)
  {
    return true;
  }
  else if(((a + b) % 2) != 0)
  {
    return false;
  }
  else
  {
    return false;
  }
  return false;
}

int BoxesNeeded(int apples) 
{
    if (apples <= 0) 
    {
        return 0;
    } 
    else 
    {
        int boxes = apples / 20;

        if (apples % 20 != 0) 
        {
            boxes++; // Increment the boxes if there are remaining apples
        }
        return boxes;
    }

}
bool SmarterSection(int A_correct, int A_total, int B_correct, int B_total) 
{
    if (A_total < 0 && B_total < 0) 
    {
        throw std::invalid_argument("");
        //return std::invalid_argument("");
    } 
    if ((static_cast<double>(A_correct) / static_cast<double>(A_total)) > (static_cast<double>(B_correct) / static_cast<double>(B_total))) 
    {
        return true;
    } 
    else 
    {
        return false;

    }

}


bool GoodDinner(int pizzas, bool is_weekend) 
{
  if ((pizzas >= 10 && pizzas <= 20) || (pizzas >= 10 && is_weekend)) {
    return true;
  }
  else 
  {
    return false;
  }
}
/*
int SumBetween(int low, int high) 
{
  int value = 0;
  
  if(low > high)
  {
    throw std::invalid_argument("");
  }
  if (low == -2147483648 && high == 2147483647) 
  {
    return low; 
  }
  for (int n = low; n <= high; ++n)
  {
    //Check for overflow
    if((low < 0 && high < 2147483647 - low) || (high > 0 && low > 2147483647 - high))
    {
      throw std::overflow_error("");
    }
    value += n;
  }
  return value;

}
*/
int SumBetween(int low, int high) {
    int value = 0;

    if (low > high) {
        throw std::invalid_argument("low cannot be greater than high");
    }

    if (low == -2147483648 && high == 2147483647) {
        return low;
    }

    if ((high > 0 && low > 2147483647 - high) ||
        (high < 0 && low < -2147483648 - high)) {
        throw std::overflow_error("Sum exceeds the maximum/minimum value of int");
    }

    int numTerms = high - low + 1;
    value = (numTerms / 2) * (low + high);

    if (numTerms % 2 != 0) {
        value += (low + high) / 2;
    }

    return value;
}

int Product(int a, int b) 
{
  //int max = 2147483647;
  //   int min = -2147483648;
  if ((a > 0 && b > 2147483647 / a) || (a < 0 && b < 2147483647 / a) || (a > 0 && b < -2147483648 / a) || (a < 0 && b > -2147483648 / a)) 
  {
    throw std::overflow_error("Product exceeds the maximum/minimum value of int");
  }

  return a * b;
}