#include <iostream>
#include "FancyList.h"
#include <string>
using namespace std;


FancyList::FancyList(){
  head = nullptr;
}

void FancyList::menuOption(int &cOption){
  cout << endl << endl;
  cout << "********* FancyList Menu *********" << endl;
  cout << "1. Create a list" << endl;
  cout << "2. Display the list" << endl;
  cout << "3. Reverse the list" << endl;
  cout << "4. Delete the n-th node from the end of the list" << endl;
  cout << "5. Exit the program" << endl;
  cout << endl << endl << "Enter your choice: ";
  cin >> cOption;
}

void FancyList::appendVal(int userInput){
  Node* newVal;
  Node* traverse;
  
  newVal = new Node;
  newVal->value = userInput;
  newVal->next = nullptr;
  
  if(!head){ //If there's no head pointer, set the head as the userInputs
    head = newVal;
  }else{
    traverse = head;
    while(traverse->next){
      traverse = traverse->next;
    }
    traverse->next = newVal;
  }
}

void FancyList::createList(){
  string value;
  int convertValue;
  while(value != "x"){
    cout << endl << "Type a number for appending (type x to stop): ";
    cin >> value;
    if(value != "x"){
      convertValue = stoi(value);
      appendVal(convertValue);
    }else{
      continue;
    }
  }
}

void FancyList::displayList(){
  //Print out the list while it's being transvered
  Node * curr = nullptr;
  curr = head;
  while(curr){
    cout << " " << curr->value << " ";
    curr = curr->next;
  }
}

void FancyList::reverseList(){
  Node * curr = head;
  Node * prev = nullptr;
  Node * temp = nullptr;
  while(curr != nullptr){
    temp = curr->next;
    curr->next=prev;
    prev = curr;
    curr = temp;
  }
  head = prev;
}

void FancyList::deleteVal(int userInput){
  int length = 0; //counts how long the list length is
  Node * temp = head; //Will ONLY be used to tranverse the linked list
  Node * prev = nullptr;
  Node * curr = nullptr;

  if(!head){
    cout << endl << "There are no nodes in the list.";
    return;
  }

  while(temp != nullptr){
    length++;
    temp = temp->next;
  }

  if(length < userInput){
    cout << endl << "List isn't long enough to remove " << userInput << "th node.";
    return;
  }else if(length == userInput){
    //If the length is the same as the nth, then that means the nth node we want to delete would be from our head
    temp = head->next;
    delete head;
    head = temp;
  }else{ //Similar to deleteing a single node function.
    int diff = length - userInput;  // Gives us the node we want to delete, but how much we want to traverse from the beginning
    curr = head;
    for(int i = 0; i < diff; i++){
      prev = curr;
      curr = curr->next;
    }
    if(curr){
      prev->next = curr->next;
      delete curr;
    }
  }
}
FancyList::~FancyList(){
  Node * curr = nullptr;
  curr = head;
  Node * next;
  cout << "Deallocating..." << endl;
  while(curr!=nullptr){
    cout << "Deleting " << curr->value << endl;
    next = curr->next;
    delete curr;
    curr = next;
  }
  head = nullptr;
}
