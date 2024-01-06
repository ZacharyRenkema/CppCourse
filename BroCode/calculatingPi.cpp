#include <iostream>


double calculateArea(double x) {
    double Area = x*x;
    
    std::cout << "The area is " << Area << '\n';
    
    return Area;

}


int main() {
    double finalAnswer = calculateArea(2.147);
    std::cout << finalAnswer << '\n';
    return 0;
}