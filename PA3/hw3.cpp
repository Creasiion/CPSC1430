//Imani Cage
#include <iostream>
#include <string>
#include "FancyList.h"
using namespace std;


int main(){
  int caseOption;
  int numInput;
  FancyList user;
  
  user.menuOption(caseOption); 
  
  while(caseOption < 5 && caseOption >= 1){
    switch(caseOption){
    case 1:
      user.createList();
      user.menuOption(caseOption);
      break;
      
    case 2:
      cout << "Current list is: ";
      user.displayList();
      user.menuOption(caseOption);
      break;
      
    case 3:
      user.reverseList();
      cout << "Current list after reversing is: ";
      user.displayList();
      user.menuOption(caseOption);
      break;

    case 4:
      cout << "Delete n-th node from the end of the list, your n is: ";
      cin >> numInput;
      user.deleteVal(numInput);
      cout << endl << "Current list after deleting the n-th node from the end is: ";
      user.displayList();
      user.menuOption(caseOption);
      break;
    }
  }
  return 0;
}

