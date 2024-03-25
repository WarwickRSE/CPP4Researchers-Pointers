/* OLD SCHOOL */
#include <iostream>

int main(){

  //Actually all of the arrays you can get like this:
  int arr[5];
  // are mostly just pointers, and all the []
  // does is add the two sides together and dereference
  // While it looks like an assymmetric operation, the standard
  // specifically says it commutes
  // So you can, confusingly, write any of these:

  arr[0] = 0;  //OK
  *(arr+1) = 1;  //Alright, but harder to read
  *(2+arr) = 2; // Really hard to read now
  *(&arr[0]+3) = 3;  // Look, I have all these symbols and I want to use them OK!
  4[arr] = 4; // Yes this works. PLEASE PLEASE NO DO NOT DO THIS! PLEASE!

  for(int i = 0; i < 5; ++i){
    std::cout<< arr[i]<<'\n';
  }

  // Now is a good time to remind you: Pointers are NOT memory addresses
  // They look like them. They often have the same values. But to the compiler, they are more
  // arr is a pointer, and we can use it to get to the values at arr[0] through arr[4].
  // arr[17] is not just some random data - it is completely undefined behaviour!
  // Trying to use the value at arr+17 does not let us access that memory, it is just meaningless
};
