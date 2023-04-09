#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

class Queue{
    private:
    struct QueueNode{
        int val;
        QueueNode * next;
    };
    QueueNode * front;
    QueueNode * rear;
    int numItems;

    public:
    Queue();
    void enqueue(int);
    int dequeue();
    bool isEmpty() const;
    int getNumItems();
};

#endif
