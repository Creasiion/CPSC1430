#include <iostream>
#include "OrderedList.h"
#include <string>

using namespace std;

int main(){
    OrderedList listA;
    string userInput;
    int userConvert;

    cout << "Asking user to type and create listA..." << endl;
    while(userInput != "x"){
    cout << endl << "Type a number for insertion (type x to stop): ";
    cin >> userInput;
    if(userInput != "x"){
    userConvert = stoi(userInput);
    listA.insert(userConvert);
    }else{
        continue;
    }
    }

    cout << endl << "listA is: ";
    listA.printList();
    cout << endl << "listB is copied from listA: ";
    OrderedList listB(listA);
    listB.printList();

    cout << endl << endl;
    cout << "Asking user to type and add more to listB...";
    userInput = " ";
    while(userInput != "x"){
    cout << endl << "Type a number for insertion (type x to stop): ";
    cin >> userInput;
    if(userInput != "x"){
    userConvert = stoi(userInput);
    listB.insert(userConvert);
    }else{
        continue;
    }
    }

    cout << endl << endl;
    cout << "listA now is: ";
    listA.printList();
    cout << endl << "listB now is: ";
    listB.printList();
    cout << endl << endl;

    return 0;
}