//
// Created by kaiser on 18-12-5.
//

#include <string>
#include <forward_list>

void Fun(std::forward_list<std::string> &forward_list, const std::string &s1,
         const std::string &s2) {
  auto cur{std::begin(forward_list)}, prv{forward_list.before_begin()};
  for (; cur != std::end(forward_list); prv = cur, ++cur) {
    if (*cur == s1) {
      forward_list.insert_after(cur, s2);
      return;
    }
  }
  forward_list.insert_after(prv, s2);
}