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
        //here we ask and check the integer 
        cout << "ENTER AN INTEGER: " << endl;
        cin >> inputNumber;
        if(inputNumber < 0){
            cout << "error: integer must be non-negative" << endl;
            continue;
        }

        //here we ask and check the exponent 
        cout << "ENTER AN EXPONENT: " << endl;
        cin >> inputExpo; 
        if(inputExpo < 0){
            cout << "error: exponent must be a non-negative" << endl;
            continue;
        }

        //here we call Repower and display the result
        cout << "RESULT: " << RePower(inputNumber, inputExpo) << endl;

        //here we will ask user if they want to continue 
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