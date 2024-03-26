/* PLAIN WRONG */
#include <iostream>

struct a_class{

  int data= 73;
  int data2;
  a_class(){data2=37;}
  int do_a_thing(){return data;}

};

int main(){

  a_class * thng = new a_class[2];

  // We have a 2 element array of a_class now
  // And the members have correct values
  std::cout<<thng->data<<" "<<(thng+1)->data<<'\n';
  std::cout<<thng->data2<<" "<<(thng+1)->data2<<'\n';

};
