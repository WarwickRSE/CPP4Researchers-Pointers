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

  // The last smart pointer is the most complicated
  // It is non-owning, and has to be associated with a shared_pointer
  // and it is then AWARE of whether the data still exists
  // It is the most complicated to use, because we have to do checks
  // but when we need it, it is very handy

  // Create a shared pointer
  std::shared_ptr<watcher> d1 = std::make_shared<watcher>();
  // Now create a weak pointer to this
  std::weak_ptr<watcher> w1(d1);

  // Weak pointer did not increase reference count
  std::cout<<"Shared pointer knows of "<<d1.use_count()<<" pointers to this data\n";

  // To _use_ the weak pointer we have to check the data is valid, and then
  // make sure it can't be destroyed beneath us (e.g. in threaded code)

  // Can check for expiry BUT note that can't then use it - it might expire
  // between the check and the use
  std::cout<<"Weak pointer expired? "<<(w1.expired()?"true":"false")<<'\n';

  // Instead there is a lock function which returns a shared_ptr, OR nullptr if
  // expired
  {
    auto ptr = w1.lock();
    std::cout<<"Now shared pointer knows of "<<d1.use_count()<<" pointers to this data\n";
    if(ptr){
      //In here it is safe to use the data!
    }else{
      std::cout<<"Weak pointer now expired\n";
    }
    // When this block ends our ptr is destroyed, reference count goes back down
  }
  std::cout<<"And now shared pointer knows of "<<d1.use_count()<<" pointers to this data\n";

  std::cout<<"Program about to end, expect 1 destruction\n";

};
