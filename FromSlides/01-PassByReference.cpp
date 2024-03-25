/* UP TO DATE */

#include <iostream>

// This class is going to tell us if it is ever copied
// It has no other purpose, except to pretend to be expensive
struct massive_data{
  // Constructor
  massive_data(){};
  // Copy constructor
  massive_data(const massive_data & other){std::cout<<" ***** I'm being copied, this may take some time ***** \n";}
};

int a_function(massive_data data){

  std::cout<<"I'm a function who got some massive_data\n";
  return 1;
};


// You can think of this & as just meaning "pass this argument by reference"
int a_function2(massive_data & data){

  std::cout<<"I'm a function who got some massive_data by reference\n";
  return 1;
};

int main(){

  massive_data arg;
  std::cout<<"This is pass by value:\n";
  a_function(arg);


  std::cout<<"This is pass by reference:\n";
  a_function2(arg);

};
