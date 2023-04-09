#include <iostream>
#include "Queue.h"

using namespace std;

Queue::Queue(int size){
    queueArray = new int[size];
    queueSize = size;
    front = -1;
    rear = -1;
    numItems = 0;
}

Queue::~Queue(){
    delete [] queueArray;
}

void Queue::enqueue(int num){
    if(isFull()){
        cout << "Queue is full!" << endl;
    }else{
        rear = (rear + 1) % queueSize;
        queueArray[rear] = num;
        numItems++;
    }
}


int Queue::dequeue(){
    if(isEmpty()){
        cout << "Queue is empty!" << endl;
        return -1;
    }else{
        front = (front + 1) % queueSize;
        numItems--;
        return queueArray[front];
    }
}

int Queue::getSize(){
    return queueSize;
}

bool Queue::isEmpty() const {
    return numItems == 0;
}

bool Queue::isFull() const {
    return numItems == queueSize;
}