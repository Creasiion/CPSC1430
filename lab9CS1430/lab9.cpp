#include <iostream>
#include "Stack.h"
#include "Queue.h"

using namespace std;

void reverseK(int k, Queue& q);

int main(){
    int k;
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Queue q(10);
    q.enqueue(array[0]);
    q.enqueue(array[1]);
    q.enqueue(array[2]);
    q.enqueue(array[3]);
    q.enqueue(array[4]);
    q.enqueue(array[5]);
    q.enqueue(array[6]);
    q.enqueue(array[7]);
    q.enqueue(array[8]);
    q.enqueue(array[9]);


    cout << "Please input number k to reverse: ";
    cin >> k;
    cout << "Original array: ";
    for(int i = 0; i < 10; i++){
        cout << " " << array[i];
    }
    cout << endl;
    cout << "Reverse first " << k << ": ";
    reverseK(k, q);
    while(!q.isEmpty()){
        cout << q.dequeue() << " ";
    }
    cout << endl;
    return 0;
}

void reverseK(int k, Queue& q){
    Stack revArr(q.getSize());
    if(q.isEmpty() || k > q.getSize()){
        cout << "Unable to reverse an empty queue or if " << k << " is bigger than queue size." << endl;
        return;
    }
    if (k <= 0){ //can't reverse negative elements. If k is 0, then the queue will be the same
        return;
    }else{
        for(int i = 0; i < k; i++){
            revArr.push(q.dequeue()); //removes values we want from the queue while adding it to a stack 
        }
        while(!revArr.isEmpty()){
            q.enqueue(revArr.pop()); //Adding values in the stack back in, but will be reversed because of the stack's pop function
        }
        for(int i = 0; i < q.getSize() - k; i++){ //adjusts rest of the values
            q.enqueue(q.dequeue());
        }
    }
}