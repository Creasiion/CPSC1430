//Imani Cage
//hw4_5.cpp
//Programming Assignment #4
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Stack.h"
#include "Queue.h"

using namespace std;

int eval(string eqn);
bool isDigit(char a);
bool isOpperator(char b);
int operate(int val1, int val2, int opperand);
Queue slidingAvg(int t2 [], int window, int numE);

int main(int argc, char* argv[]){
    string userInput;
    int windowSize;
    int val;
    int count = 0;
    int arr[10]; //Will hold the numbers from text file
    Queue average;
    string FILENAME = argv[1];

    cout << endl << "****Showcasing the first task****" << endl;
    while(userInput != "#"){
    cout << endl << " Type the expression (type # to quit): ";
    cin >> userInput;
    
    if(userInput != "#"){
    cout << endl << "The value of this expression is " << eval(userInput);
    }
    }
    
    cout << endl << "****Showcasing the second task****" << endl;

    ifstream infile;
    infile.open(FILENAME);
    if(infile.fail()){
        cout << "File error: exiting program. Please try again.";
        cout << endl << endl;
        return 0;
    }else{
      while(infile >> val){
        arr[count] = val;
        count++;
      }
      }
    infile.close();

windowSize = stoi(argv[2]);

   average = slidingAvg(arr, windowSize, count);
   cout << endl << "The averages in each window of size " << windowSize << " are: ";

    while(!average.isEmpty()){
        cout << average.dequeue() << " ";
    }
    
return 0;
}

int eval(string eqn){
    Stack numbers;
    Stack opperands;
    int val = 0;
    int pos = 0;
    int prev;
    int opp;

    while(pos < eqn.length()){ //reads string given
        char spot = eqn[pos];
        if(isDigit(spot)){
            val = (val * 10) + (int)(spot - '0');
        }else if(isOpperator(spot)){
            numbers.push(val); //save the number before the opperand into stack
            if(spot == '+'){
                opperands.push(1); //Symbol + will be represented as 1, while - will be represented as 2
            }else{
                opperands.push(2);
            }
            val = 0; // reset val in order to get the next number
        }
        pos++;
    } // end of while loop
    //One val isn't included during while loop, so add it to stack and reset val
    numbers.push(val);
    val = 0;
    while(!opperands.isEmpty()){ 
        //Performs the calculations - will take two numbers from number stack and add/subtract based off of operand stack at the time
        //This does NOT include the last number of the stack, as the operators tend to leave first, and the loop ends
        prev = numbers.pop();
        opp = opperands.pop();
        val = operate(val, prev, opp);
    }
    //Final numbers.pop() and operate function used to include the last value.
    prev = numbers.pop();
    val = operate(val, prev, opp);
    return val;
}

bool isDigit(char a){
    //In ASCII values 
    //character a will still be in between the character numbers if it is a digit
    return (a >= '0' && a <= '9');
}
bool isOpperator (char b){
    return (b == '+' || b == '-');
}

int operate(int val1, int val2, int opperand){
    //+ in eval function is represented as 1 within the opperand stack, - is represented by 2
    if(opperand == 1){ 
        return (val1 + val2);
    }else if(opperand == 2){
        return (val1 - val2);
    }else{
        return val2;
    }
}
Queue slidingAvg(int t2 [], int window, int numE){
    //Reads first 3 values from the array before adding it to queue
    //Afterwards, i will always be >= window, 
    //so we subtract i's position with window, which causes the "sliding" part in our function
    int sum = 0;
    Queue avgs;
    for(int i=0; i < numE; i++){
        sum += t2[i];
        if(i >= window){
            sum -= t2[i-window];
            avgs.enqueue(sum/window);
        }
    }
return avgs;
}