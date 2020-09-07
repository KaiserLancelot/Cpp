//
// Created by kaiser on 18-12-20.
//

#include <cstdint>
#include <iostream>

class Numbered {
public:
    Numbered()
    {
        static std::int32_t id{};
        mysn_ = id++;
    }
    std::int32_t mysn_;
};

void f(Numbered s) { std::cout << s.mysn_ << '\n'; }

int main()
{
    Numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);
}
