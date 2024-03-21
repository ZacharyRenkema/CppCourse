#include "functions.h"
using std::cin, std::cout, std::endl, std::ostream, std::string;

#define INFO(X)  cout << "[INFO] ("<<__FUNCTION__<<":"<<__LINE__<<") " << #X << " = " << X << endl;
#define INFO_STRUCT(X) cout << "[INFO] ("<<__FUNCTION__<<":"<<__LINE__<<") " << #X << " count = " << X.count << endl;

/**
 * ----- REQUIRED -----
 * Pushes number to top of stack. If stack is full, then resize stack's array.
 * @param   stack   Target stack.
 * @param   number  Number to push to stack.
 */
void push(Stack& stack, int number) {
  // TODO: implement push function for stack
  //Stack stack;
  stack.numbers = new int[stack.count] {1};
  int doubledCap = stack.capacity * 2;
  int i = stack.count;

  if(stack.count == stack.capacity) //If at full cap resize array
  {
    stack.numbers = new int[doubledCap];
    stack.capacity = doubledCap;
    stack.count += 1;
  }
  stack.numbers[i + 1] = number;
  
  std::cout << stack.numbers << std::endl;
  
  delete[] stack.numbers;
  INFO_STRUCT(stack);
  INFO(number);
}

/**
 * ----- REQUIRED -----
 * Pops number from top of stack. If stack is empty, return INT32_MAX.
 * @param   stack   Target stack.
 * @return          Value of popped number.
 */
int pop(Stack& stack) {
  // TODO: implement pop function for stack
  INFO_STRUCT(stack);
  return 0;
}

/**
 * ----- REQUIRED -----
 * Returns the number at top of stack without popping it. If stack is empty, return INT32_MAX.
 * @param   stack   Target statck.
 * @return          Number at top of stack.
 */
int peek(const Stack& stack) {
  // TODO: implement peek function for stack
  INFO_STRUCT(stack);
  return 0;
}
