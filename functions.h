#include <iostream>
#include "Input_Validation_Extended.h"
using namespace std;

// function prototypes
void showMenu(); 
void handleOption(string); 
double calcVelocity(double, double); 
double calcAcceleration(double, double); 
void motionMenu(); 
void motionFormulas(string); 
void calcMa();
void calcMs();
void calcMv2();
void calcMv();
double calcNewt2ndLaw(double, double); 
double calcWeight(double, double); 
double calcMomentum(double, double); 

// global variables
string resultColor = "\x1b[" + to_string(36) + ";1m";
string reset = "\x1b[0m";

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
  double ds = 0.0; // displacement
  string dsUnits;
  double dt = 0.0;
  string dtUnits; // time
  double dv = 0.0;
  string dvUnits; // velocity
  string motionOption;
  double m = 0.0; // mass
  string mUnits;
  double a = 0.0; // acceleration
  string aUnits;
  double g = 0.0; // gravity
  string wUnits; // unit of weight
  double v = 0.0;
  string pUnits; // unit of momentum
  
  if(userOption == "V" || userOption == "v"){
    cout << "You have chosen to calculate Velocity." << endl;
    cout << "The fomula for Velocity is v = ds / dt, where v is velocity, ds is displacement, and dt is time." << endl;
    cout << "Please enter a value for ds: ";
    ds = validateDouble(ds);
    cout << "\nPlease enter a unit for ds: ";
    dsUnits = validateString(dsUnits);
    cout << "\nPlease enter a value for dt: ";
    dt = validateDouble(dt);
    cout << "\nPlease enter a unit for dt: ";
    dtUnits = validateString(dtUnits);
    cout << "You input " << ds << " " << dsUnits << ", and " << dt << " " << dtUnits << "." << endl;
    cout << ds << " " << dsUnits << " / " << dt << " " << dtUnits << " = " << resultColor << calcVelocity(ds, dt) << " " << 
      dsUnits << "/" << dtUnits << reset << endl;
  }
  else if(userOption == "A" || userOption == "a"){
    cout << "You have chosen to calculate Acceleration." << endl;
    cout << "The formula for Acceleration is a = dv / dt, where a is acceleration, dv is velocity, and dt is time." << endl;
    cout << "Please enter a value for dv: ";
    dv = validateDouble(dv);
    cout << "\nPlease enter a unit for dv: ";
    dvUnits = validateString(dvUnits);
    cout << "\nPlease enter a value for dt: ";
    dt = validateDouble(dt);
    cout << "\nPlease enter a unit for dt: ";
    dtUnits = validateString(dtUnits);
    cout << "You input " << dv << " " << dvUnits << ", and " << dt << " " << dtUnits << "." << endl;
    cout << dv << " " << dvUnits << " / " << dt << " " << dtUnits << " = " << resultColor << calcAcceleration(dv, dt) << " " << 
      dvUnits << "/" << dtUnits << reset << endl;
  }
  else if(userOption == "M" || userOption == "m"){
    cout << "You have chosen to calculate Motion." << endl;
    motionMenu();
    cin >> motionOption;
    motionFormulas(motionOption);
  }
  else if(userOption == "N" || userOption == "n"){
    cout << "You have choseen Newton's 2nd Law." << endl;
    cout << "This law is often used to calculate net force as N = ma, where N is net forcse, m is mass, and a is acceleration." << endl;
    cout << "Please enter a value for m: ";
    m = validateDouble(m);
    cout << "\nPlease enter a unit for m: ";
    mUnits = validateString(mUnits);
    cout << "\nPlease enter a value for a: ";
    a = validateDouble(a);
    cout << "\nPlease enter a unit for a: ";
    aUnits = validateString(aUnits);
    cout << "You input " << m << " " << mUnits << ", and " << a << " " << aUnits << "." << endl;
    cout << m << " " << mUnits << " * " << a << " " << aUnits << " = " << resultColor << calcNewt2ndLaw(m, a) << " " << 
      mUnits << " " << aUnits << reset << endl;
  }
  else if(userOption == "W" || userOption == "w"){
    cout << "You have chosen to calculate Weight." << endl;
    cout << "The formula for Weight is W = mg, where W is Weight, m is mass, and g is gravity." << endl;
    cout << "Please enter a value for m: ";
    m = validateDouble(m);
    cout << "\nPlease enter a value for g: ";
    g = validateDouble(g);
    cout << "\nPlease enter a unit of weight: ";
    wUnits = validateString(wUnits);
    cout << "You input " << m << " and " << g << "." << endl;
    cout << m << " * " << g << " = " << resultColor << calcWeight(m, g) << " " << 
      wUnits << reset << endl;
  }
  else if(userOption == "P" || userOption == "p"){
    cout << "You have chosen to calculate Momentum." << endl;
    cout << "The formula for Momentum is P = mv, where P is momentum, m is mass, and v is velocity." << endl;
    cout << "Please enter a value for m: ";
    m = validateDouble(m);
    cout << "\nPlease enter a value for v: ";
    v = validateDouble(v);
    cout << "\nPlease enter a unit of momentum: ";
    pUnits = validateString(pUnits);
    cout << "You input " << m << " and " << v << "." << endl;
    cout << m << " * " << v << " = " << resultColor << calcMomentum(m, v) << " " << 
      pUnits << reset << endl;
  }
  else if(userOption == "X" || userOption == "x"){
    system("clear");
  }
  else if(userOption == "E" || userOption == "e"){
    cout << "See ya!" << endl;
  }
  else{
    cout << "Invalid Input. Please enter one of the following choices:" << endl;
  }
}

double calcVelocity(double ds, double dt){
  return ds / dt;
}

double calcAcceleration(double dv, double dt){
  return dv / dt;
}

void motionMenu(){
  cout << "You really chose the most complex option, but I'm glad, because otherwise I gave myself this headache for nothing. Which formula would you like to use?: " << endl;
  cout << "Ma = solve for v" << endl;
  cout << "Ms = solve for s" << endl;
  cout << "Mv2 = solve for v^2" << endl;
  cout << "Mv = solve for v_bar" << endl;
}

void motionFormulas(string option){
  if (option == "Ma" || option == "ma"){
   calcMa();
  }
  else if (option == "Ms" || option == "ms"){
    calcMs();
  }
  else if (option == "Mv2" || option == "mv2"){
    calcMv2();
  }
  else if (option == "Mv" || option == "mv"){
    calcMv();
  }
  else{
    cout << "Invalid input" << endl;
  }
}

void calcMa(){
  double v = 0.0;
  double v0 = 0.0;
  double a = 0.0;
  double t = 0.0;
  
  cout << "You have chosen Ma = solve for v." << endl;
  cout << "The formula for Ma is v = v0 + at, where v0 is initial velocity, t is time, a is acceleration, and v is velocity after this time." << endl;
  cout << "Please enter a value for v0: ";
  v0 = validateDouble(v0);
  cout << "\nPlease enter a value for a: ";
  a = validateDouble(a);
  cout << "\nPlease enter a value for t: ";
  t = validateDouble(t);
  v = v0 + (a * t);
  cout << "You input " << v0 << ", " << a  << ", and " << t << "." << endl;
    cout << v0 << " + " << "(" << a << " * " << t << ")" << " = " << resultColor << v << reset << endl;
}

void calcMs(){
  double s = 0.0;
  double s0 = 0.0;
  double v0 = 0.0;
  double t = 0.0;
  double a = 0.0;

  cout << "You have chosen MS = solve for s." << endl;
  cout << "The formula for Ms is s = s0 + v0t + (1/2)at^2." << endl;
  cout << "Please enter a value for s0: ";
  s0 = validateDouble(s0);
  cout << "\nPlease enter a value for v0: ";
  v0 = validateDouble(v0);
  cout << "\nPlease enter a value for t: ";
  t = validateDouble(t);
  cout << "\nPlease enter a value for a: ";
  a = validateDouble(a);
  s = s0 + (v0 * t) + ((1/2) * a * (t * t));
  cout << "You input " << s0 << ", " << v0 << ", " << t << ", and " << a << "." << endl;
  cout << s0 << " + " << "(" << v0 << " * " << t << ")" << " + " << "((1/2) " << " * " 
    << a << " * " << t << "^2" << " = " << resultColor << s << reset << endl;
}

void calcMv2(){
  double s = 0.0;
  double s0 = 0.0;
  double v0 = 0.0;
  double t = 0.0;
  double a = 0.0;
  double v2 = 0.0;
  
  cout << "You have chosen Mv2 = solve for v^2." << endl;
  cout << "The formula for Mv2 is v^2 = v0^2 + 2a(s - s0)." << endl;
  cout << "Please enter a value for s0: ";
  s0 = validateDouble(s0);
  cout << "\nPlease enter a value for v0: ";
  v0 = validateDouble(v0);
  cout << "\nPlease enter a value for s: ";
  s = validateDouble(s);
  cout << "\nPlease enter a value for a: ";
  a = validateDouble(a);
  v2 = (v0 * v0) + (2 *a) * (s - s0);
  cout << "You input " << s0 << ", " << v0 << ", " << s << ", and " << a << "." << endl;
  cout << v0 << "^2 + " << "(2 * " << a << ")(" << s << " - " << s0 << ")" << " = " << resultColor << v2 << reset << endl;
}

void calcMv(){
  double v_bar = 0.0;
  double v = 0.0;
  double v0 = 0.0;

  cout << "You have chosen Mv = solve for v_bar." << endl;
  cout << "The formula for Mv is v_bar = (1/2)(v + v0)." << endl;
  cout << "Please enter a value for v: ";
  v = validateDouble(v);
  cout << "\nPlease enter a value for v0: ";
  v0 = validateDouble(v0);
  v_bar = (1/2) * (v + v0);
  cout << "You input " << v << " and " << v0 << "." << endl;
  cout << "(1/2)(" << v << " + " << v0 << " = " << resultColor << v_bar << reset << endl;
}

double calcNewt2ndLaw(double m, double a){
  return m * a;
}

double calcWeight(double m, double g){
  return m * g;
}

double calcMomentum(double m, double v){
  return m * v;
}
