/* UP TO DATE */

#include <iostream>

// This class is going to tell us if it is ever copied
// It has no other purpose, except to pretend to be expensive
// and to let us see if its value has been modified
struct massive_data{
  int value=0;
  // Constructor
  massive_data(){};
  // Copy constructor
  massive_data(const massive_data & other){std::cout<<" ***** I'm being copied, this may take some time ***** \n";value=other.value;}
};

void a_function(massive_data data){
  std::cout<<"I'm a function who got some massive_data\n";
  ++data.value;
};

// You can think of this & as just meaning "pass this argument by reference"
void a_function2(massive_data & data){
  std::cout<<"I'm a function who got some massive_data by reference\n";
  ++data.value;
};

int main(){

  massive_data arg;
  arg.value = 1; // Initial value

  std::cout<<"This is pass by value:\n";
  a_function(arg);
  std::cout<<"Value after: "<<arg.value<<'\n';

  std::cout<<"This is pass by reference:\n";
  a_function2(arg);
  std::cout<<"Value after: "<<arg.value<<std::endl;
};
