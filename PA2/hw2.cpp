//Imani Cage
//hw2.cpp
/*Programming Assignment #2 - Create a class IntegerSet for which each object can hold integers in the range 0 through 100.  
This customized set is represented internally as an array of ones and zeros; 
array elements a[i] is 1 if integer i is in the set. 
Member functions included are below: 
Union of sets (combining two sets together), 
Intersection of sets (numbers within both sets),
Insert Element (inserting a single number),
Delete Element, 
Print Set,
Equality Check (if both number sets are equal to each other),
empty set (removes all numbers),
input set (input an already existing list of numbers to a set), 
and Valid Entry (only numbers 0-100 are allowed in a set)*/

#include <iostream>
#include <string>
#include "IntegerSet.h"

using namespace std;

int main(int argc, char *argv[]){
  IntegerSet A;
  IntegerSet B;
  int val;
  
  cout << endl << "Enter set A:" << endl;
  A.inputSet();
  cout << endl << "Enter set B:" << endl;
  B.inputSet();
  
  cout << endl << endl << "Union of A and B is:" << endl;
  A.unionOfSets(B);
  
  cout << endl << "Intersection of A and B is:" << endl;
  A.intersectionOfSets(B);
  
  A.isEqualTo(B);
  cout << endl;
  
  cout << "What element would you like to insert into set A?: ";
  cin >> val;
  A.insertElement(val);
  
  cout << endl << "Set A is now:" << endl;
  A.printSet();
  cout << endl << endl;
  
  cout << endl << "Deleting " << val << " from set A...";
  A.deleteElement(val);
  cout << endl << "Set A is now:" << endl;
  A.printSet();
  
  cout << endl << "Now creating a set of specific values and testing the bounds limits.";
  cout << endl << "Creating array of size 10: {25, 67, 2, 9, 99, 105, 45, -5, 100, 1}";
  int arr[10] = {25, 67, 2, 9, 99, 105, 45, -5, 100, 1};
  cout << endl;
  IntegerSet testArr(arr, 10);
  
  int arrC[8] = {1, 2, 9, 25, 45, 67, 99, 100};
  cout << endl << "Set C is:" << endl;
  IntegerSet C(arrC, 8);
  C.printSet();
  cout << endl;
  
  return 0;
}
