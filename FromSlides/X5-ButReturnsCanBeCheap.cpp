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

// 
heavy* fn(){

  heavy* tmp = new heavy;
  return tmp;
}

heavy fn2(){

  heavy tmp;
  return tmp;
}

int main(){

  std::cout<<"TRY: Returning by reference\n";
  heavy h1 = *fn(); // This is going to make a copy for the assignment though!

  std::cout<<"TRY: Returning by reference\n";
  heavy * h_ptr = fn(); // And this way we have to use a pointer all the time

  std::cout<<"Moving to get a plain entity\n";
  // std::move DOES NOT move anything, but it does "flag it as moveable from"
  heavy h2{std::move(*h_ptr)};
  delete h_ptr;


  std::cout<<"TRY: Returning by value\n";
  heavy h3 = fn2(); // This way will probably just work
  // Return-value optimisation allows the compiler to eliminate the copy
  // NOTE: this is the case even if our copy-constructor has side-effects, one of the
  // few violations of the "as-if" rule
  // Here, the memory set aside for the value f2 returns is simply the h3 variable itself

};

