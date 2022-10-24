#include <iostream>
//#include <stdlib>
#include <iomanip>
#include "Input_Validation_Extended.h"

// function prototypes
void showMenu();
void handleOption(string);


int main() {
  string option = "";
  string color = "\x1b[" + to_string(32) + ";1m"; // changes color user input value to green
  string reset = "\x1b[0m";                       // resets console color to white
  
  do{
    showMenu();
    cout << color;
    option = validateString(option);
    cout << reset;
    handleOption(option);
  }while(option != "e" && option != "E");

  return 0;
}

// function definitions
void showMenu(){
  cout << "\nMenu" << endl;
  cout << "V = Calculate Velocity" << endl;
  cout << "A = Calculate Acceleration" << endl;
  cout << "M = Calculate Motion" << endl;
  cout << "N = Calculate Newton's 2nd Law" << endl;
  cout << "W = Calculate Weight" << endl;
  cout << "P = Calculate Momentum" << endl;
  cout << "X = Clear Screen" << endl;
  cout << "E = Exit" << endl;
}

void handleOption(string userOption){
  if(userOption == "V" || userOption == "v"){
    cout << "Velocity" << endl;
  }
  else if(userOption == "A" || userOption == "a"){
    cout << "Acceleration" << endl;
  }
  else if(userOption == "M" || userOption == "m"){
    cout << "Motion" << endl;
  }
  else if(userOption == "N" || userOption == "n"){
    cout << "Newton's 2nd Law" << endl;
  }
  else if(userOption == "W" || userOption == "w"){
    cout << "Weight" << endl;
  }
  else if(userOption == "P" || userOption == "p"){
    cout << "Momentum" << endl;
  }
  else if(userOption == "X" || userOption == "x"){
    system("clear");
  }
  else if(userOption == "E" || userOption == "e"){
    cout << "See ya!" << endl;
  }
  else{
    cout << "Invalid Input" << endl;
  }
}





