#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

class Stack{
    private:
    struct StackNode{
        int val;
        StackNode * next;
    };
    StackNode * top;
    
    public:
    Stack();
    ~Stack();
    void push(int);
    int pop();
    int getTop();
    bool isEmpty()const;

};
#endif