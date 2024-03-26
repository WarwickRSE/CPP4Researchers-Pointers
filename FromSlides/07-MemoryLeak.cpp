/* OLD SCHOOL and PLAIN WRONG */
#include <iostream>

// Get an integer on heap and return pointer
int * get_int(){
  int * tmp = new int;
  *tmp = 10;
  return tmp;
}

int main(){

  int * a = get_int(); // OK
  std::cout<<*a<<std::endl;

  get_int(); // Memory leak - pointer thrown away

  int * ptr=nullptr; // EVEN IN BAD CODE I always init to nullptr.

  // Nasty memory leak - many integers in our program memory space we cannot destroy
  // Compiler is helpless, need tools
  for( int i = 0; i < 100000; ++i){
    // Giving ptr new value abandons the old one
    ptr = get_int();
  }

  // NO LEAKS HERE:
  for( int i = 0; i < 100000; ++i){
    if(ptr) delete ptr; // Clean up before repointing!
    ptr = get_int();
  }


};
