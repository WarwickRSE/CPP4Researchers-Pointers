/* OLD SCHOOL and UP TO DATE */
#include <iostream>
#include <memory>

// Suppose we have a class that depends on some shared resource
// We want to give it access to this
// We don't just want a copy of it though - either it is big, or changes
// Things to consider:
//   does the class have meaning without the resource? (Can a Car exist without a Garage?)
//   is the resource shared by many instances? (Many Cars in one Garage)
//   can you be sure of the lifetime of the resource (Does the Garage exist before and after any Cars?)

// Option 1 - bare pointer. Not a good idea any more
class my_old_class{

  public:
    int  * resource=nullptr;

    // Can initialise how we like with pointers
    my_old_class(int * data){
      resource = data;
    }
    my_old_class(){
      // Can leave data null - i.e. have class without resource
    }
    // Can swap out the resource. What if we are handed nullptr though?
    void change_resource(int * new_res){resource=new_res;}

    void print(){
      // Have to check pointer EVERY time we use it
      // And just because pointer is not null, does not mean data is valid!
      if(resource){
        std::cout<<"my_old_class "<< *(resource)<<'\n';
      }
    }

    ~my_old_class(){
      // Must not free or delete data we don't own
      // If caller "forgets" we'll have a memory leak
    }
};

// Option 2 - a reference. Good if resource has "entire program" lifetime
// Risky if resource might be destroyed
// Cannot have missing resource, or change it out after construction
class my_new_class{

  public:
    int & resource;

    // A reference has to be initialised BEFORE the constructor body, like this:
    my_new_class(int & data):resource(data){};
    // This class remains valid ONLY AS LONG as the passed data object

    void print(){
      // Rely on code which constructed us to make sure resource still exists
      std::cout<<"my_new_class "<<resource<<'\n';
    }

    ~my_new_class(){
      // No question about us freeing the memory
    }
};

// Option 3 - a shared smart pointer. Many classes can share the resource
// It's swappable and nullable
// No risk of memory leak - when last shared_pointer is destroyed, memory is freed for us
// CAVEAT - here we will explicitly be keeping resource alive until the last of my_new_class_shared is destroyed
// That is, we own it, but our ownership is shared with other owners
class my_new_class_shared{

  public:
    std::shared_ptr<int> resource;

    //Initialise like this:
    my_new_class_shared(std::shared_ptr<int> & res):resource(res){};

    void print(){
      // Resource must exist, we have part ownership of it
      // BUT we do have to dereference still
      std::cout<<"my_new_class_shared "<<(*resource)<<'\n';
    }

    ~my_new_class_shared(){
      // Our "stake" is destroyed for us
    }
};

// Option 4 - a weak pointer. Class has no ownership, but
// can check if the pointer is still valid
// But the syntax is more complicated
class my_new_class_weak{

  public:
    std::weak_ptr<int> resource;

    //Initialise like this:
    my_new_class_weak(std::weak_ptr<int> & res):resource(res){};

    void print(){
      // To use resource we have to check
      // We also have to get back an actual data pointer
      // .lock() gets us a shared pointer back
      // If resource has expired, it is null
      // As long as res exists, data stays valid, because we hold shared_ptr to it
      auto res = resource.lock();
      if(res){
        std::cout<<"my_new_class_weak "<<(*res)<<'\n';
      }else{
        std::cout<<"my_new_class_weak expired data\n";
      }
      // Now res goes out of scope and we no longer help keep data alive
    }

    ~my_new_class_weak(){
      // No question of ownership here
    }
};



my_new_class_shared get_a_shared(){
  // Dat might seem to be locally scoped, but is actually a heap allocation
  auto dat = std::make_shared<int>(84);
  auto cls = my_new_class_shared(dat);
  // cls now contains shared_ptr from dat - dat will remain alive as long as cls
  return cls;
};
my_new_class_weak get_a_weak(){
  // Dat might seem to be locally scoped, but is actually a heap allocation
  auto dat = std::make_shared<int>(84);

  // Weak pointer to dat
  std::weak_ptr<int> dat2(dat);
  auto cls = my_new_class_weak(dat2);
  return cls;
  // When we return, dat goes out of scope - but dat2 will KNOW this
};


int main(){

  // Using all the options

  int dat1 = 73, dat2 = 37;
  auto a = my_old_class(&dat1);
  a.print();
  auto b = my_new_class(dat2);
  b.print();

  auto dat3 = std::make_shared<int>(48);
  auto c = my_new_class_shared(dat3);
  c.print();

  std::weak_ptr<int> dat4(dat3); // Non owning pointer from shared pointer
  auto d = my_new_class_weak(dat4);
  d.print();


  // Destroying the data and trying to use it! BAD

  int * dat = new int(43);

  auto a2 = my_old_class(dat);
  auto b2 = my_new_class(*dat);
  a2.print();
  b2.print();
  delete dat;
  a2.print();
  b2.print();

  // Shared case does not allow dangling to happen!
  auto c2 = get_a_shared();
  c2.print();

  // Weak case lets us detect it, all fine if we're careful
  auto d2 = get_a_weak();
  d2.print();

};

