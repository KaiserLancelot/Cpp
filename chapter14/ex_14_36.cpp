//
// Created by kaiser on 18-12-23.
//

#include <iostream>
#include <string>
#include <vector>

class ReadString {
 public:
  explicit ReadString(std::istream &is)
      : is_{is} {}
  std::string operator()() {
    std::string ret;
    if (std::getline(is_, ret)) {
      return ret;
    } else {
      return std::string();
    }
  }
 private:
  std::istream &is_;
};

int main() {
  ReadString read_string{std::cin};
  std::vector<std::string> vs;

  auto line{read_string()};
  while (!std::empty(line)) {
    vs.push_back(line);
    line = read_string();
  }

  for (const auto &s:vs) {
    std::cout << s << '\n';
  }
}