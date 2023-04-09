#include <iostream>
#include "IntegerSet.h"
#include <string>
using namespace std;

IntegerSet::IntegerSet(){
  for(int i = 0; i < MAX_SIZE; i++){
    set[i] = 0;
  }
}

IntegerSet::IntegerSet(int arr[], int numE){
  for(int i = 0; i < numE; i++){
    if(validEntry(arr[i]) == true){
      set[arr[i]] = 1;
    }
  }
}

void IntegerSet::inputSet(){
  string userInput;
  while( userInput != "x" ){
    cout << endl;
    cout << "Enter an element (Type x to stop): ";
    cin >> userInput;
    if(userInput != "x"){
      validEntry(stoi(userInput));
      if(validEntry(stoi(userInput)) == false){
        continue;
      }else{
        set[stoi(userInput)] = 1;
      }
    }
  }
  cout << endl << "Entry complete";
}

void IntegerSet::unionOfSets(IntegerSet b){
  int mergedSet[MAX_SIZE] = {0};
  for(int i = 0; i < MAX_SIZE; i++){
    if(set[i] == 1 || b.set[i] == 1){
      mergedSet[i] = 1;
    }else{
      continue;
    }
  }
  
  cout << "{";
  for(int i = 0; i < MAX_SIZE; i++){
    if(mergedSet[i] == 1){
      cout << " " << i << " ";
    }
  }
  cout << "}";
}

void IntegerSet::intersectionOfSets(IntegerSet b){
  int intersectionSet[MAX_SIZE] = {0};
  for(int i = 0; i < MAX_SIZE; i++){
    if(set[i]== 1 && b.set[i]== 1){
      intersectionSet[i] = 1;
    }else{
      continue;
    }
  }
  cout << "{"; // printing out the Intersecting numbers
  for(int i = 0; i < MAX_SIZE; i++){
    if(intersectionSet[i] == 1){
      cout << " " << i << " ";
    }
  }
  cout << "}";
}

void IntegerSet::insertElement(int userInput){
  if(validEntry(userInput) == true){
    set[userInput] = 1;
  }
}
void IntegerSet::deleteElement(int userInput){
  set[userInput] = 0;
}

void IntegerSet::printSet(){
  cout << "{";
  for(int i = 0; i < MAX_SIZE; i++){
    if(set[i] != 1){
      continue;
    }else{
      cout << " " << i << " ";
    }
  }
  cout << "}";
}

bool IntegerSet::isEqualTo(IntegerSet comparing){
  bool matched = true;
  for (int i = 0; i < MAX_SIZE; i++){
    if(set[i] != comparing.set[i]){
      matched = false;
      break;
    }else{
      continue;
    }
  }
  if(matched == true){
    cout << endl << "Sets are equal to each other";
    return matched;
  }else{
    cout << endl << "Sets are not equal to each other";
    return matched;
  }
  
}

void IntegerSet::emptySet(){
  for(int i = 0; i < MAX_SIZE; i++){
    set[i] = 0;
  }
}

bool IntegerSet::validEntry(int numCheck){ 
  if(numCheck <= 100 && numCheck >= 0){
    return true;
  }else{
    cout << endl << "Invalid insert of " << numCheck << " attempted!";
    return false;
  }
}


