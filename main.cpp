#include <iostream>
using namespace std;

int RePower(int number, int exponent){
    if(exponent == 0)
        return 0;
    if(exponent == 1)
        return 1;
    
    return number * RePower(number, exponent - 1);
}

int main()
{



    return 0; 
}