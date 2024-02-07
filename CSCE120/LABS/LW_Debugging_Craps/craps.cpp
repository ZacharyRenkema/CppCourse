#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout, std::cin;

// function prototype / declarations
int rollDice();		
int doGame(int, int);

int main()
{
  /*
    Normally, we would seed with time(NULL), however autograding
    is hard to do with random results. So, we are going to 
    enter a seed value to allow for autograding.
  */
  int seed;
  int wallet = 1000;
  bool gameOver = false;  // Initialize gameOver to false
  int bet;
  char c;

  //std::cout << "Please enter your seed"; //DELETE THIS AFTER DEBUGGING!!!!!
  cin >> seed;
  srand(seed); // Seed the random number generator

  while (!gameOver) // Remove the semicolon
  {
    cout << "Enter amount to bet. You have $" << wallet << std::endl;  
    cin >> bet;

    if (bet <= 0)
    {
      cout << "Bet must be positive." << std::endl;
    }
    else if (bet > wallet)
    {
      cout << "You don't have that much money." << std::endl;
    }	
    else
    {
      wallet = doGame(bet, wallet);
    }

    if (wallet == 0)
    {
      cout << "You are penniless. Thanks for playing." << std::endl;
      gameOver = true;
    }
    else
    {
      cout << "Play again? (y/n)" << std::endl;
      cin >> c;
    }

    if (c == 'n')
    {
      gameOver = true;
      cout << "You ended the game with $" << wallet << std::endl;
    }
  }
}     

// Simulate rolling two dice.  We need a separate call
// to rand() for each die roll to get the same distribution
// as rolling two actual dice.
int rollDice()
{
  return (rand() % 6 + rand() % 6 + 2);
  // rand() % 6 will give a value of 0 to 5
  // adding 1 will give a value of 1 to 6
  // adding 2 is the update for both die.
}

int doGame(int bet, int wallet) {
  // Make initial roll
  int roll = rollDice();
  cout << "You rolled " << roll << std::endl;
  // Check for a win or loss or the point
  switch (roll)
  {
    case 7:
      cout << "You win!" << std::endl;
      wallet += bet;
      break;

    case 11:
      cout << "You win!" << std::endl;
      wallet += bet;
      break;

    case 2:
      cout << "You lose." << std::endl;
      wallet -= bet;
      break;

    case 3:
      cout << "You lose." << std::endl;
      wallet -= bet;
      break;

    case 12:
      cout << "You lose." << std::endl;
      wallet -= bet;
      break;

    default:
      // Continue rolling until we roll the point
      // or 7
      int point = roll;
      cout << "The point is " << point << std::endl;
      do
      {
        roll = rollDice();
        cout << "You rolled " << roll << std::endl;
        if (roll == 7)
        {
          cout << "You lose." << std::endl;
          wallet -= bet;
        }
        else if (roll == point) // Fix the comparison operator here
        {
          cout << "That matches the point! You win!" << std::endl;
          wallet += bet;
        }
      } while ((roll != 7) && (roll != point)); // Change the logical operator here
  }
  return wallet; // Return the updated wallet value
}  