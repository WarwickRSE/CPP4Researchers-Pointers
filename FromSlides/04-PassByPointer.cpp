/* OLD SCHOOL */
#include <iostream>

// This function takes an integer by value
// The value we pass is unchanged in caller
void fn(int a){
  ++a;
};

// This function takes a pointer to an integer
// The pointer is passed by value, but the data is not passed at all
// We follow the pointer to get to the data
// Data in the caller is changed
void fn_p(int * a){

  // Inside here a is a pointer, and we have to dereference it
  // i.e. the data is (*a)
  int data = (*a); // Makes a copy of the data

  // Note precedence - we need these brackets
  // Otherwise we would increment the pointer, i.e the address
  ++(*a); // Affects whatever we passed

};

// This takes an integer by reference
// Data in the caller can be changed
void fn_r(int & a){
  // Notice how we don't have to do anything - we use a like a normal integer
  ++a;

};

int main(){

  int arg = 10;

  fn(arg);
  std::cout<<arg<<'\n'; // Unchanged, still 10

  // Have to take address with '&' explicitly
  fn_p(&arg);
  std::cout<<arg<<'\n'; // Incremented, now 11

  // Don't care that this expects a reference, we just pass arg
  fn_r(arg);
  std::cout<<arg<<'\n'; // Incremented again, now 12

};

