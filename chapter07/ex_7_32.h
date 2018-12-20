//
// Created by kaiser on 18-11-29.
//

#ifndef CPP_PRIMER_EX_7_32_H
#define CPP_PRIMER_EX_7_32_H

#include <iostream>
#include <string>
#include <vector>

class Screen;

class WindowMgr {
 public:
  using ScreenIndex=std::vector<Screen>::size_type;
  void clear(ScreenIndex index);
 private:
  std::vector<Screen> screens;
};

class Screen {
  friend void WindowMgr::clear(ScreenIndex index);
 public:
  using Pos=std::string::size_type;

  Screen() = default;

  Screen(Pos ht, Pos wd) : height_{ht}, width_{wd},
                           contents_(ht * wd, ' ') {}

  Screen(Pos ht, Pos wd, char ch) : height_{ht}, width_{wd},
                                    contents_(ht * wd, ch) {}
  char Get() const {
    return contents_[cursor_];
  }

  char Get(Pos r, Pos c) const {
    return contents_[r * width_ + c];
  }

  Screen Set(char ch) {
    contents_[cursor_] = ch;
    return *this;
  }

  Screen Set(Pos r, Pos c, char ch) {
    contents_[r * width_ + c] = ch;
    return *this;
  }

  Screen Move(Pos r, Pos c) {
    cursor_ = r * width_ + c;
    return *this;
  }

  const Screen Display(std::ostream &os) const {
    DoDisplay(os);
    return *this;
  }

  Screen Display(std::ostream &os) {
    DoDisplay(os);
    return *this;
  }

 private:
  void DoDisplay(std::ostream &os) const {
    os << contents_;
  }

  Pos cursor_{};
  Pos height_{}, width_{};
  std::string contents_;
};

inline void WindowMgr::clear(WindowMgr::ScreenIndex index) {
  auto &s{screens[index]};
  s.contents_ = std::string(s.width_ * s.height_, ' ');
}

#endif //CPP_PRIMER_EX_7_32_H
