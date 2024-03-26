/* PLAIN WRONG */
#include <iostream>

int main(){

  int * p;
  std::cout<<*p<<std::endl;

  //What will this do?
  /*
    1. Print some nonsense
    2. Fail to compile
    3. Segfault (invalid memory access)
    4. Anything it likes, it's undefined behaviour
  */

};
