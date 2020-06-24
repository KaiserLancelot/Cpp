//
// Created by kaiser on 18-12-23.
//

#include <iostream>
#include <string>

class Fun {
public:
  std::string operator()(bool check, const std::string &s1,
                         const std::string &s2) {
    return check ? s1 : s2;
  }
};

int main() {
  Fun fun;
  std::cout << fun(false, "a", "b") << '\n';
}
