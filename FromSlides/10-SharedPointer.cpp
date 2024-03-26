/* UP TO DATE */
#include <iostream>
#include <memory>

// This class only exists to tell us if it gets copied, deleted etc
struct watcher{
  int i;
  watcher(){std::cout<<"watcher created\n";}
  watcher(int ii){std::cout<<"watcher created with integer: "<<ii<<"\n";i=ii;}
  void say(){std::cout<<"watcher says "<<i<<std::endl;}
  watcher(const watcher& other){std::cout<<"watcher copied\n";}
  ~watcher(){std::cout<<"watcher deleted\n";}
};

int main(){

  // Suppose we have some data that many things might need a pointer to
  // But we still want to protect from leaks, so when the last pointer goes
  // the data should be freed

  //std::shared_ptr is a memory managing pointer that can be duplicated
  // Can't attach it to data later - use it to create the memory as it owns it
  // When the last shared_ptr is destroyed, the data is destroyed too

  // Create a shared pointer
  std::shared_ptr<watcher> d1 = std::make_shared<watcher>();

  // Another object, with its own shared ptr
  // Brackets are parameters to construct the object pointed to
  std::shared_ptr<watcher> d2 = std::make_shared<watcher>(5);

  //Braces open a scope block
  {
    // Get another shared pointer to existing data by copying
    auto d3 = d2; // d3 points to same as d2
    d3->say(); // This -> operator is equiv. to (*d3).say();
  }
  std::cout<<"Finished with d3 now, no watchers destroyed\n";
  std::cout<<"d2 still OK\n";
  d2->say();

  std::cout<<"Program about to end, expect 2 destructions\n";

};
