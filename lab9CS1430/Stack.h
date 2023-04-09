#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

class Stack{
    private:
    int * stackArray;
    int stackSize;
    int top;
    
    public:
    Stack(int);
    ~Stack();
    void push(int);
    int pop();
    bool isFull() const;
    bool isEmpty()const;

};
#endif