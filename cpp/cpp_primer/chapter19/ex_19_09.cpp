//
// Created by kaiser on 19-3-16.
//

#include <cstdint>
#include <iostream>
#include <string>
#include <typeinfo>

class Base {
public:
    virtual ~Base() = default;
};

class Derived : public Base {
};

int main()
{
    std::int32_t arr[10];
    Derived d;
    Base* p{&d};

    std::cout << typeid(42).name() << '\n';
    std::cout << typeid(arr).name() << '\n';
    std::cout << typeid(std::string).name() << '\n';
    std::cout << typeid(p).name() << '\n';
    std::cout << typeid(*p).name() << '\n';
}
