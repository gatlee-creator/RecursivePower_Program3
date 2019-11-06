/*
    Name: Graham Atlee 
    Course: csc1720
    Date: 11/5/19
    Location of Program: ~/csc1720/Programs/program3

    This program contains code for a recursive power function.
    The maxium grade attempt is 100%. Features include:
    - Standard exponentiation 
    - Negative exponents
    - Program repeats until quit by user
    - Warn of overflow
*/

#include <iostream>
#include <limits>
using namespace std;


float RePower(int number, int exponent);
/*
    This is a recursive function that calculates the 
    result of an integer raised to a power.
    Preconditions:
        number >= 0
        exponent <= 0 || exponent >= 0
    If number is a negative then the program will prompt
    the user to enter a positive till satisfied. 
*/

int main()
{
    int inputNumber, inputExpo;
    char inputChoice;
    const int INVALID_LIMIT = 0; //setting the threshold 
    float MAX_FLOAT = numeric_limits<float>::infinity(); //data type limit 
  

    while (true)
    {
        //here we ask and check the integer 
        cout << "ENTER AN INTEGER: " << endl;
        cin >> inputNumber;
        if(inputNumber < INVALID_LIMIT){
            cerr << "error: integer must be non-negative" << endl;
            continue;
        }

        //here we ask for exponent - non-negative is allowed so No need for check  
        cout << "ENTER AN EXPONENT: " << endl;
        cin >> inputExpo; 
     

        //first we must check if our result will cause an overflow 
        if(RePower(inputNumber, inputExpo) == MAX_FLOAT){
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

/*
    This is the defenition of Repower
    Postcondition:
        number raised to the power of exponent 
        ex. 2^4 = 16
*/
float RePower(int number, int exponent){
    if(exponent == 0)
        return 1;
    if(exponent == 1)
        return number;
    if(exponent < 0) //negative exponent 
        return 1 / (float)(RePower(number, -exponent));
    else
        return number * RePower(number, exponent - 1); //positive exponent 
}