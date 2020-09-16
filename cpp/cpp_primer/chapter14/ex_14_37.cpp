//
// Created by kaiser on 18-12-23.
//

#include <algorithm>
#include <iostream>
#include <vector>

class Equal {
 public:
  explicit Equal(const std::string& s) : s_{s} {}
  bool operator()(const std::string& s) { return s == s_; }

 private:
  std::string s_;
};

int main() {
  std::vector<std::string> vs{"a", "b", "a"};
  std::replace_if(std::begin(vs), std::end(vs), Equal{"a"}, "c");

  for (const auto& s : vs) {
    std::cout << s << '\n';
  }
}
