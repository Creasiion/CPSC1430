#include <iostream>
#include "Stack.h"

using namespace std;

Stack::Stack(){
    top = nullptr;
}

Stack::~Stack(){
    StackNode * curr = top;
    StackNode * next = nullptr;
    while(curr != nullptr){
        next = curr->next;
        delete curr;
        curr = next;
    }
    top = nullptr;
}

void Stack::push(int num){
    StackNode * newNode = new StackNode;
    newNode->val = num;
    if(isEmpty()){
        top = newNode;
        newNode->next = nullptr;
    }else{
        newNode->next = top;
        top = newNode;
    }
}

int Stack::pop(){
    StackNode * temp = nullptr;
    if(isEmpty()){
        cout << "Stack is empty.";
        return -1;
    }else{
        int returnValue = top->val;
        temp = top->next;
        delete top;
        top = temp;
        return returnValue;
    }
}
int Stack::getTop(){
    return top->val;
}

bool Stack::isEmpty() const {
    return top == nullptr;
}