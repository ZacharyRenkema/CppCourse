#include <iostream>

std::string name;
std::string nameTwo;

void welcome(){ //void functions do not return a value
    do{
        std::cout << "Please Enter Your Name: " << '\n';
        std::getline(std::cin,name);

    }while(name.empty());

    std::cout << "Welcome " << name << "." << '\n';

}


//Parameters
void happyBirthday(std::string nameParameter, int age){ // <-- To add parameter function_name(datatype, parameter name) {
    std::cout << "Happy Birthday to " << nameParameter << '\n'; //input parameter name in code
    std::cout << "Happy Birthday to " << nameParameter << '\n';
    std::cout << "Happy Birthday dear " << nameParameter << '\n';
    std::cout << "Happy Birthday to " << nameParameter << '\n';

    std::cout << "You are " << age << " years old" << '\n';

}


int main() //main function is where program is called and begins
{
    //Function = A block of reusable code
    
    welcome(); //envoke function like this in main()
    std::string nameTwo = "Zachary";
    int guy_age = 18;

    happyBirthday(nameTwo,guy_age);

    return 0;
}

//If we envoke the happyBirthday() before its calling in the main(), it will
//be out of scope as programs are compiled from the top down.


/*
----------------------------------------------------------------------------
People often call their seperate functions after the main function. However 
if you do that you must call the void function again prior to the main().
----------------------------------------------------------------------------
Example)

#include <iostream>

std::string name;


happyBirthday();

int main() //main function is where program is called and begins
{
    //Function = A block of reusable code
    
    happyBirthday(); //envoke function like this in main()


    return 0;
}
------------>Here the void function is called after main()<-----------

void happyBirthday(){ //void functions do not return a value
    do{
        std::cout << "Please Enter Your Name: " << '\n';
        std::getline(std::cin,name);

    }while(name.empty());

    std::cout << "Welcome " << name << "." << '\n';

}



*/