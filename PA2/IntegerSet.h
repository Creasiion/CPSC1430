#include <iostream>
#include <string>
#ifndef IntegerSet_h
#define IntegerSet_h
using namespace std;

const int MAX_SIZE = 101; //101 In order to have index 100: arr[100]
class IntegerSet{
private:
  int set[MAX_SIZE];
public:
  IntegerSet();
  IntegerSet(int arr[], int numE);
  void inputSet();
  void unionOfSets(IntegerSet b);
  void intersectionOfSets(IntegerSet b);
  void insertElement(int userInput);
  void deleteElement(int userInput);
  void printSet();
  bool isEqualTo(IntegerSet comparing);
  void emptySet();
  bool validEntry(int numCheck);
};
#endif
