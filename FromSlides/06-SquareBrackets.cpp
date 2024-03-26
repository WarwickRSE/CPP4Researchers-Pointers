/* OLD SCHOOL */
#include <iostream>

int main(){

  // One way to get a compile-time sized array is like this:
  int arr[5];
  std::cout<<"arr can hold "<<sizeof(arr)/sizeof(int)<<" integers\n";
  std::cout<<"With pointer arithmetic we also see there is room for ";
  std::cout<<(&arr[4] - &arr[0] + 1)<<" integers\n";
  // +1 here for fence-post issue - &arr[4] is the address of the start of the last data item
  // |  |  |  |
  // i     j  k  - j is position of 3rd item, i to k is length of data

  // This is a pointer to stack memory sufficient for 5 items
  // We get the items with [] too, like arr[0]
  // It looks like array subscripting but really all the []
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


  // Now knowing [] is just de-reference we can do layers of them:
  int arr2d[5][5];
  std::cout<<"Size should be 25: "<<sizeof(arr2d)/sizeof(int)<<'\n';
  // Set values before we use them!
  for(int i = 0; i<5;++i){
    for(int j=0; j<5;++j){
      arr2d[i][j] = 0;
    }
  }

  //Probably see these addresses are 20 = 4 * 5 apart (if you know hex...)
  std::cout<<"First layer: "<<arr2d[0]<<" "<<arr2d[1]<<'\n';
  std::cout<<"Second layer: "<<arr2d[0][0]<<" "<<arr2d[0][1]<<'\n';

};
