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
  Stack newStack;
  //stack.numbers = new int[stack.count] {1};
  int doubledCap = stack.capacity * 2;

  if(stack.count == stack.capacity) //If at full cap resize array
  {
    //Point pointer to new array location
    newStack.numbers = new int[doubledCap]; //New Array in heap

    //Copy location
    for(int i = 0; i <= stack.capacity; ++i) 
    {
      newStack.numbers[i] = stack.numbers[i];
      std::cout << newStack.numbers;
    }
    delete[] stack.numbers; //Delete old memory address
    stack.capacity = doubledCap; //Set original capicity to doubled cap.
    stack.numbers = newStack.numbers; //Reassign pointer to new address
  }
  //No need for resizing
  stack.numbers[stack.count + 1] = number;
  std::cout << stack.numbers << std::endl;
  
  //Return storage from heap
  delete[] stack.numbers;
  delete[] newStack.numbers;
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
