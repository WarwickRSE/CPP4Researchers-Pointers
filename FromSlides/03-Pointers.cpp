/* OLD SCHOOL */
#include <iostream>

int main(){

  // Some data
  int data = 10;

  //A pointer to the data
  int * p;
  // Has to be the right type

  // p can be pointed to any integer we like
  // Point it to data:
  p = &data; // Take the address of data with '&' (address of) and store this value

  // Printing p will probably show as a hex address, 0x...
  std::cout<<p<<'\n';

  // Get the data back with the * operator (dereference)
  // Yes, * is used for two tasks. There are only so many symbols
  int data2= *p; // Now data2 = 10 and is a new COPY

  // Print data, and data using p
  std::cout<<data<<" "<<*p<<"\n";

  // Increment data using p
  *p += 1;

  // data is affected, data2 is a copy and is not!
  std::cout<<data<<" "<<data2<<'\n';

  int a=73, b=37;

  //There is a good chance one or other of the following will SEEM to print the value of the other variable
  // On my machine, a happens to follow b, so the second one prints 73 BUT IT IS COMPLETELY UNDEFINED BEHAVIOUR!
  // Using a pointer to access any memory other than that to which it points is not OK
  // The compiler is free to do anything it likes. Pointers are only memory addresses until they are not
  // Will we come back to this point. A lot.
  std::cout<<*(&a+1)<<'\n';
  std::cout<<*(&b+1)<<'\n';

};
