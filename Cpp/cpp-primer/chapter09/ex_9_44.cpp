//
// Created by kaiser on 18-12-5.
//

#include <iostream>
#include <string>

void Fun(std::string &s, const std::string &old_val,
         const std::string &new_val) {
  for (std::string::size_type index{};
       index <= std::size(s) - std::size(old_val);) {
    if (old_val == s.substr(index, std::size(old_val))) {
      s.erase(index, std::size(old_val));
      s.insert(index, new_val);
      index += std::size(new_val);
    } else {
      ++index;
    }
  }
}

int main() {
  std::string s("To drive straight thru is a foolish, tho courageous act.");
  Fun(s, "tho", "thought");
  Fun(s, "thru", "through");
  std::cout << s << '\n';
}
