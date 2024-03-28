/* PLAIN WRONG */
#include <iostream>

int main(){

  int * p = nullptr;

{ // Open a scope block
  int data = 10;
  p = &data;
  std::cout<<"Data is: "<<*p<<'\n';
}
  //data no longer exists - using p is invalid
  std::cout<<"Data is: "<<*p<<" or is it?\n";

//Moderate chance that this will work:
  *p = 11;
  std::cout<<"Data is: "<<*p<<" or is it?\n";

// By the way, the reason this usually works is that until
// we create new data in that location, or something else
// is given the "use of it" nothing much will happen
// You might expect the below to show a problem:

  int new_data = 7;
  std::cout<<"Data is still: "<<*p<<" or is it?\n";

// but it probably wont. data and new_data are automatic
// variables, meaning probably on the stack. Stack grows linearly
// so we wont get handed that memory location again
// Heap memory, depending on system, tends to get re-used
// and we are _likely_ to get the same bit we just freed
// Below shows another reason 'new' is dangerous! We could easily
// not spot that p is COMPLETELY INVALID in all the code below!

  int * hp_data = new int;
  *hp_data = 8;
  p = hp_data;
  delete hp_data;
  // Next might print 8, on many modern systems it'll be junk
  std::cout<<"Heap data is at: "<<p<<" and is "<<*p<<"\n";
  int * hp_data2 = new int;
  *hp_data2 = 9;
  // Decent chance the hp_data2 is same location as hp_data and so:
  std::cout<<"New alloc is at: "<<hp_data2<<std::endl;
  std::cout<<"Heap data is: "<<*p<<" or is it?\n";

  // IMPORTANT: although p has the same value as hp_data2 we
  // CANNOT use it safely. This is why we say pointers are not addresses
  // Will it ever cause problems? Maybe not, but risk is there

};
