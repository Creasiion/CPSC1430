#include <iostream>
#include <string>
#ifndef FANCYLIST_H
#define FANCYLIST_H
using namespace std;

class FancyList{
private:
  struct Node{
    int value;
    Node* next;
  };
  Node* head;
  
public:
  FancyList();
  void menuOption(int &cOption); // Will display menu and allow user to chose which case option
  void appendVal(int userInput); //Will be used in createList function to add values
  void createList();
  void displayList();
  void reverseList();
  void deleteVal(int userInput);
  ~FancyList();
};

#endif
