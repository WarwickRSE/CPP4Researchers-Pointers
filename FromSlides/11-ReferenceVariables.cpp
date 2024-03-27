/* UP TO DATE */
#include <iostream>
#include <vector>
#include <initializer_list>

// Here's how to return a reference. See comment below about dangers of this!
int & element(std::vector<int> & vec_in, int index){
  // Silly function to get an element from a vector
  return vec_in.at(index);
}

int main(){

  std::vector<int> myvec;
  myvec.resize(10); // NOTE - new elements _are_ initialised when we do this

  int & a = myvec[5]; //Reference to a value in the vector. Valid as long as myvec exists AND
                      // we do nothing that will force myvec to reallocate memory,
                      // such as add to it or resize it. A DANGEROUS promise to make!

  std::cout<<"Before update: "<<myvec[5]<<std::endl;
  a = 6;
  std::cout<<"After update: "<<myvec[5]<<std::endl;


  // Container type loop:
  for(auto item : myvec){
    ++item;
  }
  // Each item in there is a COPY of an element.
  std::cout<<"After loop: "<<myvec[5]<<std::endl;

  // Apply reference spec to item
  for(auto & item : myvec){
    ++item;
  }
  // Each item in there is reference to an element
  std::cout<<"After reference loop: "<<myvec[5]<<std::endl;

{
   std::cout<<"Before change: "<<myvec[1]<<std::endl;
  // Take a guess what this will do:
  // Then try it and see:
  auto el = element(myvec, 1);
  ++el;
  std::cout<<"After change: "<<myvec[1]<<std::endl;
}
  //Spoiler gap!





















{
  //If you expected ++el to affect the vector elements, no it wont
  // el is not a reference, it's a copy. Even though we might expect
  // auto to know the the RHS is a reference, it is not able to apply the specifier for us
  // Be CAREFUL with auto and references - its up to you!
  std::cout<<"Before change: "<<myvec[1]<<std::endl;
  auto & el = element(myvec, 1);
  ++el;
  std::cout<<"After change: "<<myvec[1]<<std::endl;
}

}
