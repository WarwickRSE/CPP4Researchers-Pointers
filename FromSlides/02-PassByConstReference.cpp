/* UP TO DATE */
#include <iostream>

// Takes a copy - may take variables or literals
void fn(int a){};

// Takes a reference - can only take variables
void fn2(int & b){};

// Takes a const reference - can take variables or literals and wont copy
void fn3(const int & c){};

int main(){

  int arg = 10;

  fn(arg);
  fn(10);

  fn2(arg);
//  fn2(10); // This line cannot compile - what if fn2 changes its argument

  fn3(arg);
  fn3(10); // This is OK - fn3 CANNOT change its argument


};
