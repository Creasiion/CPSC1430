#include <iostream>
#include "Stack.h"

using namespace std;

Stack::Stack(int size){
    stackArray = new int[size];
    stackSize = size;
    top = -1;
}

Stack::~Stack(){
    delete [] stackArray;
}

void Stack::push(int num){
    if(isFull()){
        cout << "The stack is full. Nothing can be pushed" << endl;
    }else{
        top++;
        stackArray[top] = num;
    }
}

int Stack::pop(){
    if(isEmpty()){
        cout << "The stack is empty." << endl;
        return -1;
    }else{
        int returnValue = stackArray[top];
        top--;
        return returnValue;
    }
}

bool Stack::isFull() const {
    return top == stackSize - 1;
}

bool Stack::isEmpty() const {
    return top == -1;
}