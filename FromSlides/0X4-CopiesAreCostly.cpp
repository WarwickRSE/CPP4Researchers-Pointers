/* UP TO DATE */
#include <iostream>
#include <vector>

class data{
 public:
  int a =1; //Pretend this is lots of memory

};

class heavy{
 public:
  data * lots_of_data; // Pretend this is costly to copy

  heavy(){lots_of_data = new data[100];}

  heavy(const heavy& other){
    lots_of_data = new data[100];
    for(int i=0;i<100;++i) lots_of_data[i].a = other.lots_of_data[i].a;
    std::cout<<"Copied a heavy object\n";
  } // COPY constructor

  heavy(heavy&& other)noexcept{
    lots_of_data = other.lots_of_data;
    other.lots_of_data =nullptr;
    std::cout<<"Moved the data instead\n";
  } // MOVE constructor. Note noexcept - this is needed or this can't be used

  ~heavy(){if(lots_of_data) delete[] lots_of_data;} // Notice [] on delete because we used it on new

};

int main(){

  std::vector<heavy> items;
  // Reserve some space for our first 2 elements to keep it simple
  items.reserve(3);

  std::cout<<"Push back is going to be a copy, but this is probably OK once \n";
  heavy A;
  items.push_back(A);

  std::cout<<"Push back of a temporary has a decent chance of being a move \n";
  items.push_back(heavy());

  // Now we have two items in the vector, we'll get a print from each
  std::cout<<"Resizing bigger will force a move in memory\n";
  items.resize(100);

};

