/* OLD SCHOOL and PLAIN WRONG */
// Expect 5 compilation errors from this code, from lines marked // Invalid

int main(){

  //Const is a handy keyword to prevent accidental modification
  // With pointers have to separate two things:
  //  const-ness of the pointer itself
  //  const-ness of the data it points to
  // Where you put the const word relative to the * matters!
  // Roughly read right to left, reading '*' as pointer

  int data = 10;

  int * const a = &data; //A const pointer to an int
   ++(*a); // OK - data not const
  a = nullptr; // Invalid, cannot modify pointer

  int const * b = &data; //A pointer to a const int
  ++(*b); // Invalid, cannot modify data using pointer
  b = nullptr; // OK - pointer not const
  const int * b2 = &data; // Also pointer to const int
  ++(*b2); // Invalid
  b2 = nullptr;

  const int * const c = &data;// Both - const pointer to const int
  ++(*c); // Invalid
  c = nullptr; // Invalid

}
