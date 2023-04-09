//Imani Cage
//lab5.cpp
#include <iostream>
#include "Player.h"
using namespace std;

int main(int argc, char *argv[]){
  int total;
  string p1Name;
  string p2Name;
    
  cout << endl << "Please enter the total number of games: ";
  cin >> total;
  
  cout << endl << "Please enter the name of the first player: ";
  cin >> p1Name;
  Player one(p1Name, total);
  one.guessNum();
  cout << endl << "Player " << p1Name << " selected the following numbers: ";
  for(int i = 0; i < total; i++){
    cout << " " << one.getNum(i) << " ";
  }
  
  cout << endl << endl;
  
  cout << endl << "Please enter the name of the second player: ";
  cin >> p2Name;
  Player two(p2Name, total);
  two.guessNum();
  cout << endl << "Player " << p2Name << " selected the following numbers: ";
  for(int i = 0; i < total; i++){
    cout << " " << two.getNum(i) << " ";
  }

  one.getWinner(two);
  return 0;
}
