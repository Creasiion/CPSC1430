//Imani Cage
//File Car.h
//Holds the class Car

#include <iostream>
using namespace std;

class Car{
private:
  int yearModel;
  string make;
  int speed;
  
public:
  Car(int model, string brand );
  int getCarModel();
  string getCarMake();
  int getCarSpeed();
  int accelerate();
  int brake();

};
