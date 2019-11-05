#include <iostream>
using namespace std;

float RePower(int number, int exponent){
    if(exponent == 0)
        return 1;
    if(exponent == 1)
        return number;
    if(exponent < 0) //negative exponent 
        return 1 / (float)(RePower(number, exponent -1));
    else
        return number * RePower(number, exponent - 1); //positive exponent 
}

int main()
{
    int inputNumber, inputExpo;
    char inputChoice;
    const int INVALID_LIMIT = 0;
    

    while (true)
    {
        //here we ask and check the integer 
        cout << "ENTER AN INTEGER: " << endl;
        cin >> inputNumber;
        if(inputNumber < INVALID_LIMIT){
            cerr << "error: integer must be non-negative" << endl;
            continue;
        }

        //here we ask and check the exponent 
        cout << "ENTER AN EXPONENT: " << endl;
        cin >> inputExpo; 
        // if(inputExpo < INVALID_LIMIT){
        //     cerr << "error: exponent must be a non-negative" << endl;
        //     continue;
        // }

        //first we must check if our result will cause an overflow 
        /*
            If the return value is negative that indicates an overflow.
            If there is a 0 then the carryout was 0 meaning overflow.
        */
        if(RePower(inputNumber, inputExpo) <= INVALID_LIMIT){
            cerr << "warning: these numbers will cause an overflow" << endl;
        }
        else {
            //here we call Repower and display the result
            cout << "RESULT: " << RePower(inputNumber, inputExpo) << endl;
        }
       

        //here we will ask user if they want to continue 
        cout << "ENTER ANOTHER NUMBER?" << endl;
        cout << "enter Y or any other key to quit" << endl;
        cin >> inputChoice;

        if(inputChoice == 'Y')
            continue; //restart loop
        else
            break; //exit program
        
        
    } //end loop

    return 0; 
}