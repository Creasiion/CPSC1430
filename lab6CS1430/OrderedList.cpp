#include <iostream>
#include "OrderedList.h"
using namespace std;

OrderedList::OrderedList(){
   head = nullptr;
}

OrderedList::OrderedList(OrderedList &listRef){
   Node * currentVal = listRef.head;
  head = nullptr;
    while(currentVal != nullptr){
      insert(currentVal->value); //uses own insert functions to with other's values in order to make its list
      currentVal = currentVal->next;
    }
    }
  
OrderedList::~OrderedList(){
  Node * current = nullptr;
  current = head;
  Node * next;
  cout << endl << "Deallocating..." << endl;
  while(current!=nullptr){
    cout << "deleting " << current->value << endl;
    next = current ->next;
    delete current;
    current = next;
  }
  head = nullptr;
}

void OrderedList::insert(int num){ //InsertNode function taught in class
   Node * newNode = nullptr;
   Node * current = nullptr;
   Node * previous = nullptr;

   newNode = new Node;
   newNode->value = num;
   newNode->next = nullptr;

   if(!head){ //For the very first node
      head = newNode;
      newNode->next = nullptr;
   }else{
      current = head;
      previous = nullptr;

   while(current != nullptr && current->value < num){
      previous = current;
      current = current->next;
   }

   if(previous == nullptr){
      head = newNode;
      newNode->next = current;
   }else{
      previous->next = newNode;
      newNode->next = current;
   }
}
}

void OrderedList::printList(){
  Node * current = nullptr;
  current = head;
  while(current){
    cout << " " << current->value << " ";
    current = current->next;
  }
}