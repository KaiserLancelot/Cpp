//
// Created by kaiser on 19-3-16.
//

#include <iostream>
#include <memory>
#include <string>

class Screen {
public:
    using Pos = std::string::size_type;

    Screen() = default;
    Screen(Pos ht, Pos wd, char c)
        : height_{ht}, width_{wd}, contents_(ht * wd, c) {}

    char Get() const { return contents_[cursor_]; }
    char Get(Pos r, Pos c) const { return contents_[r * width_ + c]; }

    Screen& Move(Pos r, Pos c)
    {
        cursor_ = r * width_ + c;
        return *this;
    }

    static const Pos Screen::*Data() { return &Screen::cursor_; }

private:
    Pos cursor_{};
    Pos height_{}, width_{};
    std::string contents_;
};

int main()
{
    Screen screen{10, 20, '*'};
    screen.Move(5, 5);
    std::cout << screen.*Screen::Data() << '\n';
}
