//
// Created by kaiser on 19-3-16.
//

#include <iostream>
#include <typeinfo>

class A {
public:
    virtual ~A() = default;
};
class B : public A {
};
class C : public B {
};

int main()
{
    C c;
    A& pa{c};

    try {
        C& rc{dynamic_cast<C&>(pa)};
    }
    catch (const std::bad_cast& err) {
        std::cerr << err.what() << '\n';
    }
}
