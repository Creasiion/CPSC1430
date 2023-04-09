#include <iostream>
#include "Player.h"
using namespace std;

Player::Player(string name, int totalGames){
  playerName = name;
  playerGuess = new int[totalGames];
  this->totalGames = totalGames;
}
Player::~Player(){
  delete [] playerGuess;
}

void Player::guessNum(){
  int userGuess;
  for(int i = 0; i < totalGames; i++){
    cout << endl;
    cout << "Please enter a number at index " << i + 1 << " for player " << playerName << ": ";
    cin >> userGuess;
    playerGuess[i] = userGuess;
  }
}

int Player::getNum(int index){
  return playerGuess[index];
}

void Player::getWinner(Player& p2){   //Checking which player won
  int p1Win = 0;
  int p2Win = 0;
  for(int i = 0; i < totalGames; i++){ //check both players index to see which one is higher, and will add one to that round's winner
    if(getNum(i) > p2.getNum(i)){
      p1Win++;
    }else if(p2.getNum(i) > getNum(i)){
      p2Win++;
    }else{
      continue; //when players input the same number
    }
  }

   if(p1Win > p2Win){
    cout << endl << endl;
    cout << playerName << " Won";
    cout << endl;
  }else if(p2Win > p1Win){
    cout << endl << endl;
    cout << p2.playerName << " Won";
    cout << endl;
  } else {
    cout << endl << endl;
    cout << playerName << " and " << p2.playerName << " tied!";
    cout << endl;
  }
}