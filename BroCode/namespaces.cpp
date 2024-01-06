#include <iostream>

//Namespace declaration
namespace firstNameSpace {
    int x = 1;
}

namespace secondNameSpace{
    int x = 2;
}

int main() {
    //Name Spaces) Provide a solution for preventing name conflicts in large projects. Each
    // entity needs a unique name. A namespace allows for identically named entities as long
    // as the namespace is different.
    int x = 0;

    std::cout << firstNameSpace::x << '\n'; //Preceded with prefix of firstNameSpace
    std::cout << secondNameSpace::x << '\n'; //Preceded with prefix of secondNameSpace

    //If namespace is not explicitly stated, the local version of the entity is used. 
    std::cout << x << '\n';


    return 0;
}

