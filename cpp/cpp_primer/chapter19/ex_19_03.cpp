//
// Created by kaiser on 19-3-16.
//

#include <iostream>

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
    {
        A* pa = new C;
        if (B* pb = dynamic_cast<B*>(pa); !pb) {
            std::cerr << "error 1\n";
        }
    }
    {
        B* pb = new B;
        if (C* pc = dynamic_cast<C*>(pb); !pc) {
            std::cerr << "error 2\n";
        }
    }
}
