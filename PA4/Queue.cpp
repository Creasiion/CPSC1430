#include <iostream>
#include "Queue.h"

using namespace std;

Queue::Queue(){
    front = nullptr;
    rear = nullptr;
    numItems = 0;
}


void Queue::enqueue(int num){
    QueueNode * newNode = new QueueNode;
    newNode->val = num;
    newNode->next = nullptr;
    if(isEmpty()){
        front = newNode;
        rear = newNode;
    }else{
        rear->next = newNode;
        rear = newNode;
    }
    numItems++;
}


int Queue::dequeue(){
    if(isEmpty()){
        cout << "Queue is empty!" << endl;
        return -1;
    }else{
        int value = front->val;
        QueueNode * temp = front;
        front = front->next;
        delete temp;
        numItems--;
        return value;
    }
}

bool Queue::isEmpty() const {
    return numItems == 0;
}

int Queue::getNumItems(){
    return numItems;
}