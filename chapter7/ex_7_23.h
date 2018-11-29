//
// Created by kaiser on 18-11-29.
//

#ifndef CPP_PRIMER_EX_7_23_H
#define CPP_PRIMER_EX_7_23_H

#include <string>

class Screen {
public:
    using Pos=std::string::size_type;

    Screen() = default;

    Screen(Pos ht, Pos wd, char c) : height_{ht}, width_{wd},
                                     contents_(ht * wd, c) {}
    char Get() const {
        return contents_[cursor_];
    }

    char Get(Pos r, Pos c) const {
        return contents_[r * width_ + c];
    }

    Screen &Move(Pos r, Pos c) {
        cursor_ = r * width_ + c;
        return *this;
    }

private:
    Pos cursor_{};
    Pos height_{}, width_{};
    std::string contents_;
};

#endif //CPP_PRIMER_EX_7_23_H
