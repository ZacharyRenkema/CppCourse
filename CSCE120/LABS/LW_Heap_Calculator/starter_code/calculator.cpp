#include <iostream>
#include <string>
#include <sstream>
#include "functions.h"
using std::cin, std::cout, std::endl, std::string, std::istringstream;

int main() {
  // prompt user input
  Stack stack;
  cout << "Type RPN expression (end with '=')." << endl;
  cout << "> ";
  
  //TODO: create a command-line interface for calculator GUI
  push(stack,5);
  push(stack,10);

    

  return 0;
}