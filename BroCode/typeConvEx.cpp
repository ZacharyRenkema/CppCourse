#include <iostream>

//Type Conversions are nessecary when needed to convert datatypes such as in the example below
int main(){
    /*
    int correct = 8;
    int numQuestions = 10;
    double score = correct/numQuestions * 100; When doing it this way, the int type for correct and numQuestions is truncating the decimal
    */

//Corect Way)
    int correct = 8;
    int numQuestions = 10;

    double score = (double)correct/(double)numQuestions * 100;


    std::cout << score << "%" << '\n';

    return 0;
    //In the above method, numQuestions and correct were cast in the double datatype thus calculating score as a double. 
    //This retained the decimal value which allowed it to be multiplied by 100 to result in the correct percentage.

}