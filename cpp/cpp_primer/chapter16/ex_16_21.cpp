//
// Created by kaiser on 19-3-4.
//

#include <cstdint>
#include <iostream>
#include <memory>

class DebugDelete {
 public:
  explicit DebugDelete(std::ostream& os = std::cerr) : os_{os} {}

  template <typename T>
  void operator()(T* p) const {
    os_ << "deleting unique_ptr\n";
    delete p;
  }

 private:
  std::ostream& os_;
};

int main() {
  std::unique_ptr<std::int32_t, DebugDelete> p{new std::int32_t, DebugDelete{}};
}
