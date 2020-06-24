//
// Created by kaiser on 18-11-29.
//

#pragma once

#include <iostream>
#include <string>
#include <vector>

class Screen;

class WindowMgr {
public:
  using ScreenIndex = std::vector<Screen>::size_type;
  void clear(ScreenIndex index);

private:
  std::vector<Screen> screens_;
};

class Screen {
  friend void WindowMgr::clear(ScreenIndex index);

public:
  using Pos = std::string::size_type;

  Screen() = default;

  Screen(Pos ht, Pos wd) : height_{ht}, width_{wd}, contents_(ht * wd, ' ') {}

  Screen(Pos ht, Pos wd, char ch)
      : height_{ht}, width_{wd}, contents_(ht * wd, ch) {}

  char get() const { return contents_[cursor_]; }

  char get(Pos r, Pos c) const { return contents_[r * width_ + c]; }

  Screen set(char ch) {
    contents_[cursor_] = ch;
    return *this;
  }

  Screen set(Pos r, Pos c, char ch) {
    contents_[r * width_ + c] = ch;
    return *this;
  }

  Screen move(Pos r, Pos c) {
    cursor_ = r * width_ + c;
    return *this;
  }

  Screen display(std::ostream &os) const {
    do_display(os);
    return *this;
  }

  Screen display(std::ostream &os) {
    do_display(os);
    return *this;
  }

private:
  void do_display(std::ostream &os) const { os << contents_; }

  Pos cursor_{};
  Pos height_{}, width_{};
  std::string contents_;
};

inline void WindowMgr::clear(WindowMgr::ScreenIndex index) {
  auto &s{screens_[index]};
  s.contents_ = std::string(s.width_ * s.height_, ' ');
}
