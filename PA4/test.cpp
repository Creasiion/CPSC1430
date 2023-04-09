//Imani Cage
//hw4_5.cpp
//Programming Assignment #4
#include <iostream>
#include <string>
#include "Stack.h"
#include "Queue.h"
#include "Stack.cpp"
#include "Queue.cpp"

using namespace std;

int eval(string eqn);
bool isDigit(char a);

int main(){
    string userInput;
    cout << endl << "Please input your equation: ";
    cin >> userInput;
    cout << endl << eval(userInput);
    
return 0;
}

int eval(string eqn){
    Stack numbers;
    Stack opperands;
    int val = 0;
    int pos = 0;
    int sum = 0;
    int sign = 1;

    for(int pos = 0; pos < eqn.length(); pos++){ //reads string given
        char spot = eqn[pos];
        if(isDigit(spot)){
            val = 0;
            while(pos < eqn.length() && isDigit(eqn[pos])){
            cout << "Value found" << endl;
            val = (val * 10) + (int)(spot - '0');
            pos++;
            }
            sum += val*sign;
        }else if(spot == '-'){
            sign = -1;
        }else if(spot == '+'){
            sign = 1;
        }
    }
return sum;
}

bool isDigit(char a){
    return (a >= '0' && a <= '9');
}