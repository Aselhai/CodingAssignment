#include <iostream>

// #include "student.h"
#include "class.h"

using namespace std;

int main()
{

    Class OOP("OOP", "Kim");
    
    OOP.Register("Moon", 2017123123);
    OOP.Register("Abe", 2017123124);
    OOP.Register("Trump", 2017123125);
    OOP.Register("A", 1);
    OOP.Register("B", 3);
    OOP.Register("C", 4);
    OOP.Display();
    
    Class DATA = OOP;
    
    DATA.SetClassName("Data Structure", "Yang");
    DATA.Withdraw(2017123124);
    DATA.Display();
    
    OOP.Display();
    
    Class AI(OOP);
    AI.SetClassName("Artificial Intelligence", "Hwang");
    AI.Register("Siri", 2017123126);
    AI.Display();

    OOP.Display();

    return 0;
}