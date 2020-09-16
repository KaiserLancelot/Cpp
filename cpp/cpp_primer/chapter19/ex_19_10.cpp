//
// Created by kaiser on 19-3-16.
//

#include <iostream>
#include <typeinfo>

class A {
 public:
  virtual ~A() = default;
};
class B : public A {};
class C : public B {};

int main() {
  {
    A* pa{new C};
    // A*
    std::cout << typeid(pa).name() << '\n';
  }

  {
    C cobj;
    A& ra{cobj};
    // A*
    std::cout << typeid(&ra).name() << '\n';
  }

  {
    B* px = new B;
    A& ra{*px};
    // B
    std::cout << typeid(ra).name() << '\n';
  }
}
