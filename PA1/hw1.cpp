//Imani Cage
//hw1.cpp
//Purpose: Process and analyze the data of COVID. 
//Allows user to select what to do with the data:
//display the COVID info of all states, display the one with the most cases or deaths, or display basic stat info.

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <stdio.h>
using namespace std;

struct State
{
    string date;
    string name;
    int fip;
    int cases;
    int deaths;
};


void clrScreen();
void menuScreen(int& option);
void menuOne(const State* arr, int numE);
void menuTwo(const State* arr, int numE);
void menuThree(const State* arr, int numE);
void menuFour(const State* arr, int numE);

const int NAME_SPACES = 25;
const int STANDARD_SPACES = 20;

int main(){

    State* covidCases;
    int stateCount = 0;
    int menuOption;
    string fileOption;
    string line;
    string FILENAME;

    cout << endl << endl;
    cout << "Please enter the input file name (covid_input1.txt or covid_input2.txt): ";
    cin >> FILENAME;

    ifstream infile;
    infile.open(FILENAME);
    if(infile.fail()){
        cout << "File error: exiting program. Please try again.";
        cout << endl << endl;
        return 0;
    }else{
      while(getline(infile,line)){
        stateCount++;
      }
    }
    infile.close();
    infile.open(FILENAME);
    covidCases = new State[stateCount];
    //inputting all of the data into a structural array
    for(int i = 0; i < stateCount; i++){ 
      istringstream data(line);
      getline(infile, line, ','); //getline necessary to break apart the values that are comma-separated within the file
      covidCases[i].date = line;
      getline(infile, line, ',');
      covidCases[i].name = line;
      getline(infile, line, ',');
      covidCases[i].fip = stoi(line); //stoi used to convert numeric string data to ints
      getline(infile, line,',' );
      covidCases[i].cases = stoi(line);
      getline(infile, line);
      covidCases[i].deaths = stoi(line);
    }
    infile.close();
    
    cout << endl << endl;

    menuScreen(menuOption);

    while(menuOption < 5 && menuOption >= 1){
      
      switch(menuOption){
      case 1:
        menuOne(covidCases, stateCount);
        menuScreen(menuOption);
        break;
      case 2:
        menuTwo(covidCases, stateCount);
        menuScreen(menuOption);
        break;
      case 3:
        menuThree(covidCases, stateCount);
        menuScreen(menuOption);
            break;
      case 4:
        menuFour(covidCases, stateCount);
        menuScreen(menuOption);
        break;
      }
    }
    clrScreen(); //Used as a way to signify exit of program
    delete [] covidCases;
    return 0;
}


void menuScreen(int& option){
  cout << endl << endl;
        cout << "************Menu************";
        cout << endl << "1. Display the COVID info of all states";
        cout << endl << "2. Display the COVID info of the state that has the most cases";
        cout << endl << "3. Display the COVID info of the state that has the most deaths";
        cout << endl << "4. Display the statistics of all states";
        cout << endl << "5. Exit the program";
        cout << endl << "Enter your choice: ";
        cin >> option;
}


void clrScreen(){
  for(int i = 0; i < 25; i++){
    cout << endl;
  }
}

void menuOne(const State* arr, int numE){
  cout << endl << endl;
  cout << setw(NAME_SPACES) << "**States**"  << setw(STANDARD_SPACES) << "**Cases**" << setw(STANDARD_SPACES) << "**Deaths**";
  cout << endl;
  for(int i = 0; i < numE; i++){
    cout << endl;
    cout << setw(NAME_SPACES) << arr[i].name << setw(STANDARD_SPACES) << arr[i].cases << setw(STANDARD_SPACES) << arr[i].deaths;
  }
}

void menuTwo(const State* arr, int numE){
  int mostCases = 0;
  for(int i = 0; i < numE; i++){
    if(arr[i].cases > arr[mostCases].cases){
      mostCases = i;
    }
  }
  cout << endl << endl;
  cout << arr[mostCases].name << " has the most cases: " << arr[mostCases].cases;
}

void menuThree(const State* arr, int numE){
  int mostDeaths = 0;
  for(int i = 0; i < numE; i++){
    if(arr[i].deaths > arr[mostDeaths].deaths){
      mostDeaths = i;
    }
    }
  cout << endl << endl;
  cout << arr[mostDeaths].name << " has the most deaths: " << arr[mostDeaths].deaths;
  
}
void menuFour(const State* arr, int numE){
  int sumCases = 0;
  int sumDeaths = 0;
  double avgDeathRate = 0.0;
  double deathRateC = 0.0;
  double highestRate= 0.0; 
  int stateHighestRate = 0; //gives the index of the state with the highest death rate

  for(int i = 0; i < numE; i++){
    sumCases += arr[i].cases;
    sumDeaths += arr[i].deaths;
  }
  
    avgDeathRate = ((double)sumDeaths/(double)sumCases) * 100.0;

    
    cout << endl;
    cout << "(a) There are " << sumCases << " cases in total, " << sumCases/numE << " on average.";
    cout << endl;
    cout << "(b) There are " << sumDeaths << " deaths in total, " << sumDeaths/numE << " on average.";
    cout << endl;
    cout << "(c) The average death rate for all states is " << setprecision(3) << avgDeathRate << "%";
    
    //loop calculating and comparing death averages to see which one is bigger

      for(int c = 0; c < numE; c++) {
        if(arr[c].deaths > 100){
          deathRateC =((double)arr[c].deaths/(double)arr[c].cases) * 100.0;
          highestRate = ((double)arr[stateHighestRate].deaths/(double)arr[stateHighestRate].cases) * 100.0;

        if(deathRateC > highestRate){
          highestRate = deathRateC;
          stateHighestRate = c;
          }
        }else{
          continue; //Continues the rest of the for loop without changing the value of c
      }
    } // end of for loop

    cout << endl;
    cout << "(d) Among all states that have more than 100 deaths, " << arr[stateHighestRate].name
         << " has the highest death rate of " << setprecision(3) << highestRate << "%";
}
