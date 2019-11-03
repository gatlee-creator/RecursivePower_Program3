#include <iostream>
using namespace std;

int RePower(int number, int exponent){
    if(exponent == 0)
        return 1;
    if(exponent == 1)
        return number;
    
    return number * RePower(number, exponent - 1);
}

int main()
{
    int inputNumber, inputExpo;
    char inputChoice;

    while (true)
    {
        cout << "ENTER AN INTEGER: " << endl;
        cin >> inputNumber;
        cout << "ENTER AN EXPONENT: " << endl;
        cin >> inputExpo; 
        cout << "RESULT: " << RePower(inputNumber, inputExpo) << endl;

        cout << "ENTER ANOTHER NUMBER?" << endl;
        cout << "enter Y or any other key to quit" << endl;
        cin >> inputChoice;

        if(inputChoice == 'Y')
            continue; //restart loop
        else
            break; //exit program
        
        
    }
    

   


    return 0; 
}