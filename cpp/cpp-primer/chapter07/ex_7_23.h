//
// Created by kaiser on 18-11-29.
//

#pragma once

#include <string>

class Screen {
 public:
  using Pos = std::string::size_type;

  Screen() = default;

  Screen(Pos ht, Pos wd, char c)
      : height_{ht}, width_{wd}, contents_(ht * wd, c) {}

  char get() const { return contents_[cursor_]; }

  char get(Pos r, Pos c) const { return contents_[r * width_ + c]; }

  Screen &move(Pos r, Pos c) {
    (void)height_;
    cursor_ = r * width_ + c;
    return *this;
  }

 private:
  Pos cursor_{};
  Pos height_{}, width_{};
  std::string contents_;
};
