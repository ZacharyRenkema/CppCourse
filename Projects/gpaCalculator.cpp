#include <iostream>

int main(){
    using strings = std::string;
    int courseNum; 
    double gpa;
    int tempHours;
    char letter; //User inputted letter grade
    double points; //Combined value sum for each letter grade
    int credit =  0; //letter credit
    int totalHours = 0;

    //Introduction: 
    bool Yes = true;
    bool No = false;
    strings input;

    std::cout << "-------------------------------------------------------------------" << '\n';
    std::cout << "<---------- Welcome to Zachary Renkema's GPA Calculator ---------->" << '\n';
    std::cout << "-------------------------------------------------------------------" << '\n';
    std::cout << '\n';

    //Start
    std::cout << "Would you like to calculate your cumulative gpa? (Yes/No) ";
    std::getline(std::cin >> std::ws,input) ; 

    if(input == "Yes"){
        //shit
        std::cout << "How many courses are you taking? ";
        std::cin >> courseNum;
    
        for(int i = 1; i <= courseNum; i++){
            tempHours = 0;
            std::cout << "What was your letter grade for course " << i << " ";
            std::cin >> letter;
            std::cout << "How many credit hours is this class ";
            std::cin >> tempHours;
            totalHours += tempHours;

            switch(letter) {
                case 'A':
                case 'a':
                    credit = tempHours * 4;
                    break;

                case 'B':
                case 'b':
                    credit = tempHours * 3;
                    break; 

                case 'C':
                case 'c':
                    credit = tempHours * 2;
                    break;

                case 'D':
                case 'd':
                    credit = tempHours * 1;
                    break;

            }
            points += credit;
        }

    }

    else{
        std::cout << "Come back again soon!" << '\n';
        system("pause");
        return 0; 
    }

    gpa = (double)(points)/(double)(totalHours);
    std::cout << "Your cumulative gpa for this semester is " << gpa << '\n';
    system("pause");
    
    
    return 0;
}