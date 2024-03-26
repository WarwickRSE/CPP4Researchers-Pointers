/* OLD SCHOOL and PLAIN WRONG */
#include <iostream>

int main(){

  //Saw that arr[10][10] is a 2-d compile time sized array
  //Might try and do the same for the heap with pointer to pointer

  //Naively:
  int sz = 10;
  int ** arr2d;
  arr2d = (int**) malloc(sz * sizeof(int*));
  for(int i=0; i<sz; ++i){
    arr2d[i] = (int*)malloc(sz*sizeof(int));
  }

  for(int i=0; i<sz; ++i){
    for(int j=0; j<sz; ++j){
      arr2d[i][j] = (i+1)*(j+1);
    }
  }
  for(int i=0; i<sz; ++i){
    for(int j=0; j<sz; ++j){
      std::cout<<arr2d[i][j]<<", ";
    }
    std::cout<<'\n';
  }

  //Looks OK! What's wrong?
  // This may print 100. it usually wont!
  std::cout<<"Size of array in items is: "<<(&arr2d[sz-1][sz-1] + 1 - &arr2d[0][0])<<std::endl;

  // Each "row" could be all over the place in memory!
  for(int i=1; i<sz; ++i){
    std::cout<<"Expect 10, got: "<<arr2d[i] - arr2d[i-1]<<'\n';
  }

  //Problem on line 14 - each malloc is separate action! No guarantee of contiguity

  // Old-school solution:
  int ** arr2d_s;
  arr2d_s = (int **) malloc(sz * sizeof(int*));

 {// Use a block because then tmp wont hang about
  int * tmp; // Will be the actual array memory
  tmp = (int*) malloc(sz*sz*sizeof(int));
  for(int i=0; i< sz; ++i){
    // Setup pointers to each row within tmp
    arr2d_s[i] = tmp;
    tmp += sz;
  }
 }

  for(int i=0; i<sz; ++i){
    for(int j=0; j<sz; ++j){
      arr2d_s[i][j] = (i+1)*(j+1);
    }
  }

  for(int i=0; i<sz; ++i){
    for(int j=0; j<sz; ++j){
      std::cout<<arr2d_s[i][j]<<", ";
    }
    std::cout<<'\n';
  }

}
