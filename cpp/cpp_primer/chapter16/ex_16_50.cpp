//
// Created by kaiser on 19-3-6.
//

#include <iostream>

template <typename T>
void f(T) {
  std::cout << "f(T)\n";
}

template <typename T>
void f(const T*) {
  std::cout << "f(const T*)\n";
}

template <typename T>
void g(T) {
  std::cout << "foo(T)\n";
}

template <typename T>
void g(T*) {
  std::cout << "foo(T*)\n";
}

int main() {
  int i = 42, *p = &i;
  const int ci = 0, *p2 = &ci;

  g(42);
  g(p);
  g(ci);
  g(p2);

  f(42);
  f(p);
  f(ci);
  f(p2);
}
