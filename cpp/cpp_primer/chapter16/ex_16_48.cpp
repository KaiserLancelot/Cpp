//
// Created by kaiser on 19-3-6.
//

#include <iostream>
#include <sstream>
#include <string>

template <typename T>
std::string debug_rep(const T& t) {
  std::ostringstream ret;
  ret << t;
  return ret.str();
}

template <typename T>
std::string debug_rep(T* p) {
  std::ostringstream ret;
  ret << "pointer: " << p;
  if (p) {
    ret << " " << debug_rep(*p);
  } else {
    ret << " null pointer";
  }
  return ret.str();
}

std::string debug_rep(const std::string& s) { return '"' + s + '"'; }

std::string debug_rep(const char* s) { return debug_rep(std::string(s)); }

int main() { std::cout << debug_rep("hi") << '\n'; }
