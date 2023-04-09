//Except for adding your own comments to this file,
//you should not make any change to this file.
#ifndef ORDEREDLIST_H
#define ORDEREDLIST_H
#include <iostream>
using namespace std;
class OrderedList {
   private:
    struct Node{
      int value;
      Node *next;
    };
    Node* head;
  public:
    OrderedList();
    OrderedList(OrderedList &);
    ~OrderedList();
    void insert(int);
    void printList();
};
#endif