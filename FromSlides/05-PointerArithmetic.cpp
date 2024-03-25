/* OLD SCHOOL */
#include <iostream>

int main(){

  //Pointers were used a lot in C to get memory in the "heap"
  // Early C++ used this too
  // So you would see things like this:

  int * data_p;

  data_p = (int*) malloc(10 * sizeof(int)); // Memory for 10 integers
  // Sizeof(int) is the number of bytes per integer, probably 4 or 8

  // Now data_p points to ten integers, starting at data_p
  // First value:
  *data_p = 1;
  // Second value - add one. Compiler "knows" this is a pointer to integer
  // so automatically adds enough bytes to jump one integer, again probably 4 or 8 bytes
  *(data_p+1) = 2;

  *(data_p+9) = 9; // Last valid value

  // Values from 2 to 8 may be junk or may be 0
  // DO NOT RELY ON ANYTHING!
  for(int i = 0; i < 10; ++i){
    std::cout<<i<<" "<<*(data_p + i)<<'\n';
  }


  // This line is NOT VALID
  *(data_p + 11) = 73; // Your compiler will NOT KNOW

};