//Imani Cage
//lab4.cpp
//Main function that runs the header and function files

#include <iostream>
#include "Car.h"
using namespace std;


int main(){
  cout << "Declaring an object of Car" << endl;
  Car example(2022, "Honda");
  
  
  cout << "Showing the values of the object" << endl;
  cout << "Car Model: " << example.getCarModel() << endl;
  cout << "Make: " << example.getCarMake() << endl;
  cout << "Current speed: " << example.getCarSpeed() << endl << endl;
  
  cout << "Now we will call the accelerator function" << endl;
  
  for(int i = 0; i < 5; i++){
    cout << i + 1 << " time calling the accelerator" << endl;
    example.accelerate();
    cout << "Current speed: " << example.getCarSpeed();
    cout << endl;
  }
  
  cout << endl << endl;
  cout << "This is what the object looks like now" << endl;
  cout << "Car Model: " << example.getCarModel() << endl;
  cout << "Make: " << example.getCarMake() << endl;
  cout << "Current speed: " << example.getCarSpeed() << endl << endl;
  
  cout << "Now we will be calling the brake function." << endl;
  for(int i = 0; i < 5; i++){
    cout << i + 1 << " time calling the brakes" << endl;
    example.brake();
    cout << "Current speed: " << example.getCarSpeed();
    cout << endl;
  }
  
  cout << endl << endl;
  cout << "This is what the object looks like now" << endl;
  cout << "Car Model: " << example.getCarModel() << endl;
  cout << "Make: " << example.getCarMake() << endl;
  cout << "Current speed: " << example.getCarSpeed() << endl;
  cout << endl << endl;
  
  return 0;
  
}
