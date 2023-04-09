//Imani Cage
//Car.cpp
//Implements functions from Car header

#include <iostream>
#include "Car.h"
using namespace std;

Car::Car(int model, string brand){
  yearModel = model;
  make = brand;
  speed = 0;
}

int Car::getCarModel(){
  return yearModel;
}

string Car::getCarMake(){
  return make;
}

int Car::getCarSpeed(){
  return speed;
}

int Car::accelerate(){
  int speedUp = 5;
  speed += speedUp;
  return speed;
}

int Car::brake(){
  int slowDown = 5;
  speed -= slowDown;
  return speed;
}
