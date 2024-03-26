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

  // Shared pointers can give us an unmanaged pointer to the data (.get)
  // We can give them ownership of data we own - make sure it is ours to give away (.reset with argument)
  // Now we have two managed objects - the original one with one less reference, and a new one with count 1

  // Create three shared pointers
  std::shared_ptr<watcher> d2 = std::make_shared<watcher>();
  auto d3 = d2;
  auto d1 = d3;

  std::cout<<"Watcher  now has "<<d2.use_count()<<" live references\n";

  watcher * mine = new watcher(5);

  std::cout<<"Created watcher at: "<<mine<<'\n';
  d2.reset(mine); // Hand over this data

  std::cout<<"Our data is at: "<<mine<<" and the shared pointer has data at: "<<d2.get()<<'\n';
  // Our data pointer should now not really be used because d2 might delete the memory - so clear it
  mine = nullptr;

  std::cout<<"d2 has :"<<d2.use_count()<<" and d3 has: "<<d3.use_count()<<std::endl;

  // Now the data we allocated on line 22 and line 28 will be freed
  std::cout<<"Program about to end, expect 2 destructions\n";

};
