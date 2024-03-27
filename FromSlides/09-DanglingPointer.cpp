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


};
