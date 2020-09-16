//
// Created by kaiser on 19-3-6.
//

#include <cstdint>
#include <iostream>
#include <memory>

class A {
 public:
  A(std::int32_t i, double d) : i_{i}, d_{d} {}
  ~A() { std::cout << "~A()\n"; }
  void show() const { std::cout << i_ << ' ' << d_ << '\n'; }

 private:
  std::int32_t i_{};
  double d_{};
};

template <typename T, typename... Args>
std::shared_ptr<T> MakeShared(Args&&... args) {
  return std::shared_ptr<T>{new T(std::forward<Args>(args)...)};
}

int main() {
  auto p{MakeShared<A>(1, 2.3)};
  p->show();
}
