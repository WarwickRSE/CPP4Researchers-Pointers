/* PLAIN WRONG */
#include <iostream>

struct a_class{

  int data= 73;
  int data2;
  a_class(){data2=37;}
  int do_a_thing(){return data;}

};

int main(){

  a_class * thng;

  // Do an INVALID malloc operation for 2 of a_class
  thng = (a_class*) malloc(2 * sizeof(a_class));

  // We have enough memory now, but we do not have any a_class entities
  // We can see this because the value a_class would have for
  // data is not there. My system has 0 - yours may also have all kinds of junk
  std::cout<<thng->data<<" "<<(thng+1)->data<<'\n';
  std::cout<<thng->data2<<" "<<(thng+1)->data2<<'\n';



};
