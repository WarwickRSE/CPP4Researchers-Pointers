/* PLAIN WRONG */
#include <iostream>
#include <vector>

int main(){

  std::vector<int> data;
  data.resize(10);

  int & item = data[5];
  item = 6;

  std::cout<<"Item before (expect 6): "<<item<<'\n';

  // Checking if vector actually moved in memory
  auto addr = &data[0];
  data.resize(100); //A big number - likely to need a new memory location
                    // Turn this up if address of data[0] does not change
  auto addr_after = &data[0];
  if(addr == addr_after) std::cout<<"Vector did not move, this test will seem to work\n";

  std::cout<<"Item after move (expect 6): "<<item<<std::endl;
  ++item;

  std::cout<<"Actual item in vector after increment (expect 7): "<<data[5]<<'\n';


}
