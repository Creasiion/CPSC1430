#include <iostream>
#ifndef Player_h
#define Player_h
using namespace std;

class Player{
private:
  string playerName;
  int * playerGuess;
  int totalGames;

public:
  Player(string name, int totalGames);
  ~Player(); //deconstructor
  void guessNum(); 
  int getNum(int index);
  void getWinner(Player& p2);
};
#endif
