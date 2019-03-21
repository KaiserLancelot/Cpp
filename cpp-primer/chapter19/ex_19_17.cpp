//
// Created by kaiser on 19-3-17.
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

  Screen &Move(Pos r, Pos c) {
    cursor_ = r * width_ + c;
    return *this;
  }

  static const Pos Screen::*Data() { return &Screen::cursor_; }

 private:
  Pos cursor_{};
  Pos height_{}, width_{};
  std::string contents_;
};

using Fp1 = char (Screen::*)(Screen::Pos, Screen::Pos) const;
using Fp2 = char (Screen::*)() const;
using Fp3 = Screen &(Screen::*)(Screen::Pos, Screen::Pos) const;

int main() {}