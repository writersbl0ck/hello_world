// Credit to Dr. T for naming and formatting ideas
#include <iostream>
#include <iomanip>
#include "functions.h"



int main() {
  cout << fixed << setprecision(4);
  string option = "";
  string color = "\x1b[" + to_string(32) + ";1m"; // changes color user input value to green
  string reset = "\x1b[0m";                       // resets console color to white
  
  do{
    showMenu();
    cout << color;
    //option = validateString(option);
    cin >> option;
    cout << reset;
    handleOption(option);
  }while(option != "e" && option != "E");

  return 0;
}
