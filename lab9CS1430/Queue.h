#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

class Queue{
    private:
    int * queueArray;
    int queueSize;
    int front;
    int rear;
    int numItems;

    public:
    Queue(int);
    ~Queue();
    void enqueue(int);
    int dequeue();
    int getSize();
    bool isEmpty() const;
    bool isFull() const;
};

#endif
