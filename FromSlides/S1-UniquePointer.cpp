/* UP TO DATE */
#include <iostream>
#include <memory>

// This class only exists to tell us if it gets copied, deleted etc
struct watcher{
  int ii = 0;
  watcher(){std::cout<<"watcher created\n";}
  watcher(int i){std::cout<<"watcher created with integer: "<<i<<"\n";ii=i;}
  watcher(const watcher& other){std::cout<<"watcher copied\n";}
  ~watcher(){std::cout<<"watcher deleted\n";}
};

int main(){

  //Suppose we want a pointer for reasons, but we don't want to risk memory leaks
  //Suppose this is a single object

  //std::unique_ptr is a memory managing pointer that can't be duplicated
  // Can't attach it to data later - use it to create the memory as it owns it

  // Create a unique pointer. Not using auto for demo purposes only!
  std::unique_ptr<watcher> d1 = std::make_unique<watcher>();

  // Create another watcher, with its own ptr
  // Brackets are parameters to construct the object pointed to
  std::unique_ptr<watcher> d2 = std::make_unique<watcher>(5);

  // Have to dereference to use, and need brackets. Shortcut is '->' operator which
  // is equivalent: (* ptr).value <==> ptr->value
  std::cout<<"Watcher values: "<<(*d1).ii<<" and "<<d2->ii<<'\n';

  std::cout<<"Program does programmy things here\n";
  std::cout<<"Program ending, expect two destructions\n";
  // At exit d1 and d2 will be cleaned up and watcher correctly destructed
};
