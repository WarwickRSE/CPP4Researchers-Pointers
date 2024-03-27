/* OLD SCHOOL */
#include <iostream>

int main(){

  // Some data
  int data = 10;

  //A pointer to the data
  int * p = nullptr;
  // Has to be the right type
  // Created with no particular value, so we should always set it

  // p can be pointed to any integer we like
  // Point it to data:
  p = &data; // Take the address of data with '&' (address of) and store this value

  // Printing p will probably show as a hex address, 0x...
  std::cout<<"pointer value is a hex number: "<<p<<'\n';

  // Get the data back with the * operator (dereference)
  // Yes, * is used for two tasks. There are only so many symbols
  int data2= *p; // Now data2 = 10 and is a new COPY

  // Print data, and data using p
  std::cout<<"data is: "<<data<<" data accessed via p is: "<<*p<<"\n";

  // To be safe, we should check p is not nullptr before using it
  // Special short-cut: nullptr becomes false as a boolean, anything else true
  if(p){
    std::cout<<"p is not nullptr\n";
  }

  // Increment data using p
  *p += 1;

  // data is affected, data2 is a copy and is not!
  std::cout<<"data after increment: "<<data<<" copy of data not affected by increment: "<<data2<<'\n';

  // Pointers like p are variables too - we can have pointers to pointers
  int ** q = &p; // q is a pointer to pointer to int. *q is a pointer to int, equal to p. **q is data
  std::cout<<"q: "<<q<<" *q, same as p: "<<*q<<" **q, same as data: "<<**q<<'\n';


  /* PLAIN WRONG */
  int a=73, b=37;

  //There is a good chance one or other of the following will SEEM to print the value of the other variable
  // On my machine, a happens to follow b, so the second one prints 73 BUT IT IS COMPLETELY UNDEFINED BEHAVIOUR!
  // Using a pointer to access any memory other than that to which it points is not OK
  // The compiler is free to do anything it likes.
  //Pointers only look like memory addresses. We can't use them like they actually are!
  // Will we come back to this point. A lot.
  std::cout<<"Trying to do something stupid, might seem to get 37?: "<<*(&a+1)<<'\n';
  std::cout<<"Trying to do something stupid again, might seem to give 73?:  "<<*(&b+1)<<'\n';
  /* END PLAIN WRONG */


};
