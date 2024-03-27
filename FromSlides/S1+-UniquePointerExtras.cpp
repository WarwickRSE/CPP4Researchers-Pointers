/* UP TO DATE */
#include <iostream>
#include <memory>

// This class only exists to tell us if it gets copied, deleted etc
struct watcher{
  watcher(){std::cout<<"watcher created\n";}
  watcher(int i){std::cout<<"watcher created with integer: "<<i<<"\n";}
  watcher(const watcher& other){std::cout<<"watcher copied\n";}
  ~watcher(){std::cout<<"watcher deleted\n";}
};

int main(){

  //Suppose we want a pointer for reasons, but we don't want to risk memory leaks
  //Suppose this is a single object

  //std::unique_ptr is a memory managing pointer that can't be duplicated
  // Can't attach it to data later - use it to create the memory as it owns it
  // however we can steal the pointer from inside, and take chances (.get)
  // or we can take ownership of the data - no longer getting leak protection (.release)
  // and we can destroy the managed data but not the pointer (.reset)
  // or we can give it control of memory we allocated (.reset with argument) - BUT we must be sure it's ours to give away!

  // Create a unique pointer and then take its data
  std::cout<<"Taking the object from d1 - expect no destructions\n";
  auto d1 = std::make_unique<watcher>();
  watcher * tmp = d1.release(); // data is ours now! We must clean up

  std::cout<<"Deleting the object at d2 - expect one destruction\n";
  auto d2 = std::make_unique<watcher>();
  d2.reset();
  std::cout<<"Is d2 valid? "<<(d2?"true":"false")<<'\n';


  std::cout<<"Program ending, expect no destructions\n";
  // We forgot to free tmp! So:
  std::cout<<"Am I leaking memory? "<<(tmp ? "true" : "false")<<'\n';

};
