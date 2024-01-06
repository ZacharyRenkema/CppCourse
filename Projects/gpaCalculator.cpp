#include <iostream>

//Letter Grade Credit Values
int A = 4;
int B = 3;
int C = 2;
int D = 1;

int main(){
    int courseNum; 
    //future endeavor 
    std::cout << "How many courses are you taking? ";
    std::cin >> courseNum;

    for(int i = 1; i <= courseNum; i++){
        char letter; //User inputted letter grade
        double totalCredit; //Combined value sum for each letter grade
        int credit =  0;

        std::cout << "What was your letter grade for course " << i << " ";
        std::cin >> letter;

        switch(letter) {
            case 'A':
            case 'a':
                credit = 4;
                break;

            case 'B':
            case 'b':
                credit = 3;
                break; 

            case 'C':
            case 'c':
                credit = 2;
                break;

            case 'D':
            case 'd':
                credit = 1;
                break;

        }
        totalCredit += credit;

        std::cout << totalCredit;
    }


    return 0;
}